#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define capacity 10
#define readrequest 13
#define writerequest 17
#define finished 19
/* coduri de operatie */

typedef enum {
	FALSE, TRUE
} BOOLEAN;

typedef struct {
	long mtip;
	int pid;
	/* pid-ul procesului client */
	char mtext[13];
	/* spatiu suplimentar */
} Message;

static int openqueue(int key);
BOOLEAN send(int dstkey, Message *buf, int nbytes);
BOOLEAN receive(int srckey, Message *buf, int nbytes);
void rmqueue(int key);
BOOLEAN QueueIsEmpty(int srckey);
