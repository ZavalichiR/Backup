#ifndef _SC_H
#define _SC_H
#include<iostream>
using namespace std;

struct stiva{
	int data;
	stiva *leg;
};
void initS(stiva *&S);
void creareS(stiva *&S);
void push(stiva *&S);
int top(stiva *S);
int pop(stiva *&S);


struct elm
{
	int data;
	elm *succ;
};
struct coada{
	elm *tail, *head;
};

void initC(coada *&C);
void put(coada *&C,int val);
int get(coada *&C,bool &flag);
bool palindrom(char *sir);
#endif
