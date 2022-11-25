#include "OSDRectangle.hh"
#include "SDLImage.hh"
#include "CommandException.hh"
#include "FileContext.hh"
#include "FileOperations.hh"
#include "TclObject.hh"
#include "stl.hh"
#include "components.hh"
#include <cassert>
#include <cmath>
#include <cstdint>
#include <memory>
#if COMPONENT_GL
#include "GLImage.hh"
#endif

using namespace gl;

namespace openmsx {

OSDRectangle::OSDRectangle(Display& display_, const TclObject& name_)
	: OSDImageBasedWidget(display_, name_)
{
}

void OSDRectangle::setProperty(
	Interpreter& interp, std::string_view propName, const TclObject& value)
{
	if (propName == "-w") {
		float w = value.getFloat(interp);
		if (size[0] != w) {
			size[0] = w;
			invalidateRecursive();
		}
	} else if (propName == "-h") {
		float h = value.getFloat(interp);
		if (size[1] != h) {
			size[1] = h;
			invalidateRecursive();
		}
	} else if (propName == "-relw") {
		float relw = value.getFloat(interp);
		if (relSize[0] != relw) {
			relSize[0] = relw;
			invalidateRecursive();
		}
	} else if (propName == "-relh") {
		float relh = value.getFloat(interp);
		if (relSize[1] != relh) {
			relSize[1] = relh;
			invalidateRecursive();
		}
	} else if (propName == "-scale") {
		float scale2 = value.getFloat(interp);
		if (scale != scale2) {
			scale = scale2;
			invalidateRecursive();
		}
	} else if (propName == "-image") {
		std::string_view val = value.getString();
		if (imageName != val) {
			if (!val.empty()) {
				if (auto file = systemFileContext().resolve(val);
				    !FileOperations::isRegularFile(file)) {
					throw CommandException("Not a valid image file: ", val);
				}
			}
			imageName = val;
			invalidateRecursive();
		}
	} else if (propName == "-bordersize") {
		float newSize = value.getFloat(interp);
		if (borderSize != newSize) {
			borderSize = newSize;
			invalidateLocal();
		}
	} else if (propName == "-relbordersize") {
		float newSize = value.getFloat(interp);
		if (relBorderSize != newSize) {
			relBorderSize = newSize;
			invalidateLocal();
		}
	} else if (propName == "-borderrgba") {
		uint32_t newRGBA = value.getInt(interp);
		if (borderRGBA != newRGBA) {
			borderRGBA = newRGBA;
			invalidateLocal();
		}
	} else {
		OSDImageBasedWidget::setProperty(interp, propName, value);
	}
}

void OSDRectangle::getProperty(std::string_view propName, TclObject& result) const
{
	if (propName == "-w") {
		result = size[0];
	} else if (propName == "-h") {
		result = size[1];
	} else if (propName == "-relw") {
		result = relSize[0];
	} else if (propName == "-relh") {
		result = relSize[1];
	} else if (propName == "-scale") {
		result = scale;
	} else if (propName == "-image") {
		result = imageName;
	} else if (propName == "-bordersize") {
		result = borderSize;
	} else if (propName == "-relbordersize") {
		result = relBorderSize;
	} else if (propName == "-borderrgba") {
		result = borderRGBA;
	} else {
		OSDImageBasedWidget::getProperty(propName, result);
	}
}

std::string_view OSDRectangle::getType() const
{
	return "rectangle";
}

bool OSDRectangle::takeImageDimensions() const
{
	return (size == vec2()) && (relSize == vec2());
}

vec2 OSDRectangle::getSize(const OutputSurface& output) const
{
	if (!imageName.empty() && image && takeImageDimensions()) {
		return vec2(image->getSize());
	} else {
		return (size * float(getScaleFactor(output)) * scale) +
		       (getParent()->getSize(output) * relSize);
	}
	//std::cout << "rectangle getWH " << getName() << "  " << width << " x " << height << '\n';
}

uint8_t OSDRectangle::getFadedAlpha() const
{
	return uint8_t(255 * getRecursiveFadeValue());
}

template<typename IMAGE> std::unique_ptr<BaseImage> OSDRectangle::create(
	OutputSurface& output)
{
	if (imageName.empty()) {
		bool constAlpha = hasConstantAlpha();
		if (constAlpha && ((getRGBA(0) & 0xff) == 0) &&
		    (((borderRGBA & 0xFF) == 0) || (borderSize == 0.0f))) {
			// optimization: Sometimes it's useful to have a
			//   rectangle that will never be drawn, it only exists
			//   as a parent for sub-widgets. For those cases
			//   creating an IMAGE only wastes memory. So postpone
			//   creating it till alpha changes.
			return nullptr;
		}
		vec2 sz = getSize(output);
		auto factor = narrow<float>(getScaleFactor(output)) * scale;
		auto bs = narrow_cast<int>(lrintf(factor * borderSize + sz[0] * relBorderSize));
		assert(bs >= 0);
		return std::make_unique<IMAGE>(output, round(sz), getRGBA4(), bs, borderRGBA);
	} else {
		auto file = systemFileContext().resolve(imageName);
		if (takeImageDimensions()) {
			auto factor = narrow<float>(getScaleFactor(output)) * scale;
			return std::make_unique<IMAGE>(output, file, factor);
		} else {
			ivec2 iSize = round(getSize(output));
			return std::make_unique<IMAGE>(output, file, iSize);
		}
	}
}

std::unique_ptr<BaseImage> OSDRectangle::createSDL(OutputSurface& output)
{
	return create<SDLImage>(output);
}

std::unique_ptr<BaseImage> OSDRectangle::createGL(OutputSurface& output)
{
#if COMPONENT_GL
	return create<GLImage>(output);
#else
	(void)&output;
	return nullptr;
#endif
}

} // namespace openmsx
