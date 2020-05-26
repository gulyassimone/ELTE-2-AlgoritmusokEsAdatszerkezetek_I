#include "weather.h"
#include "airStratum.h"
#include <iostream>

using namespace std;
Else* Else::_instance = nullptr;
Else* Else :: instance()
{
    if(!_instance)
    {
        _instance = new Else();
    }
    return _instance;
}
Else* Else :: change(Oxygen* oxygen,bool &l,unsigned i,std::vector<AirStratum*> &airStratum)
{
    CarbonDioxide* a = new CarbonDioxide('s',oxygen->getSize()*0.1);
    oxygen->changeSize(-oxygen->getSize()*0.1);
    unsigned j=i+1;
    bool lp=true;
    while(j<airStratum.size())
    {
        if(lp && airStratum[j]->getName()==a->getName() )
        {
            airStratum[j]->changeSize(a->getSize());
            delete a;
            lp=false;
        }
        if(oxygen->getSize()<0.5)
        {
            if(airStratum[j]->getName()==oxygen->getName() )
            {
                airStratum[j]->changeSize(oxygen->getSize());
                airStratum.erase(airStratum.begin()+i-1);
            }
        }
        j++;
    }
    for(auto b:airStratum)
    {
        if(b->getSize()<0.5)
        {
            l=false;
        }
    }
    if(lp && a->getSize()>=0.5)
    {
        airStratum.push_back(a);
    }
    else if (lp && a->getSize()<0.5)
    {
        delete a;
    }
    return this;
}
Else* Else :: change(Ozone* ozone,bool &l,unsigned i,std::vector<AirStratum*> &airStratum)
{
    Oxygen* a = new Oxygen('x',ozone->getSize()*0.05);
    ozone->changeSize(-ozone->getSize()*0.05);
    unsigned j=i+1;
    bool lp=true;
    while(j<airStratum.size())
    {
        if(lp && airStratum[j]->getName()==a->getName() )
        {
            airStratum[j]->changeSize(a->getSize());
            delete a;
            lp=false;
        }
        if(ozone->getSize()<0.5)
        {
            if(airStratum[j]->getName()==ozone->getName() )
            {
                airStratum[j]->changeSize(ozone->getSize());
                airStratum.erase(airStratum.begin()+i-1);
            }
        }
        j++;
    }
    for(auto b:airStratum)
    {
        if(b->getSize()<0.5)
        {
            l=false;
        }
    }
    if(lp && a->getSize()>=0.5)
    {
        airStratum.push_back(a);
    }
    else if (lp && a->getSize()<0.5)
    {
        delete a;
    }
    return this;
}
Else* Else :: change(CarbonDioxide* carbonDioxide,bool &l,unsigned i,std::vector<AirStratum*> &airStratum)
{
    return this;
}
void Else::destroy()
{
    if ( !_instance )
        delete _instance;
}

Rain* Rain::_instance = nullptr;
Rain* Rain :: instance()
{
    if(!_instance)
    {
        _instance = new Rain();
    }
    return _instance;
}
Rain* Rain :: change(Oxygen* oxygen,bool &l,unsigned i,std::vector<AirStratum*> &airStratum)
{
    Ozone* a = new Ozone('z',oxygen->getSize()*0.5);
    oxygen->changeSize(-oxygen->getSize()*0.5);
    unsigned j=i+1;
    bool lp=true;
    while(j<airStratum.size())
    {
        if(lp && airStratum[j]->getName()==a->getName() )
        {
            airStratum[j]->changeSize(a->getSize());
            delete a;
            lp=false;
        }
        if(airStratum[j]->getName()==oxygen->getName() )
        {
            {
                airStratum[j]->changeSize(oxygen->getSize());
                airStratum.erase(airStratum.begin()+i-1);
            }
        }
        j++;
    }
    for(auto b:airStratum)
    {
        if(b->getSize()<0.5)
        {
            l=false;
        }
    }
    if(lp && a->getSize()>=0.5)
    {
        airStratum.push_back(a);
    }
    else if (lp &&a->getSize()<0.5)
    {
        delete a;
    }
    return this;
}
Rain* Rain :: change(Ozone* ozone,bool &l,unsigned i,std::vector<AirStratum*> &airStratum)
{
    return this;
}
Rain* Rain :: change(CarbonDioxide* carbonDioxide,bool &l,unsigned i,std::vector<AirStratum*> &airStratum)
{
    return this;
}
void Rain::destroy()
{
    if ( !_instance)
        delete _instance;
}

Sunny* Sunny::_instance = nullptr;
Sunny* Sunny :: instance()
{
    if(!_instance)
    {
        _instance = new Sunny();
    }
    return _instance;
}
Sunny* Sunny :: change(Oxygen* oxygen,bool &l,unsigned i,std::vector<AirStratum*> &airStratum)
{
    Ozone* a = new Ozone('z',oxygen->getSize()*0.05);
    oxygen->changeSize(-oxygen->getSize()*0.05);
    unsigned j=i+1;
    bool lp=true;
    while(j<airStratum.size())
    {

        if(lp && airStratum[j]->getName()==a->getName() )
        {
            airStratum[j]->changeSize(a->getSize());
            delete a;
            lp=false;
        }
        if(oxygen->getSize()<0.5)
        {
            if(airStratum[j]->getName()==oxygen->getName() )
            {
                airStratum[j]->changeSize(oxygen->getSize());
                airStratum.erase(airStratum.begin()+i-1);
            }
        }
        j++;
    }
    for(auto b:airStratum)
    {
        if(b->getSize()<0.5)
        {
            l=false;
        }
    }
    if(lp && a->getSize()>=0.5)
    {
        airStratum.push_back(a);
    }
    else if (lp && a->getSize()<0.5)
    {
        delete a;
    }
    return this;
}
Sunny* Sunny :: change(Ozone* ozone,bool &l,unsigned i,std::vector<AirStratum*> &airStratum)
{
    return this;
}
Sunny* Sunny :: change(CarbonDioxide* carbonDioxide,bool &l,unsigned i,std::vector<AirStratum*> &airStratum)
{
    Oxygen* a = new Oxygen('x',carbonDioxide->getSize()*0.05);
    carbonDioxide ->changeSize(-carbonDioxide->getSize()*0.05);
    cout << carbonDioxide->getSize() <<endl;
    unsigned j=i+1;
    bool lp=true;
    while(j<airStratum.size())
    {
        if(lp && airStratum[j]->getName()==a->getName() )
        {
            airStratum[j]->changeSize(a->getSize());
            delete a;
            lp=false;
        }
        if(carbonDioxide->getSize()<0.5)
        {
            if(airStratum[j]->getName()==carbonDioxide->getName() )
            {
                airStratum[j]->changeSize(carbonDioxide->getSize());
                airStratum.erase(airStratum.begin()+i-1);
            }
        }
        j++;
    }
    for(auto b:airStratum)
    {
        if(b->getSize()<0.5)
        {
            l=false;
        }
    }
    if(lp && a->getSize()>=0.5)
    {
        airStratum.push_back(a);
    }
    else if (lp && a->getSize()<0.5)
    {
        delete a;
    }
    return this;
}
void Sunny::destroy()
{
    if ( !_instance )
        delete _instance;
}
