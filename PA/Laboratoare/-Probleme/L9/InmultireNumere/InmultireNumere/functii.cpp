#include "Header.h"

int numarCifre(int x) {
	int n = 0;
	if (x == 0)
		return 1;
	else
		while (x) {
			n++;
			x /= 10;
		}
	return n;
}

lli DivideEtImpera(int x, int y) {
	int m;
	int n1, n2;
	int ok = 1;
	int xs, xd, ys, yd;
	lli z;
	n1 = numarCifre(x);
	n2 = numarCifre(y);
	int n = (n1 > n2) ? n1 : n2;
	if (n1 == 1 || n2 == 1) {
		return x*y;
	}
	else {
		m = n / 2;
		if (n % 2)
			ok = 0;

		long long int p1, p2, p3, p4;
		xs = xd = x;
		ys = yd = y;
		for (int i = 0; i < m; ++i) {
			xs = xs / 10;
			ys = ys / 10;
		}
		if (ok)
		{
			xd = xd % (int)(pow(10, n - m));
			yd = yd % (int)(pow(10, n - m));
		}
		else
		{
			xd = xd % (int)(pow(10, n - m - 1));
			yd = yd % (int)(pow(10, n - m - 1));
		}

		//printf("Xs: %6d  Xd: %6d  |  Ys: %6d  Yd: %6d\n", xs, xd, ys, yd);
		p1 = DivideEtImpera_Imbunatatit(xs, ys);
		p2 = DivideEtImpera_Imbunatatit(xd, yd);
		p3 = DivideEtImpera_Imbunatatit(xs, yd);
		p4 = DivideEtImpera_Imbunatatit(xd, ys);

		z = p1*(int)pow(10, 2 * m) + p2 + (p3 + p4)*(int)pow(10, m);
		return z;
	}
}


lli DivideEtImpera_Imbunatatit(lli x,lli y) {
	int m;
	int n1, n2;
	int ok=1;
	long int xs, xd, ys, yd;
	lli z;
	n1 = numarCifre(x);
	n2 = numarCifre(y);
	int n = (n1 > n2) ? n1 : n2;
	if (n1 == 1 || n2 == 1) {
		return x*y;
	}
	else {
		m = n / 2;
		if (n % 2)
			ok = 0;

		lli p1, p2, p3;
		xs = xd = x;
		ys = yd = y;
		for (int i = 0; i < m; ++i) {
			xs = xs / 10;
			ys = ys / 10;
		}
		if (ok)
		{
			xd = xd % (int)(pow(10, n - m));
			yd = yd % (int)(pow(10, n - m));
		}
		else
		{
			xd = xd % (int)(pow(10, n - m-1));
			yd = yd % (int)(pow(10, n - m-1));
		}
		
		//printf("Xs: %6d  Xd: %6d  |  Ys: %6d  Yd: %6d\n", xs, xd, ys, yd);
		p1 = DivideEtImpera_Imbunatatit(xs, ys);
		p2 = DivideEtImpera_Imbunatatit(xd, yd);
		p3 = DivideEtImpera_Imbunatatit(xs + xd, ys + yd);
		z = p1*(int)pow(10, 2 * m) + p2 + (p3 - p2 -p1)*(int)pow(10, m);
		return z;
	}
}



llu DivideEtImperaBinar(llu a,llu b,llu n){ 
	if (n <= 4) {
		return a*b;
	}

	llu xs, xd, yd, ys;
	llu m = n / 2;
	llu rez = 0;

	xs = (a >> m);
	xd = ((a << (dim - m)) >> (dim - m));

	ys = (b >> m);
	yd = ((b << (dim- m)) >> (dim - m));

	rez += DivideEtImperaBinar(xd, yd, m);
	rez += DivideEtImperaBinar(xs << m, ys << m, m);
	rez += DivideEtImperaBinar(xs << m, yd, m);
	rez += DivideEtImperaBinar(xd, ys << m, m);

	return rez;
}


llu DivideEtImperaBinar_Imbunatatit(llu a, llu b, llu n){
	if (n <= 4) {
		return a*b;
	}

	llu xs, xd, yd, ys;
	llu m = n / 2;
	llu rez = 0;

	xs = (a >> m);
	xd = ((a << (dim - m)) >> (dim - m));

	ys = (b >> m);
	yd = ((b << (dim - m)) >> (dim - m));

	rez += DivideEtImperaBinar_Imbunatatit(xd, yd, m);
	rez += DivideEtImperaBinar_Imbunatatit(xs << m, ys << m, m);
	rez += DivideEtImperaBinar_Imbunatatit(xs << m, ys, m);
	rez += DivideEtImperaBinar_Imbunatatit(xd, yd << m, m);
	rez += DivideEtImperaBinar_Imbunatatit((xs - xd) << m, (yd - ys), m);

	return rez;
}