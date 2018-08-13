#include <sys/msg.h>
#include "../inc/mes.h"
#include "../inc/hdr.h"

int main()
{
	int count=10;
	Message msg;
	int writer_id;

	while(1)
	{
		if (count>0)
		{
			if (!QueueIsEmpty(finished))
			{	
				receive(finished, &msg, sizeof(msg));
				count++;
				printf("Controllerul afla ca cititorul %d a terminat.\n", msg.pid);
			}
			else if(!QueueIsEmpty(writerequest))
			{
				receive(writerequest, &msg, sizeof(msg));
				writer_id=msg.pid;
				count-=100;
				printf("Controllerul a primit cererea de la scriitorul %d.\n", msg.pid);
			}
			else if(!QueueIsEmpty(readrequest))
			{
				receive(readrequest, &msg, sizeof(msg));
				count--;
				strcpy(msg.mtext, "OK");
				send(msg.pid, &msg, sizeof(msg));
				printf("Controllerul a primit cererea de la cititorul %d si ii da permisiunea sa citeasca.\n", msg.pid);
			}
		}
		if (count==0)
		{
			strcpy(msg.mtext, "OK");
			printf("Controllerul ii da permisiunea scriitorului %d.\n", writer_id);
			send(writer_id, &msg, sizeof(msg));
			receive(finished, &msg, sizeof(msg));
			printf("Controllerul afla ca scriitorul %d a terminat.\n", msg.pid);
			count=100;
		}
		while(count < 0)
		{
			receive(finished, &msg, sizeof(msg));
			count++;
			printf("Count negativ. Controllerul afla ca cititorul %d a terminat.\n", msg.pid);
		}
	}
	return 0;
}
