#ifndef WEATHER_H
#define WEATHER_H
#include <iostream>
#include <vector>

class Oxygen;
class Ozone;
class CarbonDioxide;
class AirStratum;

class Weather
{
public:
    virtual char getName() {return _name;}
    virtual ~Weather() {}
    virtual Weather* change(Oxygen* oxygen, bool &l,unsigned i, std::vector<AirStratum*> &airStratum) = 0;
    virtual Weather* change(Ozone* ozone,bool &l,unsigned i,std::vector<AirStratum*> &airStratum) = 0;
    virtual Weather* change(CarbonDioxide* carbonDioxide,bool &l,unsigned i,std::vector<AirStratum*> &airStratum) = 0;
protected:
    char _name;
};
class Else: public Weather
{
public:
    char getName() override {return _name;} ;
    static Else* instance();
    Else* change(Oxygen* oxygen,bool &l,unsigned i, std::vector<AirStratum*> &airStratum) override;
    Else* change(Ozone* ozone,bool &l,unsigned i, std::vector<AirStratum*> &airStratum) override;
    Else* change(CarbonDioxide* carbonDioxide,bool &l,unsigned i,std::vector<AirStratum*> &airStratum) override;
    static void destroy();
private:
    char _name;
    Else() : _name('m') {}
    static Else* _instance;
};
class Rain: public Weather
{
public:
    char getName() override {return _name;} ;
    static Rain* instance();
    Rain* change(Oxygen* oxygen,bool &l,unsigned i,std::vector<AirStratum*> &airStratum) override;
    Rain* change(Ozone* ozone,bool &l,unsigned i,std::vector<AirStratum*> &airStratum) override;
    Rain* change(CarbonDioxide* carbonDioxide,bool &l,unsigned i,std::vector<AirStratum*> &airStratum) override;
    static void destroy();
private:
    Rain():_name('z') {}
    static Rain* _instance;
    char _name;
};
class Sunny: public Weather
{
public:
    char getName() override {return _name;} ;
    static Sunny* instance();
    Sunny* change(Oxygen* oxygen,bool &l,unsigned i,std::vector<AirStratum*> &airStratum) override;
    Sunny* change(Ozone* ozone,bool &l,unsigned i,std::vector<AirStratum*> &airStratum) override;
    Sunny* change(CarbonDioxide* carbonDioxide,bool &l,unsigned i,std::vector<AirStratum*> &airStratum) override;
    static void destroy();
private:
    Sunny():_name('n') {}
    static Sunny* _instance;
    char _name;
};

#endif // WEATHER_H
