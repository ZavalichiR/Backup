#include"hdr.h"
#include<signal.h>

int pid;
static void sig_quit()
{
	if(fork()==0)
	{
		execlp("ls","ls",0);
		exit(1);
	}
}

int main()
{
	//"   Semnalul se da cu CTRL+\   "
	//Programul se inchide cu CTRL+C 
	if(signal(SIGQUIT,sig_quit)==SIG_ERR)
	{
		err_sys("Eroare signal");
	}
	while(1)
	{	
		pause();
	}
wait(0);
return 0;
}

