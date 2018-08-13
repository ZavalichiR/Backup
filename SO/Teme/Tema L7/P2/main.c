#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "hdr.h"


int main()
{	
	int nr = 4;
	int fiu[nr];
	int fiuPID, parintePID;
	int j=5;
	int i, k;
	int status;
	for(i=0;i<nr;i++)
	{
		fiu[i]=fork();
		if(fiu[i] == 0)
		{
			fiuPID=getpid();
			parintePID=getppid();
			sleep(j);
			for(k=0; k<10; k++)
			{
				printf("%d cu parintele %d\n",fiuPID, parintePID);
			}
			exit(j);
		}
		j=j+5;
	}
	for(i=0;i<10;i++)
	{
		printf("%d cu procesele fiu: ",getpid());
		for(j=0;j<nr;j++)
		{
			printf(" %d",fiu[j]);
		}
		printf("\n");
	}

	for(i=0;i<nr;i++)
	{
		wait(&status);
		printf("status: ");
		print_exit(status);
	}

	
	return 0;
}

