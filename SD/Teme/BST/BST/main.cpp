#include"Header.h"

int main()
{
	Nod *p = 0;
	int ok = 1, raspuns,val,fiu;
	while (ok)
	{
		cout << "\n<1>----> Folosire arbore curs" << endl;
		cout << "\n<2>----> Construieste arbore" << endl;
		cout << "\n<3>----> Cautare TATA dupa FIU" << endl;
		cout << "\n<4>----> Afisare succesor" << endl;
		cout << "\n<5>----> Afisare predecesor" << endl;
		cout << "\n<6>---->Afisare" << endl;
		cout << "\n<0>----> EXIT" << endl;

		do
		{
			cout << "Raspuns:";
			cin >> raspuns;
		} while (raspuns<0 || raspuns>6);

		switch (raspuns)
		{
		case 0:
			system("cls");
			ok = 0;
			break;
		case 1:
		{
				  system("cls");
				  int v[] = {-9 ,10, 40, 8, -15, 30, -59, 5, 9, 12, 18, 25, 35, 45, -55 };
				  for (int i = 0; i < 15; ++i)
				  {
					  p = insert(p, v[i]);
				  }
				  inordine(p);
				  cout << endl;
				  cout << "Maxim:" << Max(p) << endl;
				  cout << "Maxim:" << maxim(p) << endl;
				  cout << "Minim:" << Min(p) << endl;
				  cout << "Minim:" << minim(p) << endl;
				  system("pause");
				  break; 
		}
			
		case 2:
		{
				  system("cls");
				  cout << "Dati valori( 0 indica finalul):";
				  cin >> val;
				  p = insert(p, val);
				  while (val != 0)
				  {
					  p = insert(p, val);
					  cin >> val;
				  }
				  
				  system("pause");
				  break;
		}
			
		case 3:
		{
				  system("cls");
				  cout << "Introduceti Fiul: ";
				  cin >> fiu;
				  Nod *r = new Nod;
				  r->data = fiu;
				  r->drt = 0;
				  r->stg = 0;
				  Nod *f;
				  f = Father(p, r);
				  cout << "Fiul " << fiu << " are ca tata pe " << f->data << endl;
				  system("pause");
				  system("cls");
				  break;
		}
		case 4:
			{
				system("cls");
				int val;
				cout << "Valoarea pentru care se cauta succesorul: ";
				cin >> val;
				Nod *d = succ(p, val);
				cout << "Succesorul lui "<<val<<" este "<<d->data<<endl;
				system("pause");
				system("cls");
				break;
			}
		case 5:
		{
				system("cls");
				int val;
				cout << "Valoarea pentru care se cauta predecesorul: ";
				cin >> val;
				Nod *d = pred(p, val);
				cout << "Predecesorul lui " << val << " este " << d->data << endl;;
				cout << endl;
				system("pause");
				system("cls");
				break;
		}
		case 6:
		{
				  cout << "Preordine: ";
				  preordine(p);
				  cout << "Inordine: ";
				  inordine(p);
				  cout << "Postordine: ";
				  postordine(p);
		}
		}

	}
	return 0;
}