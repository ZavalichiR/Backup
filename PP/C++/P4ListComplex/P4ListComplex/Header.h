#pragma once
#include<iostream>
using namespace std;

template<class T>
class complex{
private:
	T re, im;
public:
	complex(){
		this->re = 0; this->im = 0;
	};
	complex(T re, T im){
		this->re = re;
		this->im = im;
	};

	complex<T>& operator=(complex<T> c)
	{
		this->re = c.re;
		this->im = c.im;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out,complex<T> c)
	{
		return out << c.re << "+(" << c.im << "*j)";
	}
};

template<class T>
class list{
private:
	template<class T>
	struct Nod{
		complex<T> data;
		Nod<T> *succ;
	};
	Nod<T> *head;
public:
	list(){
		head = new Nod<T>;
		head = nullptr;
	};

	list(Nod<T> *next){
		head->succ = next;
	};

	~list(){
		Nod<T> *p = head;
		while (p->succ)
		{
			Nod<T> *q = p;
			p = p->succ;
			delete q;
		}
		delete p;
	};

	void add(complex<T> val)
	{
		Nod<T> *p = new Nod<T>;
		p->data = val;
		p->succ = head;
		head = p;
	}
	void afisare()
	{
		Nod<T> *p = head;
		while (p->succ)
		{
			cout << p->data << " ";
			p = p->succ;
		}
		cout << p->data << ".";
	}

};
