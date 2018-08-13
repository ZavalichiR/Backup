#pragma once

class PUNCT {
	int x, y;

public:
	PUNCT();
	PUNCT(int x, int y);
	~PUNCT();

	int getX();
	void setX(int val);
	int getY();
	void setY(int val);

	bool operator==(const PUNCT&);
	PUNCT& operator=(const PUNCT&);
};

class MULTIME {
	int nrElem;
	PUNCT* puncte;

public:
	MULTIME();
	~MULTIME();

	MULTIME(const MULTIME&);

	int getNrElem();
	void adauga(PUNCT p);
	PUNCT& operator[](int i);
	MULTIME& operator=(const MULTIME&);
};

MULTIME interclasareGrafice(MULTIME* S, MULTIME* T);
void rucsac(int M, int n, int* w, int* p, int*& x);

