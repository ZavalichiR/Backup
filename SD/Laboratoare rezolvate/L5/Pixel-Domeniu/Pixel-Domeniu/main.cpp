#include"Header.h"

int main()
{
	coada *C;
	initC(C);
	Atom data;
	cin >> data.x;
	cin >> data.y;
	put(C,data);
	Atom out = get(C);
	cout << out.x << endl;
	cout << out.y << endl;




	return 0;
}