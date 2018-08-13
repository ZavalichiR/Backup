#include"Header.h"
//------------Functia se cere la examen------------------------------
int search(trie_t *pTrie, char key[])
{
	int level;
	int length = strlen(key);
	int index;
	trie_node_t *pCrawl;
	pCrawl = pTrie->root;
	for (level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);
		if (!pCrawl->children[index])
		{
			return 0;
		}
		pCrawl = pCrawl->children[index];
	}
	return (0 != pCrawl && pCrawl->value);
}
//-------------------------------------------------------------------
trie_node_t *getNode(void)
{
	trie_node_t *pNode = NULL;
	pNode = new trie_node_t;
	if (pNode)
	{
		int i;
		pNode->value = 0;
		for (i = 0; i < ALPHABET_SIZE; i++)
		{
			pNode->children[i] = NULL;
		}
	}
	return pNode;
}
void insert(trie_t *pTrie, char key[])
{
	int level;
	int length = strlen(key);
	int index;
	trie_node_t *pCrawl;
	pTrie->count++;
	pCrawl = pTrie->root;
	for (level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);
		if (!pCrawl->children[index])
		{
			pCrawl->children[index] = getNode();
		}
		pCrawl = pCrawl->children[index];
	}
	pCrawl->value = pTrie->count;
}
