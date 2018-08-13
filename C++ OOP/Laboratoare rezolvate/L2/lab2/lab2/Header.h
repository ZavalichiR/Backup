#ifndef _LAB2_
#define _LAB2_

typedef struct _student{
	int nrMatr;
	char nume[100];
	char gen;
	float nota;
	void (*Read)(struct _student *s);
	void (*Write)(struct _student *s);
}student;

void ReadData(student *st);
void WriteData(student *st);


#endif