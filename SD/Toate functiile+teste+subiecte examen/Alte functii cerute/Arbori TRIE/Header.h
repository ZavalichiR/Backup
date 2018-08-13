#pragma once
#include<iostream>
using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
// trie node
typedef struct trie_node trie_node_t;
struct trie_node
{
	int value;
	trie_node_t *children[ALPHABET_SIZE];
};
// trie ADT
typedef struct trie trie_t;
struct trie
{
	trie_node_t *root;
	int count;
};
