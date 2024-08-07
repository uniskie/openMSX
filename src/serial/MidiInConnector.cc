#include "MidiInConnector.hh"
#include "MidiInDevice.hh"
#include "DummyMidiInDevice.hh"
#include "checked_cast.hh"
#include "serialize.hh"
#include <memory>

namespace openmsx {

MidiInConnector::MidiInConnector(PluggingController& pluggingController_,
                                 std::string name_)
	: Connector(pluggingController_, name_,
	            std::make_unique<DummyMidiInDevice>())
	, description(std::move(name_))
{
}

std::string_view MidiInConnector::getDescription() const
{
	return description;
}

std::string_view MidiInConnector::getClass() const
{
	return "midi in";
}

MidiInDevice& MidiInConnector::getPluggedMidiInDev() const
{
	return *checked_cast<MidiInDevice*>(&getPlugged());
}

template<typename Archive>
void MidiInConnector::serialize(Archive& ar, unsigned /*version*/)
{
	ar.template serializeBase<Connector>(*this);
}
INSTANTIATE_SERIALIZE_METHODS(MidiInConnector);

} // namespace openmsx
