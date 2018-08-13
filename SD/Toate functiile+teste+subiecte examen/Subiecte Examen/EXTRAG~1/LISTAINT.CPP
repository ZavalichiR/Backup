#include "listaint.h"

void insert(Lista& li, int nr)
{
    Element* q;
    Element* p = new Element;
    p->data = nr;
    if(li==0 || nr<=li->data){
        p->link = li;
        li = p;
        }
    else {
         q = li;
         while(q->link!=0 && nr>q->link->data)
                 q = q->link;
         p->link = q->link;
         q->link = p;
         }
}