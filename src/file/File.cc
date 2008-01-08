// $Id$

#include "File.hh"
#include "FileBase.hh"
#include "LocalFile.hh"
#include "GZFileAdapter.hh"
#include "ZipFileAdapter.hh"
#include "MSXException.hh"

using std::string;

namespace openmsx {

File::File(const string& url, OpenMode mode)
{
	string protocol, name;
	string::size_type pos = url.find("://");
	if (pos == string::npos) {
		// no explicit protocol, take "file"
		protocol = "file";
		name = url;
	} else {
		protocol = url.substr(0, pos);
		name = url.substr(pos + 3);
	}

	PRT_DEBUG("File: " << protocol << "://" << name);
	if (protocol == "file") {
		file.reset(new LocalFile(name, mode));
	} else {
		throw MSXException("Unsupported protocol: " + protocol);
	}

	if (((pos = name.rfind(".gz")) != string::npos) &&
	    (pos == (name.size() - 3))) {
		file.reset(new GZFileAdapter(file));
	} else
	if (((pos = name.rfind(".GZ")) != string::npos) &&
	    (pos == (name.size() - 3))) {
		file.reset(new GZFileAdapter(file));
	} else
	if (((pos = name.rfind(".zip")) != string::npos) &&
	    (pos == (name.size() - 4))) {
		file.reset(new ZipFileAdapter(file));
	} else
	if (((pos = name.rfind(".ZIP")) != string::npos) &&
	    (pos == (name.size() - 4))) {
		file.reset(new ZipFileAdapter(file));
	}
}

File::~File()
{
}

void File::read(void* buffer, unsigned num)
{
	file->read(buffer, num);
}

void File::write(const void* buffer, unsigned num)
{
	file->write(buffer, num);
}

byte* File::mmap(bool writeBack)
{
	return file->mmap(writeBack);
}

void File::munmap()
{
	file->munmap();
}

unsigned File::getSize()
{
	return file->getSize();
}

void File::seek(unsigned pos)
{
	file->seek(pos);
}

unsigned File::getPos()
{
	return file->getPos();
}

void File::truncate(unsigned size)
{
	return file->truncate(size);
}

void File::flush()
{
	file->flush();
}

const string File::getURL() const
{
	return file->getURL();
}

const string File::getLocalReference() const
{
	return file->getLocalReference();
}

const string File::getOriginalName()
{
	return file->getOriginalName();
}

bool File::isReadOnly() const
{
	return file->isReadOnly();
}

time_t File::getModificationDate()
{
	return file->getModificationDate();
}

} // namespace openmsx
