#pragma once
#include <iostream>
#include <string>
#include "Pet.h"
using namespace std;

class dog :public virtual Pet
{

public:
    dog()
    {
        kind = 2;
        HP = 7;
        span = 10;
        price = 150;
        fullness = 9;
    }   
    ~dog()             
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
    int ShowPrice() ;
    int ShowHP() ;
    int ShowSpan() ;
    int ShowMood() ;
    int ShowFullness() ;
    int ShowEng() ;
};

