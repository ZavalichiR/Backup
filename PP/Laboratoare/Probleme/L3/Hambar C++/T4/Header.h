#pragma once
#include<iostream>
#include<string>

using namespace std;

class Animal
{
	string name;

public:
	Animal()
	{
		name = " ";
	}

	Animal(string name)
	{
		this->name = name;
	}

	virtual ~Animal(){}

	virtual void Speak(){}

	string getName()
	{
		return name;
	}
};

class Dog : public Animal
{
public:
	Dog() :Animal("Nameless Dog"){};

	Dog(string name) : Animal(name){}

	~Dog(){}

	void Speak()
	{
		cout << endl << getName().c_str() << ": Ham Ham!";
	}

};

class Cat : public Animal{
public:
	Cat() :Animal("Nameless Cat"){};

	Cat(string name) : Animal(name){};

	~Cat(){}

	void Speak(){
		cout << endl << getName().c_str() << ": Miau miauuu!";
	}
};


class Horse : public Animal{
public:
	Horse() :Animal("Nameless Horse"){}

	Horse(string name) : Animal(name){}

	~Horse(){}

	void Speak(){
		cout << endl << getName() << ": Fac ca un cal!" << endl;
	}
};
