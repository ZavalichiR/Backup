#include"hdr.h"
#include<stdio.h>

#include<signal.h>

pid_t fiu;

void sig_hand1(int sig)
{
	if(sig==SIGUSR1)
	{
		printf("Procesul parinte a primit %d. \n",sig);
		kill(fiu,SIGUSR1);
		exit(0);
	}
	else if((sig == SIGUSR2)||(sig == SIGTERM)||(sig== SIGINT))
	{
		printf("Procesul parinte a primit %d. \n",sig);
		kill(fiu,SIGTERM);
		sleep(1);
		printf("pid PARINTE: %d  |  pid FIU: %d. \n",getppid(),fiu);
		wait(0);
		exit(0);
	}
}

void sig_hand2(int sig)
{
	if(sig == SIGUSR1)
	{
		printf("pid PARINTE: %d, semnal primit %d \n.",getppid(),sig);
		exit(0);
	}
	if(sig == SIGTERM)
	{
		printf("pid PARINTE: %d",getppid());
		exit(0);
	}
}


int main()
{	
	//EXIT() l-am folosit ca sa se termine programul dupa ce primeste un semnal
	//Pentru trimiterea semnalului se scrie in alt terminal:
	//						 kill -semnal $(pidof main)
	//                                                    la semnal pui unul din semnale

	fiu = fork();
	if(fiu ==0)
	{
	
		if(signal(SIGUSR1,sig_hand2)==SIG_ERR)
			err_sys("Eroare SIGUSR1");
		if(signal(SIGTERM,sig_hand1)==SIG_ERR)
			err_sys("Eroare SIGTERM");
	}

	if(signal(SIGUSR1,sig_hand1)==SIG_ERR)
		err_sys("Eroare SIGUSR1");
	if(signal(SIGUSR2,sig_hand1)==SIG_ERR)
		err_sys("Eroare SIGUSR1");
	if(signal(SIGTERM,sig_hand1)==SIG_ERR)
		err_sys("Eroare SIGTERM");
	if(signal(SIGINT,sig_hand1)==SIG_ERR)
		err_sys("Eroare SIGINT");

	//se asteapta procesul din exterior
	while(1)
	{
		pause();
	}
	wait(0);
	return 0;
}
