#include"Header.h"
int main()
{
	
	inserare("ABC");
	inserare("ACB");
	inserare("BAC");
	inserare("BCA");
	inserare("ACD");
	inserare("DAC");
	inserare("a");
	inserare("b");
	afisare();
	cout << endl;
	stergere("a");
	afisare();
	cout << endl;

	return 0;
}