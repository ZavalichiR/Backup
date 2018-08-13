#include"Header.h"
int suma;
void sterge(vector<int> &vect)
{
	int i;
	for (i = 0; i < (int)vect.size() - 1; i++)
		vect[i] = vect[i + 1];
	vect.pop_back();
}
void afisare(vector<int> vect)
{
	int i;
	for (i = 0; i < (int)vect.size(); i++)
		cout << vect[i] << " ";
	cout << endl;

}
void sortHeap(vector<int> &vect)
{
	make_heap(vect.begin(), vect.end());
	sort_heap(vect.begin(), vect.end());

}
int greedy(vector<int> &vect)
{
	int nod1, nod2, sum;
	while (vect.size() != 1)
	{
		nod1 = vect.front();
		sterge(vect);

		nod2 = vect.front();
		sterge(vect);

		sum = nod1 + nod2;
		suma = suma + sum;

		vect.push_back(sum);
		sortHeap(vect);

		afisare(vect);
	}
	return suma;
}