#include <iostream>
#include "labor2.3.h"

using namespace std;

int main()
{
	catalog c;
	c.Read();
	c.Write();
	c.sortare_alfabetica();
	c.Write();
	c.sortare_lungime();
	c.Write();
	delete []c.nume;
	return 0;
}