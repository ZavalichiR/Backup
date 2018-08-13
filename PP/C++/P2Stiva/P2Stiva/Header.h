#pragma once
#include<iostream>
using namespace std;

template<class T>
class stiva{

private:

	template<class T>
	struct Stack{
		T data;
		Stack<T> *leg;
	};

	Stack<T> *S ; 
public:
	stiva()
	{
		initS(S);
	}

	void initS(Stack<T> *&S){
		S = new Stack<T>;
		S = nullptr;
	};

	void push(T val){
		Stack<T> *p = new Stack<T>;
		p->data = val;
		p->leg = S;
		S = p;
	};
	T pop(){
		if (!S)
		{
			cout << "Stiva este goala" << endl;
			return 0;
		}
		else
		{
			T aux = S->data;
			Stack<T> *p = S;
			S = S->leg;
			delete p;
			return aux;
		}
	};
	T top(){
		if (S)
		{
			return S->data;
		}
		else
		{
			cout << "Stiva este goala!!";
			return -1;
		}
	};
};


