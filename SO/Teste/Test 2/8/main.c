#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include"hdr.h"


static void sig_quit()
{
	printf("Se executa comanda ls \n");
	execlp("ls","ls",0);
	exit(1);
}

void cod_fiu()
{
	if(signal(SIGQUIT,sig_quit)<0)
		err_sys("Eroare SEMNAL");
}

int main()
{
	int sig;
	pid_t fiu;
	if((fiu=fork())==0)
		cod_fiu();

	do{
		printf("Introduceti S: ");
		scanf("%c",&sig);
		if(sig=='S')
			kill(fiu,SIGQUIT);
	}while(sig!='S');

	// Aici nu mai folosim while(1) pause; sau for ever pause();
	// deoarece semnalul este intern, nu se mai asteapta din exterior
	wait(0);

	return 0;	
}

