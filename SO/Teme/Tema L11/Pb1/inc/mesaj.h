#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PROD_KEY 0x400 //cheia permisiune pentru produs
#define CONS_KEY 0x600 //cheia permisiune pentru consumat

const long tip=100;
const int capacitate=5;

struct message{
	long mtype;
	char mtext[2];
};
