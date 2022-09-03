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

};

int rabbit::showPet()
{
    cout << "       姓    名 ：" << this->name << endl;
    cout << "       健 康 值 ：" << this->HP << endl;
    cout << "       寿    命 ：" << this->span << endl;
    cout << "       体 力 值 : " << this->eng << endl;
    cout << "       心    情 ：" << this->mood << endl;
    cout << "       饱腹程度 ：" << this->fullness << endl;
    //注意
    if (this->HP < 4)
        cout << "注意！！        " << this->name << "十分虚弱地缩成一团，表示自己感到不舒服（请及时带它去看医生）" << endl;
    if (this->eng < 3)
        cout << "注意！！        " << this->name << "的眼睛因为困倦显得更加红了（请及时把它哄睡）" << endl;
    if (this->mood <= 4)
        cout << "注意！！        " << this->name << "生气的坐在胡萝卜旁边（请让它开心起来）" << endl;
    if (this->fullness <= 4)
        cout << "注意！！        " << this->name << "眼巴巴看着你手中的胡萝卜，口水流了一地（请及时喂食）" << endl;
    if (this->fullness >= 8)
        cout << "注意！！        " << this->name << "脸涨得通红，对你提出如厕的需求（请及时带它去厕所）" << endl;
    //常态
    if (this->HP >= 4)
        cout << "恭喜！！        " << this->name << "处于健康状态" << endl;
    if (this->eng >= 3)
        cout << "恭喜！！        " << this->name << "活力满满，蹦蹦跳跳！" << endl;
    if (this->mood > 4)
        cout << "恭喜！！        " << this->name << "心情愉快，并愿意让你抚摸" << endl;
    if (this->fullness > 4 && this->fullness < 8)
        cout << "恭喜！！        " << this->name << "吃得饱饱的~" << endl;
    return 0;
}

int rabbit::Action()
{
    int cost = 0;//互动产生的花销
    int c = 1;
    while (c != 0)
    {
        cout << "   兔兔：" << this->name << endl;
        cout << "   请选择您的操作：" << endl;
        cout << "   1 -------------- 喂食" << endl;
        cout << "   2 -------------- 喝水" << endl;
        cout << "   3 -------------- 玩耍" << endl;
        cout << "   4 -------------- 看病" << endl;
        cout << "   5 -------------- 哄睡" << endl;
        cout << "   6 -------------- 如厕" << endl;
        cout << "   0 -------------- 结束" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "   体力值：" << this->eng << endl;
        cout << "   生命值：" << this->HP << endl;
        cout << " 预期寿命：" << this->span << endl;
        cout << "   心情值：" << this->mood << endl;
        cin >> c;
        switch (c)
        {
        case 1:cost += this->Feed();   break;
        case 2:cost += this->Drink();  break;
        case 3:cost += this->Play();   break;
        case 4:cost += this->Doctor(); break;
        case 5:cost += this->Sleep();  break;
        case 6:cost += this->Toilet(); break;
        case 0:break;
        }
        system("cls");
        if (this->check() == 1)
        {
            system("pause");
            return cost;
        }
    }
    return cost;
}
int rabbit::Feed()
{
    system("cls");
    cout << "       请问你想投喂哪种食物？" << endl;
    cout << "       1、 -------------- 胡萝卜  (5r)" << endl;
    cout << "       2、 -------------- 大白菜叶(10r)" << endl;
    cout << "       3、 -------------- 黑暗料理(0r)" << endl;
    cout << "       0、 -------------- 退出" << endl;
    system("pause");
    int x;
    cin >> x;
    switch(x)
    {
    case 1:
    {
        if (this->fullness > 7)
        {
            this->fullness += 1;
            this->eng += 1;
            this->HP -= 1;
            this->mood -= 1;
            this->span -= 1;
            cout << "     “咯~~~”，您的兔兔经很撑了，肚子也变得圆鼓鼓的" << endl;
            cout << "-----------------------------------------------------" << endl;
            system("pause");
            return 5;
        }
        cout << "   您给兔兔投喂了一些它最爱的胡萝卜~" << endl;
        cout << "-----------------------------------------------------" << endl;
        this->eng += 2;
        this->fullness += 2;
        this->mood += 2;
        this->span -= 1;
        system("pause");
        return 5;
    }
    case 2:
    {
        if (this->fullness > 7)
        {
            this->fullness += 1;
            this->eng += 1;
            this->HP -= 1;
            this->mood -= 1;
            this->span -= 1;
            cout << "     “咯~~~”，您的兔兔经很撑了，肚子也变得圆鼓鼓的" << endl;
            cout << "-----------------------------------------------------" << endl;
            system("pause");
            return 5;
        }
        cout << "   大白菜很快被一扫而空~" << endl;
        cout << "-----------------------------------------------------" << endl;
        this->eng += 3;
        this->fullness += 2;
        this->mood += 1;
        this->span -= 1;
        system("pause");
        return 10;
    }
    case 3:
    {
        cout << "   吃了一口之后" << this->name << "简直想咬你：主人，兔子急了也会咬人呢！" << endl;
        this->fullness -= 1;
        this->eng -= 1;
        this->HP -= 1;
        this->mood -= 1;
        this->span -= 1;
        system("pause");
        return 0;
    }
    }

    if (this->fullness > 7)
    {
        this->fullness += 1;
        this->eng += 1;
        this->HP -= 1;
        this->mood -= 1;
        this->span -= 1;
        cout << "     “咯~~~”，您的兔兔经很撑了，肚子也变得圆鼓鼓的" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return 0;
    }
}
int rabbit::Drink()
{
    if (this->fullness > 7)
    {
        this->fullness += 1;
        this->HP -= 1;
        this->mood -= 1;
        this->span -= 1;
        cout << "     “咯~~~”，您的兔兔已经很撑了，肚子也变得圆鼓鼓的" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return 0;
    }
    cout << this->name << "补充了足量的水" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->HP += 2;
    this->fullness += 2;
    this->mood += 2;
    this->span -= 1;
    system("pause");
}
int rabbit::Play()
{
    if (this->eng < 3)
    {
        cout << this->name << "耳朵耷拉着，貌似显得不是很热情，下次再陪它玩吧。" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return 0;
    }
    cout << "   陪伴" << this->name << "玩跳格子游戏，兔兔喜欢这个游戏。" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 2;
    this->fullness -= 2;
    this->HP += 2;
    this->mood += 4;
    this->span -= 1;
    system("pause");
}
//哄睡函数
int rabbit::Sleep()
{
    this->HP += 2;
    this->eng += 4;
    this->fullness -= 2;
    this->span -= 1;
    system("pause");
    return 0;
}
//看医生函数
int rabbit::Doctor()
{
    this->HP = 8;
    this->mood = 10;
    this->fullness = 7;
    this->eng = 10;
    this->span -= 1;
    cout << "在兽医小姐姐的全面治疗下，您的兔兔已经满血复活！以后要好好照顾它哦！(耗费 50r)" << endl;
    system("pause");
    return 20;
}
//如厕函数
int rabbit::Toilet()
{
    if (this->fullness > 8)
    {
        this->fullness -= 4;
        this->HP += 2;
        this->span -= 1;
        cout << "噗~~~    兔兔一泻千里,酣畅淋漓……" << endl;
        cout << this->name << "露出它的兔牙，咧嘴一笑，向你卖了个萌" << endl;
        system("pause");
    }
    else if (this->fullness >= 4)
    {
        this->fullness -= 2;
        this->HP += 1;
        this->span -= 1;
        cout << "兔兔愉快地做了某些事。" << endl;
        system("pause");
    }
    else
    {
        cout << this->name << "茫然地看着你，表示自己并没有这样的需求……" << endl;
        system("pause");
        return 0;
    }
}

