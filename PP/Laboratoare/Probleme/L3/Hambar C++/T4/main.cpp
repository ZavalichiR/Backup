#include"Header.h"
#include<iostream>

using namespace std;

int main(){
	Animal *theBarn[4];

	Animal Mikey("Soricel");
	Cat cat("Miki");
	Dog dog("Rex");
	Horse horse("Cal alb");

	theBarn[0] = &cat;
	theBarn[1] = &dog;
	theBarn[2] = &horse;


	for (int i = 0; i<3; i++){
		theBarn[i]->Speak();
	}
	system("pause");
	return 0;
}
