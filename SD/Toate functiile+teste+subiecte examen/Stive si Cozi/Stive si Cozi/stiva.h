#pragma once
#include<iostream>
using namespace std;
//     Alocare Statica
#define dim 10
struct stiva1{
	int sp;
	int vect[dim];
};

void init(stiva1 &s);
void push(stiva1 &s, int val);
int pop(stiva1 &s);
int top(stiva1 s);
void stiva1Main();


//     Alocare Dinamica

struct stiva2{
	int data;
	stiva2 *leg;
};

void initS(stiva2 *&s);
bool isEmpty(stiva2 *S);
void pushS(stiva2 *&s, int val);
int popS(stiva2 *&s);
int topS(stiva2 *s);
void stiva2Main();
stiva2 *copy(stiva2 *S);
void sterge(stiva2 *&S);

