#include "YM2413.hh"
#include "YM2413Okazaki.hh"
#include "YM2413Burczynski.hh"
#include "YM2413NukeYKT.hh"
#include "YM2413OriginalNukeYKT.hh"
#include "DeviceConfig.hh"
#include "MSXException.hh"
#include "serialize.hh"
#include "cstd.hh"
#include "narrow.hh"
#include "outer.hh"
#include <cmath>
#include <memory>
#if defined(FOR_MAMI)
#include "MSXMotherBoard.hh"
#endif

namespace openmsx {

// Debuggable

YM2413::Debuggable::Debuggable(
		MSXMotherBoard& motherBoard_, const std::string& name_)
	: SimpleDebuggable(motherBoard_, name_ + " regs", "MSX-MUSIC", 0x40)
{
}

byte YM2413::Debuggable::read(unsigned address)
{
	const auto& ym2413 = OUTER(YM2413, debuggable);
	return ym2413.core->peekReg(narrow<uint8_t>(address));
}

void YM2413::Debuggable::write(unsigned address, byte value, EmuTime::param time)
{
	auto& ym2413 = OUTER(YM2413, debuggable);
	ym2413.pokeReg(narrow<uint8_t>(address), value, time);
}


// YM2413

static std::unique_ptr<YM2413Core> createCore(const DeviceConfig& config)
{
	auto core = config.getChildData("ym2413-core", "");
	if (core == "Okazaki") {
		return std::make_unique<YM2413Okazaki::YM2413>();
	} else if (core == "Burczynski") {
		return std::make_unique<YM2413Burczynski::YM2413>();
	} else if (core == "NukeYKT") {
		return std::make_unique<YM2413NukeYKT::YM2413>();
	} else if (core == "Original-NukeYKT") {
		return std::make_unique<YM2413OriginalNukeYKT::YM2413>(); // for debug
	} else if (core.empty()) {
		// The preferred way to select the core is via the <core> tag.
		// But for backwards compatibility, when that tag is missing,
		// fallback to using the <alternative> tag.
		if (config.getChildDataAsBool("alternative", false)) {
			return std::make_unique<YM2413Burczynski::YM2413>();
		} else {
			return std::make_unique<YM2413Okazaki::YM2413>();
		}
	}
	throw MSXException("Unknown YM2413 core '", core,
	                   "'. Must be one of 'Okazaki', 'Burczynski', 'NukeYKT', 'Original-NukeYKT'.");
}

static constexpr auto INPUT_RATE = unsigned(cstd::round(YM2413Core::CLOCK_FREQ / 72.0));

YM2413::YM2413(const std::string& name_, const DeviceConfig& config)
	: ResampledSoundDevice(config.getMotherBoard(), name_, "MSX-MUSIC", 9 + 5, INPUT_RATE, false)
	, core(createCore(config))
	, debuggable(config.getMotherBoard(), getName())
{
	registerSound(config);

#if defined(FOR_MAMI)
	//HACK: MAmi
	if (!config.getMotherBoard().isTest()) {
	try {
		m_rpcClient = new rpc::client("localhost", 30000);
	} catch (...) {
		// pass through
	}
	}
#endif
}

YM2413::~YM2413()
{
	unregisterSound();

#if defined(FOR_MAMI)
	//HACK: MAmi
	if (m_rpcClient != nullptr)
		m_rpcClient->~client();
#endif
}

void YM2413::reset(EmuTime::param time)
{
	updateStream(time);
	core->reset();
}

void YM2413::writePort(bool port, byte value, EmuTime::param time)
{
#if defined(FOR_MAMI)
	//HACK: MAmi
	if (m_rpcClient != nullptr) {
	if (port == 0)
	{
			reg_address = value;
		}else if( 0 <= reg_address )
	{
		try {
				//DirectAccessToChip(unsigned char device_id, unsigned char unit, unsigned int address, unsigned int data)
				m_rpcClient->async_call("DirectAccessToChip", (unsigned char)9, (unsigned char)0, (unsigned int)reg_address, (unsigned int)value);
		} catch (...) {
			// pass through
		}
	}
	}
#endif

	updateStream(time);

	auto [integral, fractional] = getEmuClock().getTicksTillAsIntFloat(time);
	auto offset = narrow_cast<int>(18 * fractional);
	assert(integral == 0);
	assert(offset >= 0);
	assert(offset < 18);

	core->writePort(port, value, offset);
}

void YM2413::pokeReg(byte reg, byte value, EmuTime::param time)
{
#if defined(FOR_MAMI)
	//HACK: MAmi
	if (m_rpcClient != nullptr) {
	//DirectAccessToChip(unsigned char device_id, unsigned char unit, unsigned int address, unsigned int data)
	m_rpcClient->async_call("DirectAccessToChip", (unsigned char)9, (unsigned char)0, (unsigned int)reg, (unsigned int)value);
	}
#endif

	updateStream(time);
	core->pokeReg(reg, value);
}

void YM2413::setOutputRate(unsigned hostSampleRate, double speed)
{
	ResampledSoundDevice::setOutputRate(hostSampleRate, speed);
	core->setSpeed(speed);
}

void YM2413::generateChannels(std::span<float*> bufs, unsigned num)
{
	assert(bufs.size() == 9 + 5);
	core->generateChannels(bufs.first<9 + 5>(), num);
}

float YM2413::getAmplificationFactorImpl() const
{
	return core->getAmplificationFactor();
}


template<typename Archive>
void YM2413::serialize(Archive& ar, unsigned /*version*/)
{
	ar.serializePolymorphic("ym2413", *core);
}
INSTANTIATE_SERIALIZE_METHODS(YM2413);

} // namespace openmsx
