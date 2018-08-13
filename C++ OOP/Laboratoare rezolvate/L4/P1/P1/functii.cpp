#include"Header.h"
Patrat::Patrat()
{
	latura = 0;
}
Patrat::Patrat(int lat)
{
	latura = lat;
}

Patrat::Patrat(Patrat &d)
{
	latura = d.latura;
}

Patrat::~Patrat()
{
	cout << "\n A fost apelat destructorul \n";
}



void Patrat::SetLatura(int lat)
{
	latura = lat;
}

int Patrat::Aria()
{
	return latura*latura;
}

int Patrat::Perimetru()
{
	return 4 * latura;
}



Dreptunghi::Cerc()
{
	lungime = 0;
	latime = 0;
}
Dreptunghi::Dreptunghi(int lung, int lat)
{
	lungime = lung;
	latime = lat;
}

Dreptunghi::Dreptunghi(Dreptunghi(&d))
{
	lungime = d.lungime;
	latime = d.latime;
}

Dreptunghi::~Dreptunghi()
{
	cout << "\n A fost apelat destructorul \n";
}



void Dreptunghi::SetLungime(int lung)
{
	lungime = lung;
}
void Dreptunghi::SetLatime(int lat)
{
	latime = lat;
}

int Dreptunghi::Aria()
{
	return lungime*latime;
}

int Dreptunghi::Perimetru()
{
	return 2 * (lungime + latime);
}



Dreptunghi::Dreptunghi()
{
	lungime = 0;
	latime = 0;
}
Dreptunghi::Dreptunghi(int lung, int lat)
{
	lungime = lung;
	latime = lat;
}

Dreptunghi::Dreptunghi(Dreptunghi(&d))
{
	lungime = d.lungime;
	latime = d.latime;
}

Dreptunghi::~Dreptunghi()
{
	cout << "\n A fost apelat destructorul \n";
}



void Dreptunghi::SetLungime(int lung)
{
	lungime = lung;
}
void Dreptunghi::SetLatime(int lat)
{
	latime = lat;
}

int Dreptunghi::Aria()
{
	return lungime*latime;
}

int Dreptunghi::Perimetru()
{
	return 2 * (lungime + latime);
}

//problema 1

Multime::Multime()
{
	n = 0;
	dim = 20;
	date = new int[dim];

}
Multime::Multime(int d)
{
	dim = d;
	n = 0;
	date = new int[dim];


}

Multime::~Multime()
{
	if (date)
	{
		delete[] date;
		date = NULL;
	}
}

Multime::Multime(Multime &s)
{
	date = new int[s.n];
	n = s.n;
	dim = s.dim;
	for (int i = 0; i < n; ++i)
	{
		date[i] = s.date[i];
	}
}
void Multime::Adauga(int val)
{
	int ok = 0;
	if (date != NULL && n < dim - 1)
	{
		for (int i = 0; i < n; ++i,ok==0)
		{
			if (date[i] == val)
			{
				ok = 1;
			}
			
		}
		if (ok == 0)
		{
			date[n++] = val;
		}
	}
	else
	{
		cout << "\nVectorul de date este plin\n";
	}
}

void Multime::Afisare()
{
	cout << "Numarul maxim de elemente admise in multime:" << dim << endl;
	cout << "Numarul de elemente continute de multime:" << n << endl;
	cout << "Elementele multimii:" << endl;
	for (int i = 0; i < n; ++i)
		cout << date[i] << ' ';
	cout << endl;
}
void Multime::Extrage(int val)
{
	int i;
	int ok = -1;
	if (date != nullptr)
	{
		cout << "\nElementele extrase sunt: ";
		for (i = 0; i < n; ++i)
		{
			if (date[i] == val)
			{
				ok = i;
				cout << date[i];
				break;
			}
		}
		if (ok != -1)
		{
			for (i = ok; i < n; ++i)
				date[i] = date[i + 1];
			n--;
		}
	}
	else
		exit(EXIT_FAILURE);
}

//problema 2
Stiva::Stiva()
{
	n = -1;
	dim = 20;
	v = new int[dim];
}

Stiva::~Stiva()
{
	if (v)
	{
		delete[] v;
		v = NULL;
	}
}



void Stiva::push(int val)
{
	if (v == nullptr)
		v = new int[dim];

	if (n < dim)
	{
		v[++n] = val;
	}
	else
		exit(EXIT_FAILURE);
}

int Stiva::pop()
{
	if (n == -1)
		cout << "Stiva goala. " << endl;
	else
		return v[n--];
}

int Stiva::top()
{
	if (n != -1)
		return v[n];
	else
		cout << "Stiva goala. " << endl;
}

void Stiva::print()
{
	cout << "Stiva are dimensiunea: " << dim << endl;
	cout << "Stiva contine " << n << " elemente." << endl;
	cout << "Elementele stivei sunt: ";
	for (int i = n; i >= 0; --i)
	{
		cout << v[i] << " ";
	}
	cout << ".";
		
}