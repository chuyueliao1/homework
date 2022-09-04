#pragma once
#include <iostream>
#include <string>
#include "Pet.h"
using namespace std;

class cat : public virtual Pet
{
public:
    cat()                           
    {
        kind = 1;
        price = 200;
        HP = 10;
        span = 9;
    }
    ~cat()                         
    {
    }
    int Feed();
    int Drink();
    int Play();
    int Action();
    int showPet();
    int Sold();
    int Sleep();
    int Doctor();
    int Toilet();
    int check();
    void Name(string);
    string ShowName();
    void Status(int);
    int ShowStatus();
    int ShowKind();
    int ShowPrice();
    int ShowHP();
    int ShowSpan();
    int ShowMood();
    int ShowFullness();
    int ShowEng();
};


