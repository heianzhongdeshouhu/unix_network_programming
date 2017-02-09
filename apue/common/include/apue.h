/*
 * Our own header, to be included before all standard system headers.
 */
#ifndef _APUE_H
#define _APUE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 4096        /* max line length */

void
set_fl(int fd, int flags);

void
clr_fl(int fd, int flags);

void    err_sys(const char *, ...) __attribute__((noreturn));

#endif  /* _APUE_H */
