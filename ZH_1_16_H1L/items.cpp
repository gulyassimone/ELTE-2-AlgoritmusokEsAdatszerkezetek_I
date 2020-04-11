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
    while(read())
    {
        insertKey();
    }
}
void Items::insertKey()
{
    itemInfo *p;
    p=L->next;
    itemInfo *pe;
    pe=L;
    while(p!=0 && _dx.key>p->key)
    {
        pe=p;
        p=p->next;
    }
    if(p!=0 && _dx.key==p->key)
        throw EXISTING_KEY;
    itemInfo *curr;
    curr=new itemInfo;
    curr->key=_dx.key;
    curr->measure=_dx.measure;
    pe->next=curr;
    curr->next=p;
}
void Items::mergeList(Items *lm)
{
    itemInfo *p,*q, *qe;
    p=L->next;
    q=lm->L->next;
    qe=lm->L;

    while(q!=0)
    {
        if(p==0 || p->key>q->key)
        {
            cout<<"The " << q->key << " key is not exists in the list." <<endl;
            qe=q;
            q=qe->next;
        }
        else if(p->key==q->key)
        {
            if (p->measure<q->measure)
            {
                cout<<"Out of stock. Can't order more, than " << p->measure << " from " << p->key << " item." <<endl;

                qe=q;
            }
            else
            {
                p->measure-=q->measure;
                qe->next=q->next;
                q->next=0;
            }
            q=qe->next;
            p=p->next;
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
