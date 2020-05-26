#ifndef AIRSTRATUM_H
#define AIRSTRATUM_H
#include <iostream>
#include "weather.h"

class Else;
class Sunny;
class Rain;

class AirStratum
{
public:
    enum error{WRONG_FILENAME};
    virtual ~AirStratum() {};
    char getName()
    {
        return _name;
    }
    double getSize()
    {
        return _size;
    }
    virtual void transmute(Weather* &weather,bool &l,unsigned i, std::vector <AirStratum*> &airStratum) = 0;
    bool remaining()
    {
        return _size > 0.5;
    }
    void changeSize(double e)
    {
        _size +=e ;
    }
protected:
    AirStratum (const char ch, double e = 0) :_name(ch), _size(e) {}
    char _name;
    double _size;
};

class Oxygen: public AirStratum
{
public:
    Oxygen(const char ch, double e = 0) : AirStratum(ch,e) {}
     void transmute(Weather* &weather,bool &l,unsigned i, std::vector <AirStratum*> &airStratum)override
    {
        weather->change(this,l,i,airStratum);
    }
};

class Ozone: public AirStratum
{
public:
    Ozone(const char ch, double e = 0): AirStratum(ch,e) {};
     void transmute(Weather* &weather, bool &l,unsigned i,std::vector <AirStratum*> &airStratum)override
    {
        weather->change(this,l,i,airStratum);
    }
};

class CarbonDioxide: public AirStratum
{
public:
    CarbonDioxide(const char ch, double e = 0) : AirStratum(ch,e) {};
    void transmute(Weather* &weather,bool &l, unsigned i,std::vector <AirStratum*> &airStratum)override
    {
        weather->change(this,l,i,airStratum);
    }
};

#endif // AIRSTRATUM_H
