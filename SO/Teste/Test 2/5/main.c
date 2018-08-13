#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include"hdr.h"
#include"sem.h"

int main()
{
	int descriptor_r,descriptor_w;
	char buffer[100];
	char buffer2[100];
	char c;

	if((descriptor_r=open("in.txt",O_RDONLY|O_CREAT,0666))<0)
	{
		err_sys("Eroare OPEN");
	}
	if((descriptor_w=open("out.txt",O_WRONLY|O_TRUNC|O_CREAT,0666))<0)
	{
		err_sys("Eroare OPEN");
	};
	int semid;
	semid=initsem(0x100);// se initializeaza semaforul, cu ce vrem 0x100 0x200 0x600 etc..

	if(semid<0)
	{
		err_sys("Eroare INITSEM");
	}
	int cpid=fork();
	if(cpid>0)
	{

		while(read(descriptor_r,&c,sizeof(char))!=0)
		{
			sprintf(buffer,"%s%d%s","\nSunt procesul: ",getpid()," si am citit datele\n"); 

			P(semid);
			sleep(random()%3);

			while(read(descriptor_r,&c,sizeof(char))!=0 && c!='\n'){}
			//procesul fiu va citi din fisier linie cu linie
			//dupa ce a citit o linie va afisa ca a citit datele
			//apoi va lasa procesul tata sa citeasca urmatoarea linie
			//se va repeta procesup pana nu vor mai fi linii
			if(c=='\n')
			{	
				write(descriptor_w,buffer,sizeof(char)*strlen(buffer));
			}

			V(semid);
		}	
		exit(1);
	}
	else if(cpid==0)

	{
		while(read(descriptor_r,&c,sizeof(char))!=0)
		{
			sprintf(buffer,"%s%d%s","\nSunt procesul: ",getpid()," si am citit datele\n "); 

			P(semid);
			sleep(random()%3);

			while(read(descriptor_r,&c,sizeof(char))!=0 && c!='\n'){}

			if(c=='\n')
			{	
				write(descriptor_w,buffer,sizeof(char)*strlen(buffer));
			}

			V(semid);
		}	
		exit(1);

	}


	if(close(descriptor_r)<0)
	{
		err_sys("Eroare CLOSE");
	}
	if(close(descriptor_w)<0)
	{
		err_sys("Eroare CLOSE");
	}
	wait(0);
	return 0;
}
