#include "hdr.h"
#include "sem.h"

static char* lockpath(char* name)
{
	static char path[20];
	char* strcat();
	strcpy(path, LOCKDIR);
	return(strcat(path, name));
}
int P(char* name)
{
	char* path, *lockpath();
	int fd, incerc;
	extern int errno;
	path=lockpath(name);
	incerc=0;
	while ((fd=creat(path, 0))<0 && errno==EACCES)
	{
		if (++incerc>MAXINCERC)
		{
			return 0;
		}
		sleep(WAITTIME);
	}
	if (fd<0 || close(fd)<0)
	{
		err_sys("Eroare P()");
	}
	return 1;
}
void V(char* name)
{
	char* lockpath();
	if (unlink(lockpath(name))<0)
	{
		err_sys("Eroare V()");
	}
}
