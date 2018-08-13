#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include "../inc/hdr.h"
#include "../inc/mes.h"

#define MAXOPEN 20
#define MAXMSG 4 

static int openqueue(int key)
{
	static struct { 
		int key; 
		int qid;
	} queues[MAXOPEN];

	int i, avail, qid;
	avail = -1; 

	for (i=0; i < MAXOPEN; i++) 
	{
		if(queues[i].key == key) 
		{
			return queues[i].qid;
		}
		if(queues[i].key == 0 && avail == -1)
		{
			avail = i;
		}
	}
	if( avail == -1 )
	{
		errno = 0;
		return -1;
	}
	if ((qid=msgget(key, 0666 | IPC_CREAT)) < 0)
	{
		return -1;
	}
	queues[avail].key = key;
	queues[avail].qid = qid;
	return qid;
}
BOOLEAN send(int dstkey, Message *buf, int nbytes)
{
	int qid;
	if ((qid = openqueue(dstkey)) < 0) 
	{
		fprintf(stderr, "Send - Eroare openqueue\n");
		return FALSE;
	}
	buf->mtip=1;
	return (msgsnd(qid,buf,nbytes-sizeof(buf->mtip),0) != -1);
}

BOOLEAN receive(int srckey, Message *buf, int nbytes)
{
	int qid;
	if ((qid = openqueue(srckey)) < 0) 
	{
		fprintf(stderr, "Receive - Eroare openqueue\n");
		return FALSE;
	}
	return (msgrcv(qid, buf, nbytes-sizeof(buf->mtip), 0L, 0) !=-1);
}
void rmqueue(int key)
{
	int qid;
	if ((qid=openqueue(key)) < 0 || msgctl(qid, IPC_RMID, NULL) < 0)
	{
		err_sys("Eroare rmqueue");
	}
}
BOOLEAN QueueIsEmpty(int srckey)
{
	struct msqid_ds buf;
	int qid;
	if ((qid = openqueue(srckey)) < 0) 
	{
		fprintf(stderr, "Receive - Eroare openqueue\n");
		return FALSE;
	}
	if (msgctl(qid, IPC_STAT, &buf)<0)
	{
		err_sys("Eroare msgctl");
	}
	if (buf.msg_qnum)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}
