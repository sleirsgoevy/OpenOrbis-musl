#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

int setdomainname(const char *name, size_t len)
{
#ifndef PS4
	return syscall(SYS_setdomainname, name, len);
#else
	errno = ENOSYS;
	return -1;
#endif
}
