# pragma once
typedef struct student_{
int nr_matricol;
char nume[15];
char gen;
float nota;
void (*read)(struct student_ *st);
void (*write)(struct student_ *st);
}student;

void ReadData(student*st);
void WriteData(student*st);
void Read(void);
void Write(void);