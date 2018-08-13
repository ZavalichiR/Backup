#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "hdr.h"

int pid;

static void sig_usr_1()
{	
	printf("\nPID-ul procesului fiu: %d\n", getpid());
	printf("PID-ul procesului parinte: %d\n\n", getppid());
	if(fork()==0)
	{	
		execlp("ps", "ps", 0); //executam comanda "ps"
		//execlp("ps", "ps", "-l", (char*)(0));
	}
}

int main()

{
	//NOTA: dupa rularea programului se deschide alta consola( nu conteaza unde)
	//si se scrie kill -SIGUSR1 $(pidof main)  asa se trimite semnalul pe care il asteapta
	//SIGUSR1 se poate da doar cu kill		

	if (signal(SIGUSR1, sig_usr_1)==SIG_ERR)
	{
		err_sys("Eroare signal");
	}

	while (1) // se foloseste deoarece se asteapta un semnal din exterior
	{
		pause();
	}
	wait(0);// daca procesul tata s-a terminat atunci asteapta si procesul fiu sa se execute

	return 0;
}
