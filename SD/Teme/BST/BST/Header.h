#pragma once
#include<iostream>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h> 
using namespace std;



struct Nod
{
	int data;
	Nod*stg, *drt;
};
struct Stiva
{
	Nod *data;
	Stiva* leg;
};

void InitS(Stiva *&S);
void CreareS(Stiva *&S);
void Push(Stiva *&S, Nod *val);
Nod *Top(Stiva *&S);

Nod* MakeNod(int val);
Nod* insert(Nod *&r, int val);
Nod* Father(Nod *rad,Nod *r);
Nod* pred(Nod *rad,int cheie);
Nod* succ(Nod *rad, int cheie);
int Max(Nod *rad);
int Min(Nod *rad);
int maxim(Nod *rad);
int minim(Nod *rad);
void inordine(Nod *rad);
void preordine(Nod *rad);
void postordine(Nod *rad); 