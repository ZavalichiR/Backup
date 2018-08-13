#include"Header.h"

vector<Obiect>init(){
	vector<Obiect> a;
	Obiect ob;
	ob.in = 0; ob.greutate = 3;	ob.valoare = 10;
	a.push_back(ob);

	ob.in = 0; ob.greutate = 5;	ob.valoare = 30;
	a.push_back(ob);

	ob.in = 0; ob.greutate = 6;	ob.valoare = 20;
	a.push_back(ob);

	return a;
}

vector<Punct> interclasare(vector<Punct>s, vector<Punct>t){
	int k = 0, j = 0, L = 1;
	vector<Punct>final;

	while (j<(int)s.size() && k <(int)t.size()){
		if (L == 1){
			if (s[j].x < t[k].x){
				final.push_back(s[j]);
				j++;
			}
			else{
				if (s[j].x == t[k].x){
					if (s[j].y>t[k].y){
						final.push_back(s[j]);
						j++;
						k++;
					}
					else{
						final.push_back(t[k]);
						L = 2;
						j++;
						k++;
					}
				}
				else{
					if (s[j].x > t[k].x){
						if (s[j].y < t[k].y){
							final.push_back(t[k]);
							k++;
							L = 2;
						}
						else{
							k++;
						}
					}
				}
			}
		}
		else{
			if (s[j].x < t[k].x){
				if (s[j].y>t[k].y){
					final.push_back(s[j]);
					L = 1;
					j++;
				}
				else{
					j++;
				}
			}
			else{
				if (s[j].x == t[k].x){
					if (s[j].y < t[k].y){
						final.push_back(t[k]);
						k++;
						j++;
					}
					else{
						final.push_back(s[j]);
						L = 1;
						k++;
						j++;
					}
				}
				else{
					final.push_back(t[k]);
					k++;
				}
			}
		}
	}
	if (j != (int)s.size()){
		for (int i = j; i <(int)s.size(); ++i){
			if (s[i].y>final[final.size() - 1].y)
				final.push_back(s[i]);
		}
	}
	if (k != (int)t.size()){
		for (int i = k; i <(int)t.size(); ++i){
			if (t[i].y > final[final.size() - 1].y)
				final.push_back(t[i]);
		}
	}

	return final;
}

vector<vector<Punct>> Rucsac(vector<Obiect>&obj)
{
	Punct start;
	start.x = 0;
	start.y = 0;

	Punct ts;
	ts.x = obj[0].greutate;
	ts.y = obj[0].valoare;

	vector<Punct> S;
	vector<Punct> T;
	vector<vector<Punct>> Sfinal;

	S.push_back(start);
	T.push_back(ts);
	Sfinal.push_back(S);

	for (int i = 0; i <(int) obj.size() - 1; ++i){
		vector<Punct> aux1;
		aux1 = interclasare(Sfinal[i], T);
		Sfinal.push_back(aux1);
		while (!T.empty())
			T.pop_back();
		for (int j = 0; j < (int)aux1.size(); ++j)
		{
			Punct aux;
			aux.x = aux1[j].x + obj[i + 1].greutate;
			aux.y = aux1[j].y + obj[i + 1].valoare;
			T.push_back(aux);
		}
	}

	Sfinal.push_back(interclasare(Sfinal[obj.size() - 1], T));
	return Sfinal;
}

void Afisare(vector<vector<Punct>>Sfinal)
{
	for (int j = 0; j < (int)Sfinal.size(); ++j)
	{
		cout << "S" << j << " = {";
		for (int i = 0; i <(int)Sfinal[j].size(); ++i)
		{
			cout << "(" << Sfinal[j][i].x << "," << Sfinal[j][i].y << ") ";
		}

		cout << "}." << endl;
	}
}

Punct startFind(vector<vector<Punct>> Sfinal, int M)
{
	Punct a;
	a.x = 0;
	a.y = 0;
	for (int i = Sfinal[Sfinal.size() - 1].size() - 1; i >= 0; --i)
	{
		if (Sfinal[Sfinal.size() - 1][i].x <= M)
		{
			
			a.x = Sfinal[Sfinal.size() - 1][i].x;
			a.y = Sfinal[Sfinal.size() - 1][i].y;
			return a;
		}
	}
	return a;
}

bool apartine(Punct a, vector<Punct>S)
{
	for (int i = 0; i <(int)S.size(); ++i)
	{
		if (a.x == S[i].x &&S[i].y == a.y)
		{
			return true;
		}
	}

	return false;
}

vector<Obiect>InRucsac(vector<vector<Punct>> Sfinal, int M, vector<Obiect> &obj)
{
	vector<Obiect> inRucs;
	Punct a = startFind(Sfinal, M);

	for (int i = obj.size() - 1; i >= 0; --i)
	{
		if (apartine(a, Sfinal[i])){}
		else{
			inRucs.push_back(obj[i]);
			obj[i].in = 1;
			a.x = a.x - obj[i].greutate;
			a.y = a.y - obj[i].valoare;

		}
	}

	return inRucs;

}

void rucsacAfisareTotala(vector<Obiect>a)
{
	cout << endl << endl << "\tRucsacul contine:\n";

	for (int i = 0; i < (int)a.size(); ++i)
	if (a[i].in)
		cout << a[i].greutate << ", " << a[i].valoare << endl;

	cout << "\n";
	for (int i = 0; i < (int)a.size(); ++i)
		cout << a[i].in << "  ";

	cout << "\tAdica valorile: ";
	for (int i = 0; i < (int)a.size(); ++i)
	if (a[i].in)
		cout << a[i].valoare << "  ";
	cout << endl;
}