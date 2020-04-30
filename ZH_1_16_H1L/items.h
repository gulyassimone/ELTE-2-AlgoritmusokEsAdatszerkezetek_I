#pragma once
#include <fstream>


struct itemInfo
{
    int key;
    int measure;
    itemInfo *next;
    itemInfo()
    {
        next = 0;
    }

    friend std::ostream& operator<<(std::ostream &s, const itemInfo *e)
    {
        s << "(key:" << e->key << ",measure: " << e->measure <<  ")";
        return s;
    }
};
class Items
{
public:

    enum error {FILE_NAME_ERROR,EXISTING_KEY,OUT_OF_MEMORY};
    Items(std::string filename);
    ~Items();
    void mergeList(Items *lm);
    itemInfo* L;
    friend std::ostream& operator<<(std::ostream& s, const Items &e)
    {
        itemInfo *p;
        p=e.L->next;
        s << 'L';
        while(p!=0)
        {
            s << "->" << p;
            p=p->next;
        }
        return s;
    }
    int getLenght() const
    {
        return length;
    };
private:
    enum Status {abnorm, norm};
    Status _sx;
    itemInfo _dx;
    std::fstream _x;
    int length;
    bool read();
    void createList();
    void insertKey();
    void statistic(itemInfo *L1,std::string);
    Items(const Items &filename);
    itemInfo* &operator=(const Items &e)
    {
        itemInfo *p,*q;
        L=e.L;
        p=L, q=q->next;
        while (q!=0)
        {
            if(p->next!=0)
            {

                p->next->key=q->key;
                p->next->measure=q->measure;
                p=p->next;
            }
            else
            {
                itemInfo* curr=new itemInfo();
                p->next=curr;
                curr->key=q->key;
                curr->measure=q->measure;
                curr->next=0;
                p=curr;
            }
            q=q->next;
        }
        return L;
    };
    void mergeSortList();
    void ms(itemInfo *L,int n);
    itemInfo* mergeSort(itemInfo *L1, itemInfo* L2);
    itemInfo* cut(itemInfo *L, int n);

};

