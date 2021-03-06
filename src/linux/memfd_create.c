#define _GNU_SOURCE 1
#include <sys/mman.h>
#include <errno.h>
#include "syscall.h"

int memfd_create(const char *name, unsigned flags)
{
#ifndef PS4
	return syscall(SYS_memfd_create, name, flags);
#else
	errno = ENOSYS;
	return -1;
#endif
}
