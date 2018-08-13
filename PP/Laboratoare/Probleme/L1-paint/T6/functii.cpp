# include"header.h"
#include<Windows.h>

int Patrat::read(char *readBuff)
{
	int res;
	res = sscanf_s(readBuff, "patrat(%d,%d,%d,%d", &x, &y, &l);
	if (res == 3 && (readBuff[strlen(readBuff) - 1] == ')'))
		return 1;
	else
	if ((strcmp(readBuff, "Help: ") == 0))
		cout << "patrat(x,y,latura)" << endl;
	return 0;
}
void Patrat::paint()
{
	int i, j, k, OY, OX;
	for (OX = 0; OX < x + l; OX++)
	{
		cout << " ";
	}
	cout << endl;
	
	//Pentru axa OY
	for (OY = 0; OY < y; OY++)
	{
		for (OX = 0; OX < x+l-1; OX++)
		{
			cout << "  ";
		}
		cout << endl;
		}

		for (k = y; k < y + l; k++)
		{
			for (OX = 0; OX < x; OX++)
			{
				cout << "  ";
			}
			if (k == y || k == y - 1 + l)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				for (i = x; i <= x - 1 + l; i++)
					cout << " *";
				cout << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				for (j = x; j <= x - 1 + l; j++)
				{
					if (j == x || j == x - 1 + l)
						cout << " *";
					else
						printf("  ");

				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << endl;
			}
		}
	
	cout << endl;
}

