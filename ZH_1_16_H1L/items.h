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
private:
    enum Status {abnorm, norm};
    Status _sx;
    itemInfo _dx;
    std::fstream _x;
    bool read();
    void createList();
    void insertKey();
    void statistic();
    Items(const Items &filename);
    Items* &operator=(const Items &e);

};

