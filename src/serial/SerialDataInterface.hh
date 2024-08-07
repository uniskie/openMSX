#ifndef SERIALDATAINTERFACE_HH
#define SERIALDATAINTERFACE_HH

#include "EmuTime.hh"
#include "openmsx.hh"

namespace openmsx {

class SerialDataInterface
{
public:
	enum class DataBits {
		D5 = 5, D6 = 6, D7 = 7, D8 = 8
	};
	enum class StopBits {
		INV = 0, S1 = 2, S1_5 = 3, S2 = 4
	};
	enum class Parity {
		EVEN = 0, ODD = 1
	};

	virtual void setDataBits(DataBits bits) = 0;
	virtual void setStopBits(StopBits bits) = 0;
	virtual void setParityBit(bool enable, Parity parity) = 0;
	virtual void recvByte(byte value, EmuTime::param time) = 0;

protected:
	~SerialDataInterface() = default;
};

} // namespace openmsx

#endif
