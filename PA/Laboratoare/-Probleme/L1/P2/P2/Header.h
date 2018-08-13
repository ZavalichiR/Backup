

#pragma once

#include<iostream>
using namespace std;
struct node{
	int data;
	node *suc, *prec;
};

void creare(node *&head, int val);
void afisare(node *head);
void inserare(node *&head, int val, int poz);


