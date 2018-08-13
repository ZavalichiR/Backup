#include "../inc/mes.h"
#include "../inc/hdr.h"

int main()
{
pid_t pid=getpid();
Message rmsg;
rmsg.pid=pid;
printf("Cititorul %d trimite cerere si asteapta permisiune.\n",pid);
if (!send(readrequest, &rmsg, sizeof(rmsg)))
	{
		err_sys("Eroare reader: send");
	}
if (!receive( pid, &rmsg, sizeof(rmsg)))
	{
		err_sys("Eroare reader: receive");
	}
printf("Cititorul %d intra in sectiunea critica.\n",pid);
sleep(2);
printf("Cititorul %d iese din sectiunea critica si termina.\n",pid);
rmsg.pid=pid;
if (!send(finished, &rmsg, sizeof(rmsg)))
	{
		err_sys("Eroare reader: receive");
	}
sleep(3);
rmqueue(pid);
return 0;
}
