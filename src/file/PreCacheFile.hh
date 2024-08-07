#ifndef PRECACHEFILE_HH
#define PRECACHEFILE_HH

#include <atomic>
#include <string>
#include <thread>

namespace openmsx {

/**
 * Read the complete file once and discard result. Hopefully the file
 * sticks in the OS cache. Mainly useful to avoid CD-ROM spin-ups or to
 * speed up real floppy disk (/dev/fd0) reads.
 */
class PreCacheFile final
{
public:
	explicit PreCacheFile(std::string name);
	~PreCacheFile();

private:
	void run() const;

private:
	const std::string name;
	std::thread thread;
	std::atomic<bool> exitLoop = false;
};

} // namespace openmsx

#endif
