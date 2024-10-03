#include "RomSuperLodeRunner.hh"
#include "serialize.hh"
#include <cassert>

namespace openmsx {

RomSuperLodeRunner::RomSuperLodeRunner(
		const DeviceConfig& config, Rom&& rom_)
	: Rom16kBBlocks(config, std::move(rom_))
{
	reset(EmuTime::dummy());
}

void RomSuperLodeRunner::reset(EmuTime::param /*time*/)
{
	setUnmapped(0);
	setUnmapped(1);
	setRom(2, 0);
	setUnmapped(3);
}

void RomSuperLodeRunner::globalWrite(word address, byte value, EmuTime::param /*time*/)
{
	assert(address == 0);
	(void)address;
	setRom(2, value);
}

REGISTER_MSXDEVICE(RomSuperLodeRunner, "RomSuperLodeRunner");

} // namespace openmsx
