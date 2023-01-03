#ifndef WEBDAVCLIENT_H
#define WEBDAVCLIENT_H

#include <time.h>
#include <string>
#include <vector>
#include "webdav/client.hpp"
#include "fs.h"

namespace WebDAV
{
	class WebDavClient
	{
	public:
		int Connect(const char *host, const char *user, const char *pass);
		int Mkdir(const char *path);
		int Rmdir(const char *path, bool recursive);
		int Size(const char *path, int64_t *size);
		int Get(const char *outputfile, const char *path);
		int Put(const char *inputfile, const char *path);
		int Rename(const char *src, const char *dst);
		int Delete(const char *path);
		bool FileExists(const char *path);
		std::vector<FsEntry> ListDir(const char *path);
		bool IsConnected();
		bool Ping();
		const char *LastResponse();
		int Quit();
		std::string GetPath(std::string ppath1, std::string ppath2);
		int Head(const char *path, void *buffer, uint16_t len);

	private:
		int _Rmdir(const char *path);
		WebDAV::Client *client;
		char response[1024];
		bool connected = false;
	};

}
#endif