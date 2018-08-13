//#include"revista.h"
//
//int tiraj(publicatie **tab)
//{
//	int t = 0;
//	for (int i = 0; i < 6; i++)
//	{
//
//		revista *r = dynamic_cast<revista *>(tab[i]);
//		if (r)
//		{
//			t += r->gett();
//
//		}
//		delete r;
//	}
//	return t;
//}
//void sort(publicatie**tab)
//{
//	int ok = 1;
//	while (ok)
//	{
//		ok = 0;
//		for (int i = 0; i < 5; i++)
//		{
//			if (tab[i]->getpag() > tab[i + 1]->getpag())
//				swap(tab[i], tab[i + 1]);
//		}
//	}
//}