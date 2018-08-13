# include"header.h"

int main()
{
	int k = 1;
	while (k)
	{
		//triunghi(10,10,30,30,45,1)
		//triunghi(2, 2, 2, 40, 40, 2)
		cout << "patrat(x,y,latura)" << endl;
		cout << "dreptunghi(x,y,lungime,latime)" << endl;
		cout << "line(x1,y1,x2,y2)" << endl;
		cout << "triunghi(x0,y0,x1,y1,x2,y2)" << endl;
		cout << "cerc(x,y,raza)" << endl;
		cout << "Dati comanda: ";

		Patrat p;
		Dreptunghi d;
		Cerc c;
		Line l;
		Triunghi t;
		char buffer[100];
		cin.getline(buffer, 100);
		char *figura = 0;
		figura = new char[strlen(buffer) + 1];
		strcpy_s(figura, strlen(buffer) + 1, buffer);
		int ok = p.read(figura);
		if (ok)
			p.paint();

		ok = d.read(figura);
		if (ok)
			d.paint();

		ok = c.read(figura);
		if (ok)
			c.paint();

		ok = l.read(figura);
		if (ok)
			l.paint();
		ok = t.read(figura);
		if (ok)
			t.paint();

		cout << "\nDesenati alta figura? " << endl;
		cout << "1 ---- DA" << endl;
		cout << "0 ---- NU" << endl;
		cout << "Raspuns: ";
		cin >> k;
		cin.ignore(100,'\n');
		system("cls");
	}

	_getch();
	return 0;
}