#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

#define SEMPERM 0600

int initsem(key_t semkey);
void V(int semid);
void P(int semid);
