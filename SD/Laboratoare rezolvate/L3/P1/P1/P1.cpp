// P1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
#include<iostream>
#include<stdio.h>
using namespace std;

struct Element{
	char *data;
	int leg;
};
Element V[9]={{"v[0]",1}, {"v[1]",2},{"v[2]",4},{"v[3]", 6},{"v[4]",5},{"v[5]",8}, {"v[6]",0},{"v[7]",0},{"v[8]",-1 }};




int _tmain(int argc, _TCHAR* argv[])
{
	int crt,cap;
cap=3;
crt=cap;
V[3].leg=V[6].leg;
while (crt!=-1)
{
	cout<<V[crt].data<<" ";
  crt=V[crt].leg;
  

}

	_getch();
	return 0;
}