int Dreptunghi::read(char *readBuff)
{
	int res;
	res = sscanf_s(readBuff, "dreptunghi(%d,%d,%d,%d", &x, &y, &l, &L);
	if (res == 4 && (readBuff[strlen(readBuff) - 1] == ')'))
		return 1;
	else
	if ((strcmp(readBuff, "Help: ") == 0))
		cout << "dreptunghi(x,y,lungime,latime)" << endl;
	return 0;
}
void Dreptunghi::paint()
{
	int i, j, OY, OX;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	for (OX = 0; OX<y - 1; OX++)
		cout << endl;
	for (OX = 0; OX<x - 1; OX++)
		cout << "  ";
	cout << " *";
	for (i = x; i < x + L - 1; i++)
	{
		cout << " *";
	}
	cout << endl;

	for (i = y; i < y + l - 2; i++)
	{
		for (OY = 0; OY<x - 1; OY++)
		{
			cout << "  ";
		}
		cout << " *";
		for (j = x; j < x + L - 2; j++)
		{
			cout << "  ";
		}
		cout << " *\n";
	}
	for (OY = 0; OY<x - 1; OY++)
		cout << "  ";
	cout << " *";
	for (i = x; i <x + L - 1; i++)
	{
		cout << " *";
	}
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int Line::read(char *readBuff)
{
	int res;
	res = sscanf_s(readBuff, "line(%d,%d,%d,%d", &x1, &y1, &x2, &y2);
	if (res == 4 && (readBuff[strlen(readBuff) - 1] == ')'))
		return 1;
	else
	if ((strcmp(readBuff, "Help Line") == 0))
		cout << "line(x1,y1,x2,y2)" << endl;
	return 0;
}
void Line::paint()
{
	char **matrice=0;
	matrice = new char*[max(x1, x2) + 1];
	for (int i = 0; i <= max(x1, x2); ++i)
		matrice[i] = new char[max(y1, y2) + 1];

	for (int i = 0; i <= max(x1,x2); ++i)
	{
		for (int j = 0; j<=max(y1,y2); ++j)
		{
			matrice[i][j] = ' ';
		}
	}

	if (x1 == x2 && y1 == y2)
		matrice[x1][y1] = '*';
	else
	{
		if (x1 == x2)
		{
			for (int j = min(y1, y2); j <=max(y1, y2); ++j)
				matrice[x1][j] ='*';
		}
		else
		{
			if (y1 == y2)
			{
				for (int i = min(x1, x2); i <= max(x1, x2); ++i)
					matrice[i][y1] = '*';
			}
			else
			{
				for (int x = min(x1, x2); x <= max(x1, x2); x++)
				{
					for (int y = min(y1, y2); y <= max(y1, y2); y++)
					{
						{
							double e1 = (double)(x - x1) / (double)(x2 - x1);
							double e2 = (double)(y - y1) / (double)(y2 - y1);
							if (abs(e1-e2)<=0.01)
							matrice[x][y] = '*';
						}
						
					}
				}
			}
		}
		

	}

	for (int i = 0; i <= max(x1, x2); ++i)
	{
		for (int j = 0; j<=max(y1, y2); ++j)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << matrice[i][j]<<" ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		cout << endl;
	}
	
}

int Triunghi::read(char *readBuff)
{
	int res;
	res = sscanf_s(readBuff, "triunghi(%d,%d,%d,%d,%d,%d",&x0,&y0, &x1, &y1, &x2, &y2);
	if (res == 6 && (readBuff[strlen(readBuff) - 1] == ')'))
		return 1;
	else
	if ((strcmp(readBuff, "Help Line") == 0))
		cout << "triunghi(x0,y0,x1,y1,x2,y2)" << endl;
	return 0;
}
void Triunghi::paint()
{
	double eps = 0.03;
	char **matrice = 0;
	int coloane = max(max(x1, x2), x0);
	int linii = max(max(y1, y2), y0);
	matrice = new char*[coloane + 1];
	for (int i = 0; i <= coloane; ++i)
		matrice[i] = new char[linii + 1];

	for (int i = 0; i <= coloane; ++i)
	{
		for (int j = 0; j <= linii; ++j)
		{
			matrice[i][j] = ' ';
		}
	}
	//////linia 1/////
	if (x0 == x1 && y0 == y1)
		matrice[x0][y0] = '*';
	else
	{
		if (x0 == x1)
		{
			for (int j = min(y0, y1); j <= max(y0, y1); ++j)
				matrice[x0][j] = '*';
		}
		else
		{
			if (y0 == y1)
			{
				for (int i = min(x0, x1); i <= max(x0, x1); ++i)
					matrice[i][y0] = '*';
			}
			else
			{
				for (int x = min(x0, x1); x <= max(x0, x1); x++)
				{
					for (int y = min(y0, y1); y <= max(y0, y1); y++)
					{
						{
							double e1 = (double)(x - x0) / (double)(x1 - x0);
							double e2 = (double)(y - y0) / (double)(y1 - y0);
							if (abs(e1 - e2) <= eps)
								matrice[x][y] = '*';
						}

					}
				}
			}
		}
	}

		///linia 2////
		if (x1 == x2 && y1 == y2)
			matrice[x1][y1] = '*';
		else
		{
			if (x1 == x2)
			{
				for (int j = min(y1, y2); j <= max(y1, y2); ++j)
					matrice[x1][j] = '*';
			}
			else
			{
				if (y1 == y2)
				{
					for (int i = min(x1, x2); i <= max(x1, x2); ++i)
						matrice[i][y1] = '*';
				}
				else
				{
					for (int x = min(x1, x2); x <= max(x1, x2); x++)
					{
						for (int y = min(y1, y2); y <= max(y1, y2); y++)
						{
							{
								double e1 = (double)(x - x1) / (double)(x2 - x1);
								double e2 = (double)(y - y1) / (double)(y2 - y1);
								if (abs(e1 - e2) <= eps)
									matrice[x][y] = '*';
							}

						}
					}
				}
			}

	}
		///linia 3/////
		if (x0 == x2 && y0 == y2)
			matrice[x0][y0] = '*';
		else
		{
			if (x0 == x2)
			{
				for (int j = min(y0, y2); j <= max(y0, y2); ++j)
					matrice[x0][j] = '*';
			}
			else
			{
				if (y0 == y2)
				{
					for (int i = min(x0, x2); i <= max(x0, x2); ++i)
						matrice[i][y0] = '*';
				}
				else
				{
					for (int x = min(x0, x2); x <= max(x0, x2); x++)
					{
						for (int y = min(y0, y2); y <= max(y0, y2); y++)
						{
							{
								double e1 = (double)(x - x0) / (double)(x2 - x0);
								double e2 = (double)(y - y0) / (double)(y2 - y0);
								if (abs(e1 - e2) <= eps)
									matrice[x][y] = '*';
							}

						}
					}
				}
			}

		}




	for (int i = 0; i <= coloane; ++i)
	{
		for (int j = 0; j <= linii; ++j)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << matrice[i][j] << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		cout << endl;
	}

}

int Cerc::read(char *readBuff)
{
	int res;
	res = sscanf_s(readBuff, "cerc(%d,%d,%d", &a, &b, &r);
	if (res == 3 && (readBuff[strlen(readBuff) - 1] == ')'))
	return 1;
	else
	if ((strcmp(readBuff, "Help Line") == 0))
		cout << "cerc(x,y,raza)" << endl;
	return 0;
}
void Cerc::paint()
{

	char **matrice = 0;
	matrice = new char*[r+a+1];
	for (int i = 0; i <= r+a; ++i)
		matrice[i] = new char[r+b + 1];
	for (int i = 0; i <= r + a; ++i)
	{
		for (int j = 0; j <= r + b; ++j)
			matrice[i][j] = ' ';
	}

	//raza <min(a,b)

	if (r == 0)
		return;
	else
	if (r == 1)
		matrice[a][b] = '*';
	else
	{
		for (int x = r - a; x <= r + a; ++x)
	{
		for (int y = r - b; y <= r + b; ++y)
		{
			double e1 = double(x - a);
			double e2 = double(y - b);
			double e3 = double(r*r);
			int eps;
			if (r > 3)
				eps = 2; 

			else
				eps = 1;
			if (abs(e1*e1 + e2*e2 - e3) <= eps)
				matrice[x][y] = '*';

		}
	}
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	for (int i = 0; i <= r + a; ++i)
	{
		for (int j = 0; j <= r + b; ++j)
			cout << matrice[i][j] << " ";
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}