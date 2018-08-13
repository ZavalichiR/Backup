#include"Header.h"
//------------Functia se cere la examen------------------------------
void decode(htTree *tree, char *stringToDecode)
{
	htNode *traversal = tree->root;
	printf("\nDecoding\nString : %s\nDecoded string : \n", stringToDecode);
	//Pentru fiecare "bit“ al stringului de decodificat mergem la stanga pentru 0
	//si la dreapta pentru 1
	for (int i = 0; stringToDecode[i] != '\0'; i++)
	{
		if (traversal->left == NULL && traversal->right == NULL)
		{
			printf("%c", traversal->symbol);
			traversal = tree->root;
		}
		if (stringToDecode[i] == '0') 
			traversal = traversal->left;
		if (stringToDecode[i] == '1')
			traversal = traversal->right;
		if (stringToDecode[i] != '0' && stringToDecode[i]!='1')
		{ 
			printf("Incorect!\n");
			return;
		}
	}
	if (traversal->left == 0 && traversal->right == 0)
	{
		printf("%c", traversal->symbol);
		traversal = tree->root;
	}
	printf("\n");
}
//-------------------------------------------------------------------