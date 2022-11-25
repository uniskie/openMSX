#ifndef YM2413_HH
#define YM2413_HH

#include "ResampledSoundDevice.hh"
#include "SimpleDebuggable.hh"
#include "EmuTime.hh"

#include <cstdint>
#include <memory>
#include <string>

#if defined(FOR_MAMI)
//HACK: MAmi
#include "rpc/server.h"
#include "rpc/client.h"
#include <WinSock2.h>
#endif

namespace openmsx {

class YM2413Core;

class YM2413 final : public ResampledSoundDevice
{
public:
	YM2413(const std::string& name, const DeviceConfig& config);
	~YM2413();

	void reset(EmuTime::param time);
	void writePort(bool port, uint8_t value, EmuTime::param time);
	void pokeReg(uint8_t reg, uint8_t value, EmuTime::param time);

	template<typename Archive>
	void serialize(Archive& ar, unsigned version);

private:
	// SoundDevice
	void setOutputRate(unsigned hostSampleRate, double speed) override;
	void generateChannels(std::span<float*> bufs, unsigned num) override;
	[[nodiscard]] float getAmplificationFactorImpl() const override;

private:
	const std::unique_ptr<YM2413Core> core;
#if defined(FOR_MAMI)
	rpc::client* m_rpcClient = nullptr;	//HACK: MAmi
	char reg_address = -1;
#endif

	struct Debuggable final : SimpleDebuggable {
		Debuggable(MSXMotherBoard& motherBoard, const std::string& name);
		[[nodiscard]] uint8_t read(unsigned address) override;
		void write(unsigned address, uint8_t value, EmuTime::param time) override;
	} debuggable;
};

} // namespace openmsx

#endif
