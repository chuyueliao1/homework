#pragma once
#include <iostream>
#include <string>
#include "Pet.h"
using namespace std;

class rabbit : public virtual Pet
{
public:
    rabbit()
    {
        kind = 3;
        HP = 8;
        span = 8;
        price = 30;
        fullness = 7;
    }
    ~rabbit()
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
