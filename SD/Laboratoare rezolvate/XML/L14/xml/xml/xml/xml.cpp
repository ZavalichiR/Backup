//#define TIXML_USE_STL

#include <iostream>
#include "tinyxml.h"
#include "tinystr.h"


using namespace std;
int main()
{
	TiXmlDocument doc( "SampleData.xml" );
	doc.LoadFile();
	doc.Print();

	TiXmlNode* node = 0;
	TiXmlElement* studentiElement = 0;
	TiXmlElement* itemElement = 0;

	
	//un nod este clasa de baza pentru clasele ce descriu componentele ce se pot gasi 
	//in cadrul unui document xml in afara atributelor (comentarii, elemente, declaratii, etc)

	// un nod poate avea frati, parinti si copii

	//cautam primul nod al documentului
	//in cazul considerat, nodul <Studenti>
	node = doc.FirstChild( "Studenti" );
	//daca acest nod nu exista, se iese din program
	assert( node );
	//incercam transformarea acestui nod intr-un element
	studentiElement = node->ToElement();
	//daca transformarea esueaza, iesim din program
	assert( studentiElement  );

	//cautam in continuare primul copil al nodului <Studenti>
	node = studentiElement->FirstChildElement();	
	//daca acest nod exista
	if (node)
	{
		//cat timp avem noduri de parcurs
		while (node)
		{
			//incercam transformarea nodului curent intr-un element
			itemElement = node->ToElement();
			//daca nu se reuseste transformarea sa intr-un element din cauza unor erori se iese din program
			assert( itemElement );

			//cautam primul atribut al elementului <Student>
			TiXmlAttribute* studentAtt = itemElement->FirstAttribute();

			//daca student are atribute
			if (studentAtt)
			{
				//afisam datele referitoare la primul atribut
				cout << "Nume atribut: " << studentAtt->Name();
				cout << " Valoare atribut: " << studentAtt->Value()<<endl;

				//cautam sa vedem daca exista si alte atribute
				TiXmlAttribute* nextStudentAtt = studentAtt->Next();

				//cat timp atributul urmator exista
				while (nextStudentAtt)
				{
					//afisam datele referitoare la acest atribut
					cout << "Nume atribut: " << nextStudentAtt->Name();
					cout << " Valoare atribut: " << nextStudentAtt->Value()<<endl;

					//trecem la atributul urmator
					nextStudentAtt = nextStudentAtt->Next();
				}
			}

			TiXmlElement* nextItemElement = 0;
			TiXmlNode* nextNode = 0;
			nextNode = itemElement->FirstChildElement();

			//daca exista nod copil pentru nodul Student
			if (nextNode)
			{
				//afisam datele referitoare la acest nod
				nextItemElement = nextNode ->ToElement();
				cout << "Nume element: " << nextNode->Value();
				cout << " Text element: " << nextItemElement->GetText() << endl;
				
				nextNode = nextItemElement->NextSibling();
				//cat timp exista si alte noduri copii
				while (nextNode)
				{
					//afisam datele referitoare la aceste noduri copii
					nextItemElement = nextNode->ToElement();
					cout << "Nume element: " << nextNode->Value();
					cout << " Text element: " << nextItemElement->GetText() << endl;

					//trecem la urmatorul nod copil
					nextNode = nextItemElement->NextSibling();
				}
			}

			//trecem la urmatorul nod din cadrul elementului <Studenti>
			node = node ->NextSibling();
		}
	}
	return 0;
}