//出售函数
int rabbit::Sold()
{
    this->status = 0;
    return this->price * 1.5;

}

//判断是否存活
int rabbit::check()
{
    if (this->span <= 0)
    {
        cout << "          从某天开始，" << this->name << "不再像以前一样渴望蹦蹦跳跳，更多时候它选择坐在窝里，凝视远方。" << endl;
        cout << "          或许有时它有点后悔，未在自己身强力壮的时候为自己打造至少三个窝，也好赢得一个聪明的称号。"<<endl;
        cout << "          每每想到此事，它的眼睛就会红上几分。呜呜呜~" << endl;
        cout << "          不论如何，它还是在某天闭上了眼睛……" << endl;
        cout << endl;
        cout << "         【达成结局】： 寿终正寝" << endl;       
        cout << "      7.I.7                    "<< endl; 
        cout << "      7. 7.=                   "<< endl; 
        cout << "      7.   7~.7                " << endl;
        cout << "      7.7    7.+                " << endl;
        cout << "        .7   77,...7            " << endl;
        cout << "         7.7 .77    ,.          " << endl;
        cout << "  7..........+7       .7        " << endl;
        cout << "77.7  7            777.7        " << endl;
        cout << " 7.:7        7.7   7.77.7       " << endl;
        cout << "    .~77   7=.7       7..       " << endl;
        cout << "     7?....7.       7I7I7       " << endl;
        cout << "        7   =7       7.:7       " << endl;
        cout << "          77....777..77         " << endl;
        cout << "         7.7    7..             " << endl;
        cout << "         . 7      .. 77         " << endl;
        cout << "    7..777    77  7..77..7      " << endl;
        cout << "7777.         7.7    7.?7.7     " << endl;
        cout << "7.7=+7      7.7  7.77777.       " << endl;
        cout << "7.77.7         .7 7.7777        " << endl;
        cout << "7= 7.7         .7 . 77          " << endl;
        cout << "7..7.7        7.7.7,77          " << endl;
        cout << "7...      7 ...7 .7             " << endl;
        cout << "   .77    7..:7 ?.,7            " << endl;
        cout << "  .7    7    7.7  7.            " << endl;
        cout << "  ...........,.7...7            " << endl;
        cout << "             77                 " << endl;

        this->HP = 8;
        this->mood = 10;
        this->fullness = 8;
        this->eng = 10;
        this->span = 7;

        this->status = 0;
        return 1;
    }
    else if (this->fullness <= 0 || this->HP <= 0 || this->mood <= 0 || this->eng <= 0)
    {
        cout << "          “小兔子乖乖，把门儿开开”，您是大灰狼吗？" << endl;
        cout << "          对不起，由于您的照顾不周，兔兔最后撒手人寰，永远地离开了您！" << endl;
        cout << endl;
        cout << "         【达成结局】： 不幸夭亡" << endl;

        this->HP = 8;
        this->mood = 10;
        this->fullness = 8;
        this->eng = 10;
        this->span = 7;

        this->status = 0;
        return 1;

    }
    system("pause");
    return 0;
}