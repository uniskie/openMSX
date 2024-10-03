#ifndef PANASONICMEMORY_HH
#define PANASONICMEMORY_HH

#include "Rom.hh"
#include "openmsx.hh"
#include <optional>

namespace openmsx {

class MSXMotherBoard;
class MSXCPU;
class Ram;

class PanasonicMemory
{
public:
	explicit PanasonicMemory(MSXMotherBoard& motherBoard);

	/**
	 * Pass reference of the actual Ram block for use in DRAM mode and RAM
	 * access via the ROM mapper. Note that this is always unchecked Ram!
	 */
	void registerRam(Ram& ram);
	[[nodiscard]] std::span<const byte, 0x2000> getRomBlock(unsigned block) const;
	[[nodiscard]] std::span<const byte> getRomRange(unsigned first, unsigned last) const;
	/**
	 * Note that this is always unchecked RAM! There is no UMR detection
	 * when accessing Ram in DRAM mode or via the ROM mapper!
	 */
	[[nodiscard]] byte* getRamBlock(unsigned block);
	[[nodiscard]] unsigned getRamSize() const { return ramSize; }
	void setDRAM(bool dram);
	[[nodiscard]] bool isWritable(unsigned address) const;

private:
	MSXCPU& msxcpu;

	const std::optional<Rom> rom; // can be nullptr
	byte* ram = nullptr;
	unsigned ramSize = 0;
	bool dram = false;
};

} // namespace openmsx

#endif
