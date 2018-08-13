#include <stdio.h>
void conversie_octal(int k, char sir[])
{
    unsigned int masca;
    masca=(unsigned int)7u;
    int i, p;
    p=(sizeof(int)<<3);
    sir[p+1]='\0';
    for (i=0; i<=p+1; ++i)
    {
        sir[p]='0'+(int)((k&masca)>>i);
        masca<<=i;
        --p;
    }
    sir[0]='0';
}
int main(void)
{
    int x;
    char s[33];
    printf("x=");
    scanf("%d", &x);
    conversie_octal(x, s);
    puts(s);
    return 0;
}
