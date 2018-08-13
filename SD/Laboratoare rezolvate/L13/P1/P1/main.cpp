#include"Header.h"


	int main()
	{
		OBST*a;
		int i = 0, j = 0;
		//Citire();
		Matrix();
		a = Build_OBST(i, j);
		
		afisareTree(a, 1);
		system("pause");
		return 0;
	}