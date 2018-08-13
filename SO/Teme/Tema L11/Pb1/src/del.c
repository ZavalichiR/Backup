#include "../inc/mesaj.h"
#include "../inc/hdr.h"

int main(void)
{
	int id_msgq_prod, id_msgq_cons; //id-urile cozilor de mesaje
	
	if ((id_msgq_prod=msgget((key_t)PROD_KEY, 0))<0) //preluam coada de mesaje a producatorului
	{
		err_sys("Eroare msgget");
	}
	if ((id_msgq_cons=msgget((key_t)CONS_KEY, 0))<0) //preluam coada de mesaje a consumatorului
	{
		err_sys("Eroare msgget");
	}

	//stergem cozile de mesaje
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