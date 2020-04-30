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
Items::~Items()
{
    //statistic();
    itemInfo *p,*pe;
    pe=L->next;
    while(pe!=0)
    {
        p=pe->next;
        delete pe;
        L->next=p;
        pe=p;
    }
    delete L;
    //statistic();
}
void Items::createList()
{
    length=0;
    itemInfo *pe;
    pe=L;
    while(read())
    {

        itemInfo *curr;
        curr=new itemInfo;
        curr->key=_dx.key;
        curr->measure=_dx.measure;
        pe->next=curr;
        curr->next=0;
        pe=curr;
        length++;
    }

    //statistic(L->next, "L");
    mergeSortList();

}
void Items::mergeSortList()
{
    int n=length;
    ms(L->next,n);
}
void Items::ms(itemInfo *L1, int n)
{
    if(n>1)
    {
        int n1=n/2;
        itemInfo *L2;
        L2=cut(L1,n1);
        cout << "ms"<< endl ;
        statistic(L2, "L2");
        statistic(L1,"L1");
        ms(L1,n1);
        ms(L2,n-n1);
        L=mergeSort(L->next,L2);
    }
}
itemInfo* Items::mergeSort(itemInfo *L1, itemInfo* L2)
{
    itemInfo *t;
    cout << "merge eleje" << endl ;
    statistic(L2, "L2");
    statistic(L1,"L1");
    statistic(L->next,"L");
    if(L1->key<L2->key)
    {
        L->next=t=L1;
        L1=L1->next;
    }
    else if (L1->key==L2->key)
        throw EXISTING_KEY;
    else
    {
        L->next=t=L2;
        L2=L2->next;
    }
    while (L1!=0 && L2!=0)
    {
        if(L1->key<L2->key)
        {
            t=t->next=L1;
            L1=L1->next;
        }
        else if (L1->key==L2->key)
            throw EXISTING_KEY;
        else
        {
            t=t->next=L2;
            L2=L2->next;
        }
    }
    if(L1!=0)
    {
        t->next=L1;
    }
    else
    {
        t->next=L2;
    }
    cout << "merge vege"<< endl ;
    statistic(L2, "L2");
    statistic(L1,"L1");
    statistic(L->next,"L");
    return L;
}
itemInfo* Items::cut(itemInfo *L1, int n)
{
    itemInfo *p;
    p=L1;
    while(n>1)
    {
        n=n-1;
        p=p->next;
    }
    itemInfo *q=p->next;
    p->next=0;
    return q;
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
                delete q;
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
void Items::statistic(itemInfo *L1, string name)
{
    itemInfo *p;
    p=L1;
    cout << name;
    while(p!=0)
    {
        cout << "->" << p;
        p=p->next;
    }
    cout << endl;
}
