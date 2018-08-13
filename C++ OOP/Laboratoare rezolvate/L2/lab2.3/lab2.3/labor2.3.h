#pragma once

typedef struct catalog_{
	int nr_studenti;
	char* nume[100];
	void sortare_alfabetica(void);
	void sortare_lungime(void);
	void Read(void);
	void Write(void);
}catalog;