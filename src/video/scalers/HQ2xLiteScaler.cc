/*
 * Lightweight version of the hq2x scaler (http://www.hiend3d.com/hq2x.html)
 *
 * The difference between this version and the full version of hq2x is the
 * calculation of the distance between two colors. Here it's simplified to
 * just  color1 == color2
 * Because of this simplification a lot of the interpolation code can also
 * be simplified.
 * For low color images the result is very close to the full hq2x image but
 * it is calculated _a_lot_ faster.
 */

#include "HQ2xLiteScaler.hh"
#include "HQCommon.hh"
#include "LineScalers.hh"
#include "unreachable.hh"
#include "build-info.hh"
#include <cstdint>

namespace openmsx {

template<std::unsigned_integral Pixel> struct HQLite_1x1on2x2
{
	void operator()(std::span<const Pixel> in0, std::span<const Pixel> in1, std::span<const Pixel> in2,
	                std::span<Pixel> out0, std::span<Pixel> out1,
	                std::span<uint16_t> edgeBuf, EdgeHQLite edgeOp) __restrict;
};

template<std::unsigned_integral Pixel> struct HQLite_1x1on1x2
{
	void operator()(std::span<const Pixel> in0, std::span<const Pixel> in1, std::span<const Pixel> in2,
	                std::span<Pixel> out0, std::span<Pixel> out1,
	                std::span<uint16_t> edgeBuf, EdgeHQLite edgeOp) __restrict;
};

template<std::unsigned_integral Pixel>
void HQLite_1x1on2x2<Pixel>::operator()(
	std::span<const Pixel> in0, std::span<const Pixel> in1, std::span<const Pixel> in2,
	std::span<Pixel> out0, std::span<Pixel> out1,
	std::span<uint16_t> edgeBuf,
	EdgeHQLite /*edgeOp*/) __restrict
{
	auto srcWidth = edgeBuf.size();
	assert(in0.size() == srcWidth);
	assert(in1.size() == srcWidth);
	assert(in2.size() == srcWidth);
	assert(out0.size() == 2 * srcWidth);
	assert(out1.size() == 2 * srcWidth);

	auto c2 = readPixel(in0[0]);
	auto c5 = readPixel(in1[0]); auto c6 = c5;
	auto c8 = readPixel(in2[0]); auto c9 = c8;

	unsigned pattern = 0;
	if (c5 != c8) pattern |= 3 <<  6;
	if (c5 != c2) pattern |= 3 <<  9;

	for (auto x : xrange(srcWidth)) {
		auto c4 = c5;
		c5 = c6;
		c8 = c9;
		if (x != srcWidth - 1) {
			c6 = readPixel(in1[x + 1]);
			c9 = readPixel(in2[x + 1]);
		}

		pattern = (pattern >> 6) & 0x001F; // left overlap
		// overlaps with left
		//if (c8 != c4) pattern |= 1 <<  0; // B - l: c5-c9 6
		//if (c5 != c7) pattern |= 1 <<  1; // B - l: c6-c8 7
		//if (c5 != c4) pattern |= 1 <<  2; //     l: c5-c6 8
		// overlaps with top and left
		//if (c5 != c1) pattern |= 1 <<  3; //     l: c2-c6 9,  t: c4-c8 0
		//if (c4 != c2) pattern |= 1 <<  4; //     l: c5-c3 10, t: c5-c7 1
		// non-overlapping pixels
		if (c5 != c8) pattern |= 1 <<  5; // B
		if (c5 != c9) pattern |= 1 <<  6; // BR
		if (c6 != c8) pattern |= 1 <<  7; // BR
		if (c5 != c6) pattern |= 1 <<  8; // R
		// overlaps with top
		//if (c2 != c6) pattern |= 1 <<  9; // R - t: c5-c9 6
		//if (c5 != c3) pattern |= 1 << 10; // R - t: c6-c8 7
		//if (c5 != c2) pattern |= 1 << 11; //     t: c5-c8 5
		pattern |= ((edgeBuf[x] &  (1 << 5)            ) << 6) |
		           ((edgeBuf[x] & ((1 << 6) | (1 << 7))) << 3);
		edgeBuf[x] = narrow_cast<uint16_t>(pattern);

		unsigned pixel0, pixel1, pixel2, pixel3;

#include "HQ2xLiteScaler-1x1to2x2.nn"

		out0[2 * x + 0] = writePixel<Pixel>(pixel0);
		out0[2 * x + 1] = writePixel<Pixel>(pixel1);
		out1[2 * x + 0] = writePixel<Pixel>(pixel2);
		out1[2 * x + 1] = writePixel<Pixel>(pixel3);
	}
}

template<std::unsigned_integral Pixel>
void HQLite_1x1on1x2<Pixel>::operator()(
	std::span<const Pixel> in0, std::span<const Pixel> in1, std::span<const Pixel> in2,
	std::span<Pixel> out0, std::span<Pixel> out1,
	std::span<uint16_t> edgeBuf,
	EdgeHQLite /*edgeOp*/) __restrict
{
	//  +---+---+---+
	//  | 1 | 2 | 3 |
	//  +---+---+---+
	//  | 4 | 5 | 6 |
	//  +---+---+---+
	//  | 7 | 8 | 9 |
	//  +---+---+---+
	auto srcWidth = edgeBuf.size();
	assert(in0.size() == srcWidth);
	assert(in1.size() == srcWidth);
	assert(in2.size() == srcWidth);
	assert(out0.size() == srcWidth);
	assert(out1.size() == srcWidth);

	auto c2 = readPixel(in0[0]);
	auto c5 = readPixel(in1[0]); auto c6 = c5;
	auto c8 = readPixel(in2[0]); auto c9 = c8;

	unsigned pattern = 0;
	if (c5 != c8) pattern |= 3 <<  6;
	if (c5 != c2) pattern |= 3 <<  9;

	for (auto x : xrange(srcWidth)) {
		auto c4 = c5;
		c5 = c6;
		c8 = c9;
		if (x != srcWidth - 1) {
			c6 = readPixel(in1[x + 1]);
			c9 = readPixel(in2[x + 1]);
		}

		pattern = (pattern >> 6) & 0x001F; // left overlap
		// overlaps with left
		//if (c8 != c4) pattern |= 1 <<  0; // B - l: c5-c9 6
		//if (c5 != c7) pattern |= 1 <<  1; // B - l: c6-c8 7
		//if (c5 != c4) pattern |= 1 <<  2; //     l: c5-c6 8
		// overlaps with top and left
		//if (c5 != c1) pattern |= 1 <<  3; //     l: c2-c6 9,  t: c4-c8 0
		//if (c4 != c2) pattern |= 1 <<  4; //     l: c5-c3 10, t: c5-c7 1
		// non-overlapping pixels
		if (c5 != c8) pattern |= 1 <<  5; // B
		if (c5 != c9) pattern |= 1 <<  6; // BR
		if (c6 != c8) pattern |= 1 <<  7; // BR
		if (c5 != c6) pattern |= 1 <<  8; // R
		// overlaps with top
		//if (c2 != c6) pattern |= 1 <<  9; // R - t: c5-c9 6
		//if (c5 != c3) pattern |= 1 << 10; // R - t: c6-c8 7
		//if (c5 != c2) pattern |= 1 << 11; //     t: c5-c8 5
		pattern |= ((edgeBuf[x] &  (1 << 5)            ) << 6) |
		           ((edgeBuf[x] & ((1 << 6) | (1 << 7))) << 3);
		edgeBuf[x] = narrow_cast<uint16_t>(pattern);

		unsigned pixel0, pixel1;

#include "HQ2xLiteScaler-1x1to1x2.nn"

		out0[x] = writePixel<Pixel>(pixel0);
		out1[x] = writePixel<Pixel>(pixel1);
	}
}



template<std::unsigned_integral Pixel>
HQ2xLiteScaler<Pixel>::HQ2xLiteScaler(const PixelOperations<Pixel>& pixelOps_)
	: Scaler2<Pixel>(pixelOps_)
	, pixelOps(pixelOps_)
{
}

template<std::unsigned_integral Pixel>
void HQ2xLiteScaler<Pixel>::scale1x1to3x2(FrameSource& src,
	unsigned srcStartY, unsigned srcEndY, unsigned srcWidth,
	ScalerOutput<Pixel>& dst, unsigned dstStartY, unsigned dstEndY)
{
	PolyScale<Pixel, Scale_2on3<Pixel>> postScale(pixelOps);
	EdgeHQLite edgeOp;
	doHQScale2<Pixel>(HQLite_1x1on2x2<Pixel>(), edgeOp, postScale,
	                  src, srcStartY, srcEndY, srcWidth,
	                  dst, dstStartY, dstEndY);
}

template<std::unsigned_integral Pixel>
void HQ2xLiteScaler<Pixel>::scale1x1to2x2(FrameSource& src,
	unsigned srcStartY, unsigned srcEndY, unsigned srcWidth,
	ScalerOutput<Pixel>& dst, unsigned dstStartY, unsigned dstEndY)
{
	PolyScale<Pixel, Scale_1on1<Pixel>> postScale;
	EdgeHQLite edgeOp;
	doHQScale2<Pixel>(HQLite_1x1on2x2<Pixel>(), edgeOp, postScale,
	                  src, srcStartY, srcEndY, srcWidth,
	                  dst, dstStartY, dstEndY);
}

template<std::unsigned_integral Pixel>
void HQ2xLiteScaler<Pixel>::scale2x1to3x2(FrameSource& src,
	unsigned srcStartY, unsigned srcEndY, unsigned srcWidth,
	ScalerOutput<Pixel>& dst, unsigned dstStartY, unsigned dstEndY)
{
	PolyScale<Pixel, Scale_4on3<Pixel>> postScale(pixelOps);
	EdgeHQLite edgeOp;
	doHQScale2<Pixel>(HQLite_1x1on2x2<Pixel>(), edgeOp, postScale,
	                  src, srcStartY, srcEndY, srcWidth,
	                  dst, dstStartY, dstEndY);
}

template<std::unsigned_integral Pixel>
void HQ2xLiteScaler<Pixel>::scale1x1to1x2(FrameSource& src,
	unsigned srcStartY, unsigned srcEndY, unsigned srcWidth,
	ScalerOutput<Pixel>& dst, unsigned dstStartY, unsigned dstEndY)
{
	PolyScale<Pixel, Scale_1on1<Pixel>> postScale;
	EdgeHQLite edgeOp;
	doHQScale2<Pixel>(HQLite_1x1on1x2<Pixel>(), edgeOp, postScale,
	                  src, srcStartY, srcEndY, srcWidth,
	                  dst, dstStartY, dstEndY);
}

template<std::unsigned_integral Pixel>
void HQ2xLiteScaler<Pixel>::scale4x1to3x2(FrameSource& src,
	unsigned srcStartY, unsigned srcEndY, unsigned srcWidth,
	ScalerOutput<Pixel>& dst, unsigned dstStartY, unsigned dstEndY)
{
	PolyScale<Pixel, Scale_4on3<Pixel>> postScale(pixelOps);
	EdgeHQLite edgeOp;
	doHQScale2<Pixel>(HQLite_1x1on1x2<Pixel>(), edgeOp, postScale,
	                  src, srcStartY, srcEndY, srcWidth,
	                  dst, dstStartY, dstEndY);
}

template<std::unsigned_integral Pixel>
void HQ2xLiteScaler<Pixel>::scale2x1to1x2(FrameSource& src,
	unsigned srcStartY, unsigned srcEndY, unsigned srcWidth,
	ScalerOutput<Pixel>& dst, unsigned dstStartY, unsigned dstEndY)
{
	PolyScale<Pixel, Scale_2on1<Pixel>> postScale(pixelOps);
	EdgeHQLite edgeOp;
	doHQScale2<Pixel>(HQLite_1x1on1x2<Pixel>(), edgeOp, postScale,
	                  src, srcStartY, srcEndY, srcWidth,
	                  dst, dstStartY, dstEndY);
}

// Force template instantiation.
#if HAVE_16BPP
template class HQ2xLiteScaler<uint16_t>;
#endif
#if HAVE_32BPP
template class HQ2xLiteScaler<uint32_t>;
#endif

} // namespace openmsx
