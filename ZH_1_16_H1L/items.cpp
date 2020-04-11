#include "items.h"
#include <iostream>

using namespace std;
Items::Items(string filename)
{
    _x.open(filename);
    if(_x.fail())
        throw FILE_NAME_ERROR;
    L = new itemInfo();
    if (!L)
        throw OUT_OF_MEMORY;
    createList();
}

void Items::createList()
{

    itemInfo *p;
    p=L->next;
    itemInfo *pe;
    pe=L;
    while(read())
    {
        while(p!=0 && _dx.key>p->key)
        {
            pe=p;
            p=p->next;
        }
        if(p!=0 && _dx.key==p->key) throw EXISTING_KEY;
        itemInfo *curr;
        curr=new itemInfo;
        curr->key=_dx.key;
        curr->measure=_dx.measure;
        pe->next=curr;
        curr->next=p;
        p=L->next;
        pe=L;
    }
}
void Items::mergeList(Items *lm)
{
    itemInfo *p,*q;
    p=L->next;
    q=lm->L->next;

    while(q!=0)
    {
        if(p==0 || p->key>q->key)
            throw Items::NOT_EXISTING_KEY;
        else if(p->key==q->key)
        {
            if (p->measure<q->measure)
            {
                cout<<"Out of stock. Can't order more, than " << p->key << " from " << p->measure << " item." <<endl;
            }
            else
            {
                p->measure-=q->measure;
            }
            p=p->next;
            q=q->next;
        }
        else
        {
            p=p->next;
        }
    }
}

bool Items::read()
{
    return  (_x >> _dx.key >> _dx.measure)?norm:abnorm;
}
