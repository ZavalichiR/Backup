#pragma once
#include<iostream>
#include<string>
using namespace std;

class Animal{
protected:
	string nume, mesaj;
public:
	Animal(){}
	Animal(const char nume[]){}
	virtual void vorbeste() = 0;
};

class Dog :public Animal{

public:
	Dog()
	{
		nume = "Caine";
		mesaj = "Ham Ham";
	}
	Dog(const char nume[])
	{
		this->nume = nume;
		mesaj = "Ham Ham";
	}
	void vorbeste()
	{
		cout << nume << " " << mesaj << endl;
	}
};

class Cat :public Animal{
public:
	Cat()
	{
		nume = "Pisica";
		mesaj = "Miau Miau";
	}
	Cat(const char nume[])
	{
		this->nume = nume;
		mesaj = "Miau Miau";
	}
	void vorbeste()
	{
		cout << nume << " " << mesaj << endl;
	}
};

class Pig :public Animal{

public:
	Pig()
	{
		nume = "Porc";
		mesaj = "Guit Guit";
	}
	Pig(const char nume[])
	{
		this->nume = nume;
		mesaj = "Guit Guit";
	}
	void vorbeste()
	{
		cout << nume << " " << mesaj << endl;
	}
};