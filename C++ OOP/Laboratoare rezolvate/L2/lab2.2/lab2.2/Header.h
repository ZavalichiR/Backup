# pragma once
typedef struct student_{
	int nr_matricol;
	char nume[15];
	char gen;
	float nota;
	void Read(void);
	void Write(void);
}student;


