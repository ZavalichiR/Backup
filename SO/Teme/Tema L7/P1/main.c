#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "hdr.h"
#define LOCKDIR "/tmp/"
#define MAXINCERC 3
#define WAITTIME 5
#define BOOLEAN unsigned
#define TRUE 1
#define FALSE 0

static char *lockpath( char *name)
{
	static char path[20];
	char *strcat();
	strcpy( path, LOCKDIR);
	return( strcat( path, name));
}

BOOLEAN lock( char *name)
{
	char *path, *lockpath();
	int fd, incerc;
	extern int errno;
	path = lockpath( name); /* genereaza nume semafor */
	incerc = 0;
	while (( fd=creat( path, 0)) < 0 && errno == EACCES) 
	{
		if ( ++incerc>=MAXINCERC)
			return FALSE;
		sleep( WAITTIME);
	}
	if ( fd < 0 || close(fd) < 0)
		err_sys("lock");
	return(TRUE);
}

void unlock( char *name)
{
	char *lockpath();
	if ( unlink( lockpath( name)) < 0)
		err_sys("unlock");
}

int main()
{
	int pidFIU;
	pidFIU=fork();
	if(pidFIU==0)
	{
		if (lock("semafor"))
		{
			printf("Semafor locked(fiu)\n");
			sleep(5);
			unlock("semafor");
			printf("Semafor unlocked(fiu)\n");
		}
		else
		{
			printf("Lock nereusit pentru procesul(fiu)\n");
		}
		exit(0);
	}
	else
	{
		if(lock("semafor"))
		{
			printf("Semafor locked(parinte)\n");
			sleep(5);
			unlock("semafor");
			printf("Semafor unlocked(parinte)\n");
		}
		else
		{
			printf("Lock nereusit pentru procesul(parinte)\n");
		}	
	}
	exit(0);
	return 0;
}
