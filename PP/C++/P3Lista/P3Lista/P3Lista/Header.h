#pragma once
#include<iostream>
using namespace std;

template<class T>
class List{
private:
	template<class T>
	struct Nod{
		T data;
		Nod<T> *leg;
	};

	Nod<T> *head;
public:

	List(){ head = 0; };
	~List(){
		if (head == head->leg)
		{
			delete head;
			head = 0;
		}
		else
		{
			Nod<T> *p = head;
			while (p->leg!=head)
			{
				Nod<T> *q = p;
				p = p->leg;
				delete q;
			}
			delete p;
			head = 0;
		}
	};
	void add(T val)
	{
		if (head == 0)
		{
			head = new Nod<T>;
			head->data = val;
			head->leg = head;
		}
		else
		{
			Nod<T> *p = new Nod<T>;
			p->data = val;
			p->leg = head->leg;
			head->leg = p;
			head = p;
		}
	};

	void afisare(){
		Nod<T> *p = head;
		while (p->leg!=head)
		{
			cout << p->data << " ";
			p = p->leg;
		}
		cout << p -> data << ".";
	};
};