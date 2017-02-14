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

/*
 * Default file access permissions for new files.
 */
#define FILE_MODE (S_IRUSR| S_IWUSR| S_IRGRP| S_IROTH)

void
set_fl(int fd, int flags);

void
clr_fl(int fd, int flags);

void    err_sys(const char *, ...) __attribute__((noreturn));



int lock_reg(int, int, int, off_t, int, off_t); /* {Prog lockreg} */


#define writew_lock(fd, offset, whence, len) lock_reg((fd), F_SETLKW, F_WRLCK, (offset), (whence), (len))



#endif  /* _APUE_H */
