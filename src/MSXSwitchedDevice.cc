#include "MSXSwitchedDevice.hh"
#include "MSXDeviceSwitch.hh"
#include "MSXMotherBoard.hh"

namespace openmsx {

MSXSwitchedDevice::MSXSwitchedDevice(MSXMotherBoard& motherBoard_, byte id_)
	: motherBoard(motherBoard_), id(id_)
{
	motherBoard.getDeviceSwitch().registerDevice(id, this);
}

MSXSwitchedDevice::~MSXSwitchedDevice()
{
	motherBoard.getDeviceSwitch().unregisterDevice(id);
}

} // namespace openmsx
