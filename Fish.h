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
        HP = 6;
        span = 6;
        price = 15;
        fullness = 6;
    }
    ~fish()
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

void fish::showPet()
{
    cout << "       姓    名 ：" << this->name << endl;
    cout << "       健 康 值 ：" << this->HP << endl;
    cout << "       寿    命 ：" << this->span << endl;
    cout << "       体 力 值 : " << this->eng << endl;
    cout << "       心    情 ：" << this->mood << endl;
    cout << "       饱腹程度 ：" << this->fullness << endl;
    //注意
    if (this->HP < 2)
        cout << "注意！！        " << this->name << "吐泡泡的的速度明显变缓，身体在水中有时无法保持平衡（请及时带它去看医生）" << endl;
    if (this->eng < 2)
        cout << "注意！！        " << this->name << "虽然睁着眼睛，但是在水中保持了静止（请及时把它哄睡）" << endl;
    if (this->mood <= 4)
        cout << "注意！！        " << this->name << "无聊地贴着鱼缸壁，拒绝继续游动（请让它开心起来）" << endl;
    if (this->fullness <= 2)
        cout << "注意！！        " << this->name << "不断探头望向水面，似乎在期待着什么（请及时喂食）" << endl;
    if (this->fullness >= 7)
        cout << "注意！！        " << this->name << "脸涨得通红，对你提出如厕的需求（请及时帮它如厕并换水）" << endl;
    //常态
    if (this->HP >= 2)
        cout << "恭喜！！        " << this->name << "处于健康状态" << endl;
    if (this->eng >= 2)
        cout << "恭喜！！        " << this->name << "活力满满，在水中自由自在冲浪！" << endl;
    if (this->mood > 4)
        cout << "恭喜！！        " << this->name << "心情愉快，继续它的水中华尔兹~" << endl;
    if (this->fullness > 2 && this->fullness < 7)
        cout << "恭喜！！        " << this->name << "吃得饱饱的~" << endl;
}

void fish::Action()
{
    int c = 1;
    while (c != 0)
    {
        cout << "   鱼儿：" << this->name << endl;
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
void fish::Feed()
{
    if (this->fullness > 6)
    {
        this->fullness += 1;
        this->eng += 1;
        this->HP -= 1;
        this->mood -= 1;
        this->span -= 1;
        cout << "     “咯~~~”，您的鱼儿已经很撑了，肚子也变得圆鼓鼓的" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   您给鱼儿投喂了一些它最爱的水草~" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->fullness += 1;
    this->mood += 2;
    this->span -= 1;
    system("pause");
}

void fish::Drink()
{
    cout << this->name << "虽然在水中，但还是忍不住给你翻了个大白眼。内心： 小爷我天天住在水里需要你喂水吗？" << endl;
    cout << "-----------------------------------------------------" << endl;
    system("pause");
}


void fish::Play()
{
    if (this->eng < 2)
    {
        cout << "     您的鱼儿已经很累了，请不要与它玩耍了，让它休息一会儿，暂停营业吧！";
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   和鱼儿玩耍，鱼儿亲昵地亲了亲你的手" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 1;
    this->fullness -= 1;
    this->HP += 1;
    this->mood += 2;
    this->span -= 1;
    system("pause");
}

void fish::Sleep()
{
    this->HP += 2;
    this->eng += 4;
    this->fullness -= 2;
    this->span -= 1;
    system("pause");
}
//看医生函数
void fish::Doctor()
{
    this->HP = 6;
    this->mood = 10;
    this->fullness = 6;
    this->eng = 6;
    this->span -= 1;
    cout << "在兽医小姐姐的全面治疗下，您的鱼儿已经满血复活！以后要好好照顾它哦！" << endl;
    system("pause");
    return;
}
//如厕函数
void fish::Toilet()
{
    if (this->fullness > 6)
    {
        this->fullness -= 2;
        this->HP += 1;
        this->span -= 1;
        cout << "     随着你的鱼儿在水中暂时的停顿，水中突然多了许多的黑色颗粒物质……" << endl;
        cout << this->name << "转了个身就游走了，仿佛什么也没有发生。" << endl;
        system("pause");
    }
    else if (this->fullness >= 3)
    {
        this->fullness -= 1;
        this->HP += 1;
        this->span -= 1;
        cout << "水中出现轻微黑色颗粒……" << endl;
        system("pause");
    }
    else
    {
        cout << this->name << "完全不鸟你……" << endl;
        system("pause");
        return;
    }
}

int fish::Sold()
{
    this->status = 0;
    return this->price*1.2;
}

//判断是否存活
int fish::check()
{
    if (this->span <= 0)
    {
        cout << "          从某天开始，曾经看起来能实现“鱼翔浅底，万类霜天竞自由”的"<<this->name<<"也逐渐开始在水中久久伫立,成了你鱼塘中另一种类型的水草。" << endl;
        cout << "          你明白，它并非是在装深沉，并非是在为自己从未实现的“鲤鱼跃龙门”而遗憾，它或许还未放弃自己的雄心壮志，只是逐渐衰老的身体实在无法支持它这么做了。" << endl;
        cout << "          偶尔它也会在新来的小鱼身边吐两个泡泡，但绝非是为了争夺领地，相反，它是在勉励年轻的一代，光阴可贵!" << endl;
        cout << "          这天，它的鳃终于不再继续张合……" << endl;
        cout << endl;
        cout << "         【达成结局】： 寿终正寝" << endl;

        this->HP = 6;
        this->mood = 10;
        this->fullness = 6;
        this->eng = 10;
        this->span = 6;

        this->status = 0;
        return 1;
    }
    else if (this->fullness <= 0 || this->HP <= 0 || this->mood <= 0 || this->eng <= 0)
    {
        cout << "          看来您实在是没有什么当海王的资质，您似乎没有养鱼的能力！" << endl;
        cout << "          对不起，由于您的照顾不周，鱼儿最后撒手人寰，永远地离开了您！" << endl;
        cout << endl;
        cout << "         【达成结局】： 不幸夭亡" << endl;

        this->HP = 6;
        this->mood = 10;
        this->fullness = 6;
        this->eng = 10;
        this->span = 6;

        this->status = 0;
        return 1;
    }
    system("pause");
    return 0;
}
