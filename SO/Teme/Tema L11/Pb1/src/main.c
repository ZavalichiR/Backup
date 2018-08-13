#include <unistd.h>
#include "../inc/mesaj.h"
#include "../inc/hdr.h"

int main(void)
{
	int id_msgq_prod, id_msgq_cons; //id-urile cozilor de mesaje
	int pid_producator, pid_consumator; //PID-urile proceselor fiu
	int i;
	
	if ((id_msgq_prod=msgget((key_t)PROD_KEY, IPC_CREAT | IPC_EXCL | 0666))<0) //cream coada de mesaje a producatorului
	{
		err_sys("Eroare msgget");
	}
	if ((id_msgq_cons=msgget((key_t)CONS_KEY, IPC_CREAT | IPC_EXCL | 0666))<0) //cream coada de mesaje a consumatorului
	{
		err_sys("Eroare msgget");
	}

	struct message msg; //structura de tip mesaj pentru coada
	msg.mtype=tip; //tipul mesajului (conventie 100)
	strcpy(msg.mtext, "");
	msg.mtext[1]='\0';

	for (i=0; i<capacitate; ++i)
	{
		if (msgsnd(id_msgq_prod, &msg, 0, 0)<0) //trimite mesaj NULL catre producator
		{
			err_sys("Eroare msgsnd");
		}
	}

	if ((pid_producator=fork())==0) //cream procesul producator
	{
		execl("./prod", 0);
	}
	if ((pid_consumator=fork())==0) //cream procesul consumator
	{
		execl("./cons", 0);
	}

	//asteptam ca producatorul si consumatorul sa isi incheie executia
	if (waitpid(pid_consumator, NULL, 0)<0)
	{
		err_sys("Eroare wait");
	}
	if (waitpid(pid_producator, NULL, 0)<0)
	{
		err_sys("Eroare wait");
	}
	printf("\nTerminat.\n");

	//dupa ce s-au incheiat procesele fiu, stergem cozile de mesaje
	if (msgctl(id_msgq_prod, IPC_RMID, NULL)<0)
	{
		err_sys("Eroare msgctl");
	}
	if (msgctl(id_msgq_cons, IPC_RMID, NULL)<0)
	{
		err_sys("Eroare msgctl");
	}
	
	return 0;
}