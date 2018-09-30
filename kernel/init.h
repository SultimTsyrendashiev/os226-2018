#pragma once

#include "util.h"

#defing TASKS_SIZE 32

struct kernel_globals {
	void *rootfs_cpio;
	void *mem;
	size_t memsz;
	char **task_list[TASKS_SIZE];
};

extern struct kernel_globals kernel_globals;

void kernel_init(void *rootfs_cpio, void *mem, size_t sz, const char* args);

void kernel_start(void) NORETURN;
