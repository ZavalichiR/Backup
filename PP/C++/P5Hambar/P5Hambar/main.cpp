
#include "Header.h"


using namespace std;

int main()
{
	Animal **theBarn;
	int n, k;

	n = rand() % 5 + 3;

	theBarn = new Animal*[n];

	for (int i = 0; i<n; i++)
	{
		k = rand() % 3;
		switch (k)
		{
		case 0:
			theBarn[i] = new Dog;
			break;
		case 1:
			theBarn[i] = new Cat;
			break;
		case 2:
			theBarn[i] = new Pig;
			break;
		default:
			break;
		}
	}

	for (int i = 0; i<n; i++)
	{
		theBarn[i]->vorbeste();
	}

	system("pause");
	return 0;
}