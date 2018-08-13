#pragma once
#include<iostream>
using namespace std;

//Arbore Huffman
struct htNode {
	char symbol;
	htNode *left, *right;
};
// Incapsulare arbore
struct htTree {
	htNode *root;
};
//Tabela cu noduri Huffman (lista inlantuita)
struct hlNode {
	char symbol;
	char *code;
	hlNode *next;
};
//Incapsularea listei
struct hlTable {
	hlNode *first;
	hlNode *last;
};
htTree * buildTree(char *inputString);
hlTable * buildTable(htTree *huffmanTree);
void encode(hlTable *table, char *stringToEncode);
void decode(htTree *tree, char *stringToDecode);
//COADA CU PRIORITATI
//TYPE tipul de data din coada= pointer la nod Huffman
#define TYPE htNode *
#define MAX_SZ 256
struct pQueueNode {
	TYPE val;
	unsigned int priority;
	pQueueNode *next;
};
struct pQueue {
	unsigned int size;
	pQueueNode *first;
};
void initPQueue(pQueue **queue);
void addPQueue(pQueue **queue, TYPE val, unsigned int priority);
TYPE getPQueue(pQueue **queue);
