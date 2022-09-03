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
        HP = 7;
        span = 10;
        price = 150;
        fullness = 9;
    }   
    ~dog()             
    {

    }
    void Feed();
    void Drink();
    void Play();
    void Action();
    void showPet();
    int Sold();
    void Sleep();
    void Doctor();
    void Toilet();
    int check();
};

void dog::showPet()
{
    cout << "       姓    名 ：" << this->name << endl;
    cout << "       健 康 值 ：" << this->HP << endl;
    cout << "       寿    命 ：" << this->span << endl;
    cout << "       体 力 值 : " << this->eng << endl;
    cout << "       心    情 ：" << this->mood << endl;
    cout << "       饱腹程度 ：" << this->fullness << endl;
    //注意
    if (this->HP < 2)
        cout << "注意！！        " << this->name << "十分虚弱地缩成一团，表示自己感到不舒服（请及时带它去看医生）" << endl;
    if (this->eng < 3)
        cout << "注意！！        " << this->name << "睡眼惺忪，表示自己感到困倦了（请及时把它哄睡）" << endl;
    if (this->mood <= 4)
        cout << "注意！！        " << this->name << "垂头丧气，呜咽不止，显得十分垂头丧气（请让它开心起来）" << endl;
    if (this->fullness <= 6)
        cout << "注意！！        " << this->name << "眼巴巴看着你手中的骨头，口水流了一地（请及时喂食）" << endl;
    if (this->fullness >= 10)
        cout << "注意！！        " << this->name << "脸涨得通红，对你提出如厕的需求（请及时带它去厕所）" << endl;
    //常态
    if (this->HP >= 2)
        cout << "恭喜！！        " << this->name << "处于健康状态" << endl;
    if (this->eng >= 3)
        cout << "恭喜！！        " << this->name << "活力满满，冲着你一个劲儿的摇尾巴！" << endl;
    if (this->mood > 4)
        cout << "恭喜！！        " << this->name << "心情愉快，对你喵喵两声~" << endl;
    if (this->fullness > 6 && this->fullness < 10)
        cout << "恭喜！！        " << this->name << "吃得饱饱的~" << endl;
}

void dog::Action()
{
    int c = 1;
    while (c != 0)
    {
        cout << "   狗狗：" << this->name << endl;
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
        case 1:this->Feed();   break;
        case 2:this->Drink();  break;
        case 3:this->Play();   break;
        case 4:this->Doctor(); break;
        case 5:this->Sleep();  break;
        case 6:this->Toilet(); break;
        case 0:break;
        }
        system("cls");
        if (this->check() == 1)
        {
            system("pause");
            return;
        }
    }
}
void dog::Feed()
{
    if (this->fullness > 9)
    {
        this->fullness += 1;
        this->eng += 1;
        this->HP -= 1;
        this->mood -= 1;
        this->span -= 1;
        cout << "     “咯~~~”，您的狗狗已经很撑了，肚子也变得圆鼓鼓的" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   您给狗狗投喂了一些它最爱的红烧肉~" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->fullness += 2;
    this->mood += 2;
    this->span -= 1;
    system("pause");
}
void dog::Drink()
{
    if (this->fullness > 9)
    {
        this->fullness += 1;
        this->HP -= 1;
        this->mood -= 1;
        this->span -= 1;
        cout << "     “咯~~~”，您的狗狗已经很撑了，肚子也变得圆鼓鼓的" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << this->name << "补充了足量的水" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->HP += 2;
    this->fullness += 2;
    this->mood += 2;
    this->span -= 1;
    system("pause");
}
void dog::Play()
{
    if (this->eng < 2)
    {
        cout << this->name << "耳朵耷拉着，貌似显得不是很热情，下次再陪它玩吧。" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   陪伴" << this->name << "玩捡瓶子游戏，它总是可以在你丢出瓶子之后立刻捡回来。" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 2;
    this->fullness -= 2;
    this->HP += 2;
    this->mood += 4;
    this->span -= 1;
    system("pause");
}
//哄睡函数
void dog::Sleep()
{
    this->HP += 2;
    this->eng += 4;
    this->fullness -= 2;
    this->span -= 1;
    system("pause");
}
//看医生函数
void dog::Doctor()
{
    this->HP = 7;
    this->mood = 10;
    this->fullness = 9;
    this->eng = 10;
    this->span -= 1;
    cout << "在兽医小姐姐的全面治疗下，您的狗狗已经满血复活！以后要好好照顾它哦！" << endl;
    system("pause");
    return;
}
//如厕函数
void dog::Toilet()
{
    if (this->fullness > 8)
    {
        this->fullness -= 4;
        this->HP += 2;
        this->span -= 1;
        cout << "轰~~~    狗狗一泻千里,酣畅淋漓……" << endl;
        cout << this->name << "有点不好意思地朝你吐了吐舌头，你摸摸它的头，清理干净现场" << endl;
        system("pause");
    }
    else if (this->fullness >= 4)
    {
        this->fullness -= 2;
        this->HP += 1;
        this->span -= 1;
        cout << "狗狗本来想就地解决一下，但是想起来你教导过它，做个干净的狗狗需要文明大小便,于是默默忍住了这个邪恶的念头，选择找了个小草丛。" << endl;
        system("pause");
    }
    else
    {
        cout << this->name << "茫然地看着你，表示自己并没有这样的需求……" << endl;
        system("pause");
        return;
    }
}

//出售函数
int dog::Sold()
{
    this->status = 0;
    return this->price*2.5;

}

//判断是否存活
int dog::check()
{
    if (this->span <= 0)
    {
        cout << "          从某天开始，" << this->name << "不再一刻不停地向你撒娇讨肉吃，它的毛发开始稀疏，牙齿也渐渐脱落，唯一不变的是对你永远的爱意" << endl;
        cout << "          这天，它最后一次凑到你的身边，你感受到它湿热的舌头舔了舔你，然后它似乎是下定了什么决心似的，返回了自己熟悉的小窝。" << endl;
        cout << "          你以为它只是因为年纪大了，走几步便会累了，并没有选择去打扰它" << endl;
        cout << "          就在你继续忙碌着店里工作的时候，它永远地离开了这里，再也没有回来。" << endl;
        cout << "          你找了每一个它可能去的地方，但没有任何熟悉的影子，或许，告别早在最后一次靠近就已经书写。" << endl;
        cout << "          你的汪汪选择了独自前往它的下一站……" << endl;
        cout << endl;
        cout << "         【达成结局】： 寿终正寝" << endl;

        this->HP = 7;
        this->mood = 10;
        this->fullness = 9;
        this->eng = 10;
        this->span = 10;

        this->status = 0;
        return 1;
    }
    else if (this->fullness <= 0 || this->HP <= 0 || this->mood <= 0 || this->eng <= 0)
    {
        cout << "          做一行，爱一行。身为店员的你，在某些事情上还是没有合格。" << endl;
        cout << "          由于您的照顾不周，小狗最后撒手人寰，永远地离开了您！" << endl;
        cout << endl;
        cout << "         【达成结局】： 不幸夭亡" << endl;

        this->HP = 7;
        this->mood = 10;
        this->fullness = 9;
        this->eng = 10;
        this->span = 10;

        this->status = 0;
        return 1;

    }
    system("pause");
    return 0;
}