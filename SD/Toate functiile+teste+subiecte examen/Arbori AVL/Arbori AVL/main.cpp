#include"Header.h"
int main(void)
{
	AVL *arbore = 0;
	int val;
	cout << " Elemente: ";
	cin >> val;
	while (val)
	{
		InsAVL(arbore, val);
		cin >> val;
	}
		
	//arbore = arboreCurs();
	cout << "\nAfisare inordine: ";
	inordine(arbore);
	cout << "\nAfisare intendata\n";
	afisareIndent(arbore, 1);
	cout << "\nAdancime: " << adancime(arbore) << endl;
	cout << "\nMaxim:" << max(arbore) << endl;
	cout << "\nMin:" << min(arbore) << endl;
	system("pause");
	return 0;
}