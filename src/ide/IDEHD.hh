#ifndef IDEHD_HH
#define IDEHD_HH

#include "HD.hh"
#include "AbstractIDEDevice.hh"

namespace openmsx {

class DeviceConfig;
class DiskManipulator;

class IDEHD final : public HD, public AbstractIDEDevice
{
public:
	explicit IDEHD(const DeviceConfig& config);
	IDEHD(const IDEHD&) = delete;
	IDEHD(IDEHD&&) = delete;
	IDEHD& operator=(const IDEHD&) = delete;
	IDEHD& operator=(IDEHD&&) = delete;
	~IDEHD() override;

	template<typename Archive>
	void serialize(Archive& ar, unsigned version);

private:
	// AbstractIDEDevice:
	[[nodiscard]] bool isPacketDevice() override;
	[[nodiscard]] std::string_view getDeviceName() override;
	void fillIdentifyBlock (AlignedBuffer& buffer) override;
	[[nodiscard]] unsigned readBlockStart(AlignedBuffer& buffer, unsigned count) override;
	void writeBlockComplete(AlignedBuffer& buffer, unsigned count) override;
	void executeCommand(byte cmd) override;

private:
	DiskManipulator& diskManipulator;
	unsigned transferSectorNumber = 0; // avoid UMR in serialize()
	const std::string devName;
};

} // namespace openmsx

#endif
