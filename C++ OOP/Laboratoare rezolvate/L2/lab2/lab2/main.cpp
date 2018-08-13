#include <iostream>
#include "lab2.h"

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
		  v[i].read =  ReadData;
		  v[i].write = WriteData;
	  }
	  for(i = 0;i < nr_studenti;++i)
	  {
		  v[i].read(&v[i]);
		  v[i].write(&v[i]);
	  }
	 delete []v;
	 return 0;
 }