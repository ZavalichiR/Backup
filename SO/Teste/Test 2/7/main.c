#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>
#include"hdr.h"

extern int errno;

static void sig_trm()
{
	printf("Am primit mesajul\n");
	exit(1);
}

int main()
{	
	//NOTA: Dupa ce se introduc datele de la tastatura se da CTRL+D pentru EOF
	//cand apare EOF atunci se primeste semnalul SIGTERM
	char chr;
	int pid,p[2];
	if(pipe(p)==-1)
	{
		err_sys("Eroare PIPE");
		exit(1);
	}
	if((pid=fork())==-1)
	{	err_sys("Eroare FORK");
		exit(2);
	}
	printf("Introduceti datele (pe mai multe linii): \n");
	if(pid)//pid!=0-> PROCES TATA
	{
		close(p[0]);
		while((chr=getchar())!=EOF)
		{
			if(write(p[1],&chr,sizeof(char))<0)
				err_sys("Eroare WRITE");
		}
		close(p[1]);

		kill(pid,SIGTERM);
		exit(1);
		
	}
	else//PROCES FIU
	{	
		if(signal(SIGTERM,sig_trm)==SIG_ERR)
			err_sys("Eroare SIG");
		close(p[1]);
		int d;
		if((d=open("out.txt",O_WRONLY|O_CREAT|O_TRUNC,0666))<0)
			err_sys("Eroare OPEN");

		char ch;
		while(read(p[0],&ch,sizeof(char))!=0)
			if(write(d,&ch,sizeof(char))<0)
				err_sys("Eroare");
		close(p[0]);
		exit(1);
	}
	wait(0);
	return 0;
}

