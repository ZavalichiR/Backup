
#include "Header.h"

int main() {

	Digraf D;
	int nrVf;
	int *sort;

	cout << "Numarul de varfuri: ";
	cin >> nrVf;
	initDigraf(D, nrVf);

	citireDigraf(D, nrVf);
	sort = sortareTopologicaBFS(D, nrVf);
	if (sort != nullptr)
	{
		cout << "\n\nGraful sortat topologic: ";
		setColor(14);
		for (int i = 1; i <= nrVf; ++i) {
			cout << sort[i] << " ";
		}
		setColor(7);
		cout << endl;
	}

	cout << "\n\n";
	setColor(12);
	system("pause");
	return 0;
}