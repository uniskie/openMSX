#ifndef FRAMESOURCE_HH
#define FRAMESOURCE_HH

#include "aligned.hh"
#include "narrow.hh"
#include "xrange.hh"

#include <algorithm>
#include <array>
#include <bit>
#include <cassert>
#include <cstdint>
#include <span>

namespace openmsx {

/** Interface for getting lines from a video frame.
  */
class FrameSource
{
public:
	using Pixel = uint32_t;

	/** What role does this frame play in interlacing?
	  */
	enum class FieldType {
		/** Interlacing is off for this frame.
		  */
		NONINTERLACED,
		/** Interlacing is on and this is an even frame.
		  */
		EVEN,
		/** Interlacing is on and this is an odd frame.
		  */
		ODD,
	};

	/** (Re)initialize an existing FrameSource. This method sets the
	  * Fieldtype and flushes the 'getLinePtr' buffers.
	  */
	void init(FieldType fieldType_) { fieldType = fieldType_; }

	/** Gets the role this frame plays in interlacing.
	  */
	[[nodiscard]] FieldType getField() const {
		return fieldType;
	}

	/** Gets the number of lines in this frame.
	  */
	[[nodiscard]] unsigned getHeight() const {
		return height;
	}

	/** Gets the number of display pixels on the given line.
	  * @return line width (=1 for a vertical border line)
	  */
	[[nodiscard]] virtual unsigned getLineWidth(unsigned line) const = 0;

	/** Get the width of (all) lines in this frame.
	 * This only makes sense when all lines have the same width, so this
	 * methods asserts that all lines actually have the same width. This
	 * is for example not always the case for MSX frames, but it is for
	 * video frames (for superimpose).
	 */
	[[nodiscard]] unsigned getWidth() const {
		assert(height > 0);
		unsigned result = getLineWidth(0);
		for (auto line : xrange(1u, height)) {
			assert(result == getLineWidth(line)); (void)line;
		}
		return result;
	}

	/** Get the (single) color of the given line.
	  * Typically this will be used to get the color of a vertical border
	  * line. But it's fine to call this on non-border lines as well, in
	  * that case the color of the first pixel of the line is returned.
	  */
	[[nodiscard]] inline Pixel getLineColor(unsigned line) const {
		ALIGNAS_SSE std::array<Pixel, 1280> buf; // large enough for widest line
		return getUnscaledLine(line, buf)[0];
	}

	/** Gets a pointer to the pixels of the given line number.
	  * The line returned is guaranteed to have the given width. If the
	  * original line had a different width the result will be computed in
	  * the provided work buffer. So that buffer should be big enough to
	  * hold the scaled line. This also means the lifetime of the result
	  * is tied to the lifetime of that work buffer. In any case the return
	  * value of this function will point to the line data (some internal
	  * buffer or the work buffer).
	  */
	[[nodiscard]] inline std::span<const Pixel> getLine(int line, std::span<Pixel> buf) const
	{
		line = std::clamp(line, 0, narrow<int>(getHeight() - 1));
		auto unscaledLine = getUnscaledLine(line, buf);
		if (unscaledLine.size() == buf.size()) {
			// Already the correct width.
			return unscaledLine;
		} else {
			// slow path, non-inlined
			// internalData might be equal to buf
			scaleLine(unscaledLine, buf);
			return buf;
		}
	}

	/** Get a specific line, with the 'native' line-width.
	  * @param line The line number for the requested line.
	  * @param helpBuf Buffer space that can _optionally_ be used by the
	  *                implementation.
	  * @return Returns a span of the requested line. This span may or may
	            not use the helper input buffer.
	  */
	[[nodiscard]] virtual std::span<const Pixel> getUnscaledLine(
		unsigned line, std::span<Pixel> helpBuf) const = 0;

	/** Get a pointer to a given line in this frame, the frame is scaled
	  * to 320x240 pixels. The difference between this method and
	  * getLinePtr() is that this method also does vertical scaling.
	  * This is used for video recording.
	  */
	[[nodiscard]] std::span<const Pixel, 320> getLinePtr320_240(unsigned line, std::span<Pixel, 320> buf) const;

	/** Get a pointer to a given line in this frame, the frame is scaled
	  * to 640x480 pixels. Same as getLinePtr320_240, but then for a
	  * higher resolution output.
	  */
	[[nodiscard]] std::span<const Pixel, 640> getLinePtr640_480(unsigned line, std::span<Pixel, 640> buf) const;

	/** Get a pointer to a given line in this frame, the frame is scaled
	  * to 960x720 pixels. Same as getLinePtr320_240, but then for a
	  * higher resolution output.
	  */
	[[nodiscard]] std::span<const Pixel, 960> getLinePtr960_720(unsigned line, std::span<Pixel, 960> buf) const;

protected:
	FrameSource() = default;
	~FrameSource() = default;

	void setHeight(unsigned height_) { height = height_; }

	/** Returns true when two consecutive rows are also consecutive in
	  * memory.
	  */
	[[nodiscard]] virtual bool hasContiguousStorage() const {
		return false;
	}

	void scaleLine(std::span<const Pixel> in, std::span<Pixel> out) const;

private:
	/** Number of lines in this frame.
	  */
	unsigned height;

	FieldType fieldType;
};

} // namespace openmsx

#endif // FRAMESOURCE_HH
