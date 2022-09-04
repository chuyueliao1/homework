#pragma once
#include <iostream>
#include <string>
#include "Pet.h"
using namespace std;

class fish : public virtual Pet
{
public:
    fish()
    {
        kind = 4;
        HP = 6;
        span = 6;
        price = 15;
        fullness = 6;
    }
    ~fish()
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
