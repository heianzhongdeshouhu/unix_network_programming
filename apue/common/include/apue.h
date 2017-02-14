/*
 * Our own header, to be included before all standard system headers.
 */
#ifndef _APUE_H
#define _APUE_H


#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <signal.h>
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

void    err_msg(const char *, ...);     /* {App misc_source} */
void    err_quit(const char *, ...) __attribute__((noreturn));   

void    err_exit(int, const char *, ...) __attribute__((noreturn));

void    TELL_WAIT(void);        /* parent/child from {Sec race_conditions} */
void    TELL_PARENT(pid_t);
void    TELL_CHILD(pid_t);
void    WAIT_PARENT(void);
void    WAIT_CHILD(void);

#endif  /* _APUE_H */
