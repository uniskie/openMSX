#ifndef SCC_HH
#define SCC_HH

#include "ResampledSoundDevice.hh"

#include "SimpleDebuggable.hh"
#include "Clock.hh"
#include "openmsx.hh"

#include <array>
#include <cstdint>

//HACK: MAmi
#include "rpc/server.h"
#include "rpc/client.h"
#include <WinSock2.h>

namespace openmsx {

class SCC final : public ResampledSoundDevice
{
public:
	enum class Mode {Real, Compatible, Plus};

	SCC(const std::string& name, const DeviceConfig& config,
	    EmuTime::param time, Mode mode = Mode::Real);
	~SCC();

	// interaction with realCartridge
	void powerUp(EmuTime::param time);
	void reset(EmuTime::param time);
	[[nodiscard]] uint8_t readMem(uint8_t address,EmuTime::param time);
	[[nodiscard]] uint8_t peekMem(uint8_t address,EmuTime::param time) const;
	void writeMem(uint8_t address, uint8_t value, EmuTime::param time);
	void setMode(Mode newMode);

	// public getters for classes interested to show SCC data
	const std::array<std::array<int8_t, 32>, 5>& getWaveData() const { return wave; }

	template<typename Archive>
	void serialize(Archive& ar, unsigned version);

private:
	// SoundDevice
	[[nodiscard]] float getAmplificationFactorImpl() const override;
	void generateChannels(std::span<float*> bufs, unsigned num) override;

	[[nodiscard]] uint8_t readWave(unsigned channel, unsigned address, EmuTime::param time) const;
	void writeWave(unsigned channel, unsigned address, uint8_t value);
	void setDeformReg(uint8_t value, EmuTime::param time);
	void setDeformRegHelper(uint8_t value);
	void setFreqVol(unsigned address, uint8_t value, EmuTime::param time);
	[[nodiscard]] uint8_t getFreqVol(unsigned address) const;

private:
	rpc::client* m_rpcClient; //HACK: MAmi
	static constexpr int CLOCK_FREQ = 3579545;

	struct Debuggable final : SimpleDebuggable {
		Debuggable(MSXMotherBoard& motherBoard, const std::string& name);
		[[nodiscard]] uint8_t read(unsigned address, EmuTime::param time) override;
		void write(unsigned address, uint8_t value, EmuTime::param time) override;
	} debuggable;

	Clock<CLOCK_FREQ> deformTimer;
	Mode currentMode;

	std::array<std::array<int8_t, 32>, 5> wave;
	std::array<std::array<float, 32>, 5> volAdjustedWave; // ints stored as floats, see comment in adjust()
	std::array<unsigned, 5> incr;
	std::array<unsigned, 5> count;
	std::array<unsigned, 5> pos;
	std::array<unsigned, 5> period;
	std::array<unsigned, 5> orgPeriod;
	std::array<float, 5> out; // ints stored as floats
	std::array<uint8_t, 5> volume;
	uint8_t ch_enable;

	uint8_t deformValue;
	std::array<bool, 5> rotate;
	std::array<bool, 5> readOnly;
};

} // namespace openmsx

#endif
