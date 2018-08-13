#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include"hdr.h"

int pid;

static void sig_instr()
{	
	char buff[10];
	int descriptor;
	sprintf(buff,"%d\n",getppid());
	if((descriptor=open("output.txt",O_WRONLY|O_CREAT,0666))<0)
	{
		err_sys("Eroare open");
	}
	
	if(write(descriptor,buff,strlen(buff))<0)
	{
		err_sys("Eroare write");
	}
	if(fork()==0)
	{
		execlp("pwd","pwd",0);
		exit(0);
	}
	if(close(descriptor)<0)
	{
		err_sys("Eroare close");
	}
}

int main()
{
	//NOTA: semnalul se poate trimite si cu ctrl+c
	//"Atentie, dupa ce se da CTRL +C programul se inchide cu CTRL+\ "
	//NU SE FOLOSESTE CTRL+Z, acesta genereaza procese zombi.(echivalent cu nota 2 la test)
	//DACA ATI FACUT UN PROCESC ZOMBI tastati fg pentru a-l inchide
	if(signal(SIGINT,sig_instr)==SIG_ERR)
	{
		err_sys("Eroare signal");
	}
	for ever pause(); //este echivalent cu while(1) pause;
	wait(0);

return 0;
}
