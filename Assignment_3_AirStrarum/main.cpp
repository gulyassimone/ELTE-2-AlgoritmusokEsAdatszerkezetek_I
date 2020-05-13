#include <iostream>
#include <fstream>
#include <vector>
#include "airStratum.h"
#include "weather.h"

using namespace std;

string simulate(string &filename)
{
    ifstream f(filename);
    if(f.fail())
        throw AirStratum::WRONG_FILENAME;
    int n=0;
    f>>n;
    vector<AirStratum*> airStratum(n);

    for(int i=0; i<n; i++)
    {
        char ch;
        double s;
        f >> ch >> s;
        switch(ch)
        {
        case 'x' :
            airStratum[i] = new Oxygen(ch,s);
            break;
        case 'z' :
            airStratum[i] = new Ozone(ch,s);
            break;
        case 's' :
            airStratum[i] = new CarbonDioxide(ch,s);
            break;
        }

    }
    string str;
    f>>str;
    vector<Weather*> weather(str.length());

    for( unsigned j=0; j<str.length(); ++j )
    {
        switch(str[j])
        {
        case 'm' :
            weather[j] = Else::instance();
            break;
        case 'n' :
            weather[j] = Sunny::instance();
            break;
        case 'z' :
            weather[j] = Rain::instance();
            break;
        }
    }

    int db=0;
    bool l=true;
    unsigned j=0;
    while( l && j<str.length() )
    {
        unsigned i=0;
        while( l && i<airStratum.size())
        {
            airStratum[i]->transmute(weather[j],l,i,airStratum);
            ++i;
        }
        cout <<"<<-----------Aktualis adatok--------------->>"<<endl;
        cout << db+1 << ". nap utan "<<endl;
        for(unsigned b=0; b<airStratum.size(); b++)
        {
            cout << airStratum[b]->getName() << " " <<  airStratum[b]->getSize() << endl;
        }
        cout <<"<<----------------------------------------->>"<<endl;

        ++j;
        if(j >= str.length()-1 )
            j=0;

        db++;
    }
    bool s=true;
    string result;
    for(unsigned b=0; s && b<airStratum.size(); b++)
    {
        if(airStratum[b]->getSize()<0.5)
        {
            result =airStratum[b]->getName();
            s=false;
        }
    }

    for(unsigned i=0; i<airStratum.size(); ++i)
        delete airStratum[i];

    Else::destroy();
    Sunny::destroy();
    Rain::destroy();

    return result;

}
//#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
    string filename = "input.txt";
    try
    {
        string result = simulate(filename) ;
        cout << "Elso, amelyik elfogy: " << result << endl;
    }
    catch(AirStratum::error e)
    {
        if(e==AirStratum::WRONG_FILENAME)
        {
            cout << "Wrong filename!";
        }
    }
    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("first task empty file", "inp0.txt")
{
    string filename="inp0.txt";
    try
    {
        string result =simulate(filename) ;
        CHECK(result.length()==0);
    }
    catch(AirStratum::error e)
    {
        if(e==AirStratum::WRONG_FILENAME)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("wrong filename", "inp100.txt")
{
    string filename="inp100.txt";
    try
    {
        string result =simulate(filename) ;
    }
    catch(AirStratum::error e)
    {
        CHECK(e==AirStratum::WRONG_FILENAME);
    }
}
TEST_CASE("Only one ozone with 0 size", "inp1.txt")
{
    string filename="inp1.txt";
    try
    {
        string result =simulate(filename) ;
        CHECK(result=="z");
    }
    catch(AirStratum::error e)
    {
        if(e==AirStratum::WRONG_FILENAME)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Only one ozone", "inp2.txt")
{
    string filename = "inp2.txt";
    try
    {
        string result = simulate(filename) ;
        CHECK(result=="z");
    }
    catch(AirStratum::error e)
    {
        if(e==AirStratum::WRONG_FILENAME)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Only one oxygen", "inp3.txt")
{
    string filename="inp3.txt";
    try
    {
        string result =simulate(filename) ;
        CHECK(result=="x");
    }
    catch(AirStratum::error e)
    {
        if(e==AirStratum::WRONG_FILENAME)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("only one Carbondioxide", "inp4.txt")
{
    string filename="inp4.txt";
    try
    {
        string result =simulate(filename) ;
        CHECK(result=="x");
    }
    catch(AirStratum::error e)
    {
        if(e==AirStratum::WRONG_FILENAME)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("only one else", "inp5.txt")
{
    string filename="inp5.txt";
    try
    {
        string result =simulate(filename) ;
        CHECK(result=="s");
    }
    catch(AirStratum::error e)
    {
        if(e==AirStratum::WRONG_FILENAME)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("only one rain", "inp6.txt")
{
    string filename="inp6.txt";
    try
    {
        string result =simulate(filename) ;
        CHECK(result=="x");
    }
    catch(AirStratum::error e)
    {
        if(e==AirStratum::WRONG_FILENAME)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("two air-stratum only one rain", "inp8.txt")
{
    string filename="inp8.txt";
    try
    {
        string result =simulate(filename) ;
        CHECK(result=="z");
    }
    catch(AirStratum::error e)
    {
        if(e==AirStratum::WRONG_FILENAME)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("two air-stratum only one else", "inp9.txt")
{
    string filename="inp9.txt";
    try
    {
        string result =simulate(filename) ;
        CHECK(result=="x");
    }
    catch(AirStratum::error e)
    {
        if(e==AirStratum::WRONG_FILENAME)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("more air-stratum only more weather", "input.txt")
{
    string filename="input.txt";
    try
    {
        string result =simulate(filename) ;
        CHECK(result=="x");
    }
    catch(AirStratum::error e)
    {
        if(e==AirStratum::WRONG_FILENAME)
        {
            cout << "Wrong filename!";
        }
    }
}
#endif
