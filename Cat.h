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
        price = 200;
        HP = 10;
        span = 9;//传说猫有九条命
    }
    ~cat()                         
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
//显示宠物基本信息
void cat::showPet()
{
    cout << "       姓    名 ：" << this->name << endl;
    cout << "       健 康 值 ：" << this->HP << endl;
    cout << "       寿    命 ：" << this->span << endl;
    cout << "       体 力 值 : " << this->eng << endl;
    cout << "       心    情 ：" << this->mood << endl;
    cout << "       饱腹程度 ：" << this->fullness << endl;
//注意
    if (this->HP < 3)
        cout << "注意！！        " << this->name << "十分虚弱地缩成一团，表示自己感到不舒服（请及时带它去看医生）" << endl;
    if (this->eng < 4)
        cout << "注意！！        " << this->name << "睡眼惺忪，表示自己感到困倦了（请及时把它哄睡）" << endl;
    if (this->mood <= 4)
        cout << "注意！！        " << this->name << "气呼呼地躲在角落不想理你（请让它开心起来）" << endl;
    if (this->fullness <= 4)
        cout << "注意！！        " << this->name << "眼巴巴看着你手中的鱼干，眼神表示自己好饿（请及时喂食）" << endl;
    if (this->fullness >= 9)
        cout << "注意！！        " << this->name << "脸涨得通红，对你提出如厕的需求（请及时带它去厕所）" << endl;
//常态
    if (this->HP >= 2)
        cout << "恭喜！！        " << this->name << "处于健康状态" << endl;
    if (this->eng >= 4)
        cout << "恭喜！！        " << this->name << "活力满满，正追着一只电子鼠玩耍" << endl;
    if (this->mood > 4)
        cout << "恭喜！！        " << this->name << "心情愉快，对你喵喵两声~" << endl;
    if (this->fullness > 4&&this->fullness<9)
        cout << "恭喜！！        " << this->name << "吃得饱饱的~" << endl;
    
}
//对宠物操作
void cat::Action()
{
    int c = 1;
    while (c != 0)
    {
        cout << "   猫咪：" << this->name << endl;
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
//喂食宠物
void cat::Feed()
{
    if (this->fullness > 8)
    {
        this->fullness += 1;
        this->eng += 1;
        this->HP -= 1;
        this->mood -= 1;
        this->span -= 1;
        cout << "     “咯~~~”，您的猫咪已经很撑了，肚子也变得圆鼓鼓的" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   您给猫咪投喂了一些它最爱的小鱼~" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->fullness += 2;
    this->mood += 2;
    this->span -= 1;
    system("pause");
}
//给宠物喝水
void cat::Drink()
{
    if (this->fullness > 8)
    {
        this->fullness += 1;
        this->HP -= 1;
        this->mood -= 1;
        this->span -= 1;
        cout << "     “咯~~~”，您的猫咪已经很撑了，肚子也变得圆鼓鼓的" << endl;
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
//陪宠物玩
void cat::Play()
{
    if (this->eng < 3)
    {
        cout << this->name << "趴在猫窝并表示不想动。" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   陪伴" << this->name << "玩毛线球，猫猫表示一定要扑到球球" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 2;
    this->fullness -= 2;
    this->HP += 2;
    this->mood += 4;
    this->span -= 1;
    system("pause");
}
//哄睡函数
void cat::Sleep()
{
    this->HP += 2;
    this->eng += 4;
    this->fullness -= 2;
    this->span -= 1;
    system("pause");
}
//看医生函数
void cat::Doctor()
{
    this->HP = 4;
    this->mood = 10;
    this->fullness = 8;
    this->eng = 10;
    this->span -= 1;
    cout << "在兽医小姐姐的全面治疗下，您的猫猫已经满血复活！以后要好好照顾它哦！" << endl;
    system("pause");
    return;
}
//如厕函数
void cat::Toilet()
{
    if (this->fullness > 8)
    {
        this->fullness -= 4;
        this->HP += 2;
        this->span -= 1;
        cout << "轰~~~    猫猫一泻千里,酣畅淋漓……" << endl;
        cout << this->name << "害羞的躲回了自己的小窝，你认真清理干净现场" << endl;
        system("pause");
    }
    else if(this->fullness >=4)
    {
        this->fullness -= 2;
        this->HP += 1;
        this->span -= 1;
        cout << "猫猫在猫砂处完成了一切" << endl;
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
int cat::Sold()
{
    this->status = 0;
    return this->price*3;

}

//判断是否存活
int cat::check()
{
    if (this->span <= 0)
    {
        cout << "          从某天开始，" << this->name << "不再拥有从前光亮的皮毛，行动也逐渐变得愈发迟缓。" << endl;
        cout << "          这天，它最后一次爬上你的膝盖，缩进你的怀里，恋恋不舍地蹭蹭你，而后略显蹒跚地从你身上下去。" << endl;
        cout << "          夕阳下，你一生要强的猫猫用最后的优雅迈入自己熟悉的小窝,而后永远的闭上了眼睛……" << endl;
        cout << "          你知道，你的猫大侠只是回到了属于它的喵星球。" << endl;
        cout << endl;
        cout << "         【达成结局】： 寿终正寝" << endl;
        
        this->HP = 10;
        this->mood = 10;
        this->fullness = 8;
        this->eng = 10;
        this->span = 9;

        this->status = 0;
        return 1;
    }
    else if (this->fullness <= 0 || this->HP <= 0 || this->mood <= 0 || this->eng <= 0)
    {
        cout << "          或许是一念之差，有些事您没有尽到义务。" << endl;
        cout << "          由于您的照顾不周，小猫最后撒手人寰，永远地离开了您！" << endl;
        cout << "----------虽然传说猫有九条命，但是上天还是坚定地选择收回您的猫猫，下次还是准备好再当主人吧。" << endl;
        cout << endl;
        cout << "         【达成结局】： 不幸夭亡" << endl;

        this->HP = 10;
        this->mood = 10;
        this->fullness = 8;
        this->eng = 10;
        this->span = 9;

        this->status = 0;
        return 1;
    }   
    system("pause");
    return 0;
}