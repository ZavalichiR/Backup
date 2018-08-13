#define LOCKDIR "/tmp/"

#define MAXINCERC 3
#define WAITTIME 3

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <errno.h>

int P(char* name);
void V(char* name);
static char* lockpath(char* name);
