#include "LDDummyRenderer.hh"

namespace openmsx {

void LDDummyRenderer::frameStart(EmuTime::param /*time*/)
{
}

void LDDummyRenderer::frameEnd()
{
}

void LDDummyRenderer::drawBlank(int /*r*/, int /*g*/, int /*b*/)
{
}

RawFrame* LDDummyRenderer::getRawFrame()
{
	return nullptr;
}

} // namespace openmsx
