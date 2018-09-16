#pragma once

#include "util.h"

#define SIZES_AMOUNT 0x100

struct kernel_globals {
	void *rootfs_cpio;
	void *mem;
	size_t memsz;
	int stackPtr;
	// sizes for each allocation
	size_t sizes[SIZES_AMOUNT];
};

extern struct kernel_globals kernel_globals;

void kernel_init(void *rootfs_cpio, void *mem, size_t sz, const char* args);

void kernel_start(void) NORETURN;
