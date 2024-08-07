#ifndef ROMGENERIC16KB_HH
#define ROMGENERIC16KB_HH

#include "RomBlocks.hh"

namespace openmsx {

class RomGeneric16kB final : public Rom16kBBlocks
{
public:
	RomGeneric16kB(const DeviceConfig& config, Rom&& rom);

	void reset(EmuTime::param time) override;
	void writeMem(word address, byte value, EmuTime::param time) override;
	[[nodiscard]] byte* getWriteCacheLine(word address) override;
};

} // namespace openmsx

#endif
