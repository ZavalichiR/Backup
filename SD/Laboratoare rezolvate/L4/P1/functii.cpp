#include"Header.h"

//Element v[8] = { {"v[0]",1,6},{"v[1]",2,0},{"v[2]",4,1},{"v[3]",6,-1},{"v[4]",5,2},{"v[5]",-1,4},{"v[6]",7,3},{"v[7]",1,7} };
Element v[8] = { {"v[0]",1,7},{ "v[1]",2,0 } ,{ "v[2]",4,1 } ,{ "v[3]",6,-1 } ,{ "v[4]",5,2 } ,{ "v[5]",-1,4 } ,{ "v[6]",7,3 },{ "v[7]",0,6 } };
void afisareInainte()
{
	int cap1 = 3;
	int crt;
	crt = cap1;
	while (crt != -1)
	{
		cout << v[crt].data;
		crt = v[crt].succ;
	}
}

void afisareInapoi()
{
	int cap2 = 5;
	int crt;
	crt = cap2;
	while (crt != -1)
	{
		cout << v[crt].data;
		crt = v[crt].pred;
	}
}
