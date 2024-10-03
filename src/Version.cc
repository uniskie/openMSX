#include "Version.hh"
#include "strCat.hh"

namespace openmsx {

#include "Version.ii"

std::string Version::full()
{
#if defined(FOR_MAMI)
	std::string result = strCat("openMSX for MAMI ", VERSION);
#else
	std::string result = strCat("openMSX ", VERSION);
#endif
	if constexpr (!RELEASE) strAppend(result, '-', REVISION);
	return result;
}

} // namespace openmsx
