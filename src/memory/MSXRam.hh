// $Id$

#ifndef MSXSIMPLE64KB_HH
#define MSXSIMPLE64KB_HH

#include "MSXDevice.hh"
#include <memory>

namespace openmsx {

class Ram;

class MSXRam : public MSXDevice
{
public:
	MSXRam(const XMLElement& config, const EmuTime& time);
	virtual ~MSXRam();

	virtual void powerUp(const EmuTime& time);
	virtual byte readMem(word address, const EmuTime& time);
	virtual void writeMem(word address, byte value, const EmuTime& time);
	virtual const byte* getReadCacheLine(word start) const;
	virtual byte* getWriteCacheLine(word start) const;

private:
	inline bool isInside(word address) const;

	int base;
	int end;
	std::auto_ptr<Ram> ram;
};

} // namespace openmsx

#endif
