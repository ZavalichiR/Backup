#include <iostream>
#include "Header.h"

using namespace std;
 int main()
 {
	 int nr_studenti, i;
	 student *v;
	 cout << "Nr studenti:";
	 cin >>nr_studenti;
	  v = new student[nr_studenti];
	  for(i = 0;i < nr_studenti;++i)
	  {
		  v[i].Read();
		 // v[i].Write();
	  }
	  for(i = 0;i < nr_studenti;++i)
	  {
		 // v[i].Read();
		  v[i].Write();
	  }
	 delete []v;
	 return 0;
 }