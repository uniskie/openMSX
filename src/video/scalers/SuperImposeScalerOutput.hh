#ifndef SUPERIMPOSESCALEROUTPUT_HH
#define SUPERIMPOSESCALEROUTPUT_HH

#include "ScalerOutput.hh"
#include "PixelOperations.hh"
#include <span>

namespace openmsx {

class RawFrame;

template<std::unsigned_integral Pixel>
class SuperImposeScalerOutput final : public ScalerOutput<Pixel>
{
public:
	SuperImposeScalerOutput(ScalerOutput<Pixel>& output,
	                        const RawFrame& superImpose_,
	                        const PixelOperations<Pixel>& pixelOps_);

	[[nodiscard]] unsigned getWidth()  const override;
	[[nodiscard]] unsigned getHeight() const override;
	void frameStart() override {}
	void frameStop() override {}
	[[nodiscard]] std::span<Pixel> acquireLine(unsigned y) override;
	void releaseLine(unsigned y, std::span<Pixel> buf)  override;
	void fillLine   (unsigned y, Pixel color) override;

private:
	[[nodiscard]] std::span<const Pixel> getSrcLine(unsigned y, std::span<Pixel> buf);

private:
	ScalerOutput<Pixel>& output;
	const RawFrame& superImpose;
	const PixelOperations<Pixel> pixelOps;
};

} // namespace openmsx

#endif
