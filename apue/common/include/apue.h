#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 4096        /* max line length */

void
set_fl(int fd, int flags);

void
clr_fl(int fd, int flags);

void    err_sys(const char *, ...) __attribute__((noreturn));
