#ifndef __hdr_h 
#define __hdr_h 
#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#define MAXLINE 1024 
#define FILE_MODE ( S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) 
#define DIR_MODE ( FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH) 
#define ever (;;) 
typedef void Sigfunc( int); /* tipul rutinei de tratare */ 
void print_exit( int); /* lucrarea 10 */ 
void print_mask( const char*); /* lucrarea 10 */ 
Sigfunc *signal_intr( int, Sigfunc *); /* lucararea 10,11 */ 
void err_sys( const char *, ...); 
void err_quit( const char *, ...); 
void err_dump( const char *, ...); 
void err_ret( const char *, ...); 
void err_msg( const char *, ...); 
#endif /* __hdr_h */ 
