#include <iostream>
#include "items.h"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{

    try
    {
        Items l("mainList.txt");
        Items lm("soldList.txt");
        cout << "Items info: "<< endl << l << endl;
        cout << "Sold items info: " << endl << lm << endl;
        l.mergeList(&lm);
        cout << "Remain item info: " << endl << l << endl;
    }
    catch (Items::error er)
    {
        if (er==Items::FILE_NAME_ERROR)
            cout << "Wrong file name." << endl;
        if (er==Items::EXISTING_KEY)
            cout << "The key is already existing, i cant insert it." << endl;
        if (er==Items::NOT_EXISTING_KEY)
            cout << "The key is not exesting. " << endl;
        if (er==Items::OUT_OF_MEMORY)
            cout << "Not enough space to create list." << endl;
    }

    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("EmptyFile", "inp1.txt")
{
    try
    {
        Items l("inp0.txt");
        CHECK(l.L->next==0);
    }
    catch (Items::error er)
    {
        if (er==Items::FILE_NAME_ERROR)
            cout << "Wrong file name." << endl;
    }
}

TEST_CASE("Wrong filename exception", "")
{
    try
    {
        Items l("inp100.txt");
    }
    catch (Items::error er)
    {
        CHECK(er==Items::FILE_NAME_ERROR);
    }
}
TEST_CASE("Existing key error when create list", "")
{
    try
    {
        Items l("inp.txt");
    }
    catch (Items::error er)
    {
        CHECK(er==Items::EXISTING_KEY);
        if (er==Items::FILE_NAME_ERROR)
            cout << "Wrong file name." << endl;
    }
}
TEST_CASE("Not existing key, when merge 2 list information", "inp1.txt, inp2.txt")
{
    try
    {
        Items l("inp1.txt");
        Items lm("inp2.txt");
        l.mergeList(&lm);
    }
    catch (Items::error er)
    {
        CHECK(er==Items::NOT_EXISTING_KEY);
        if (er==Items::FILE_NAME_ERROR)
            cout << "Wrong file name." << endl;
    }
}

TEST_CASE("L list get all data", "mainList.txt")
{
    try
    {
        Items l("mainList.txt");

        itemInfo *p;
        p=l.L->next;


        CHECK(p->key==0);
        CHECK(p->measure==2);
        p=p->next;

        CHECK(p->key==1);
        CHECK(p->measure==2);
        p=p->next;

        CHECK(p->key==2);
        CHECK(p->measure==1);
        p=p->next;

        CHECK(p->key==3);
        CHECK(p->measure==4);
        p=p->next;


        CHECK(p->key==5);
        CHECK(p->measure==1);
        p=p->next;

        CHECK(p->key==10);
        CHECK(p->measure==2);
        p=p->next;
    }
    catch (Items::error er)
    {
        if (er==Items::FILE_NAME_ERROR)
            cout << "Wrong file name." << endl;
    }
}
TEST_CASE("L and LM list merge right", "mainList.txt, soldList.txt")
{
    try
    {
        Items l("mainList.txt");
        Items lm("soldList.txt");
        l.mergeList(&lm);

        itemInfo *p;
        p=l.L->next;

        CHECK(p->key==0);
        CHECK(p->measure==2);
        p=p->next;

        CHECK(p->key==1);
        CHECK(p->measure==0);
        p=p->next;

        CHECK(p->key==2);
        CHECK(p->measure==0);
        p=p->next;

        CHECK(p->key==3);
        CHECK(p->measure==1);
        p=p->next;


        CHECK(p->key==5);
        CHECK(p->measure==1);
        p=p->next;

        CHECK(p->key==10);
        CHECK(p->measure==2);
        p=p->next;

    }
    catch (Items::error er)
    {
        if (er==Items::FILE_NAME_ERROR)
            cout << "Wrong file name." << endl;
    }

}
TEST_CASE("L and LM list merge right, when item with 3 key is out of stock", "mainList.txt, inp3.txt")
{
    try
    {
        Items l("mainList.txt");
        Items lm("inp3.txt");
        l.mergeList(&lm);

        itemInfo *p;
        p=l.L->next;

        CHECK(p->key==0);
        CHECK(p->measure==2);
        p=p->next;

        CHECK(p->key==1);
        CHECK(p->measure==0);
        p=p->next;

        CHECK(p->key==2);
        CHECK(p->measure==0);
        p=p->next;

        CHECK(p->key==3);
        CHECK(p->measure==4);
        p=p->next;


        CHECK(p->key==5);
        CHECK(p->measure==1);
        p=p->next;

        CHECK(p->key==10);
        CHECK(p->measure==2);
        p=p->next;

    }
    catch (Items::error er)
    {
        if (er==Items::FILE_NAME_ERROR)
            cout << "Wrong file name." << endl;
    }

}
#endif
