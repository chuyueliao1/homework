/*任务4.3 电子宠物商店

要求实现：
店内有不同类型的电子宠物。
1.	每种电子宠物能通过显示出来的文本提出需要或表示情绪如：饿、渴、饱涨、困、不舒服、高兴、生气、伤心、绝望、无聊等。
2.	店员用户通过键盘操作“饲养”电子宠物，给它实施喂饭、喂水、带它上厕所、陪它玩耍、哄它睡觉，带他看病等动作。当“饲养”不当导致电子宠物“死亡”，程序结束。“饲养”良好，当电子宠物活到指定年限“寿终正寝”。
3.	可以购买新的宠物或者售出宠物。
4.	可以统计宠物数量、查询宠物状态、价格。
5.	为店主设计其它业务或管理功能。

*/
#include <iostream>
#include <fstream>
#include <string>
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Pet.h"
#include "Rabbit.h"
#include<vector>
using namespace std;

static int sum = 0;          // 宠物总数
static int money = 1000;     // 你的资金
static int cn = 0;           // 猫咪的数量
static int dn = 0;           // 狗狗的数量
static int rn = 0;           // 兔兔的数量
static int fn = 0;           // 鱼儿的数量

void Instruction();//说明
int Menu();//菜单
void Buy(vector<Pet*>);//购买
void Action(vector<Pet*>);//互动
void Sold(vector<Pet*>);//出售
void Showinfo(vector<Pet*>);//展示信息
void SaveData(vector<Pet*>);//存档
void ReadData(vector<Pet*>);//读档

int main()
{
	vector<Pet*> p;
    int C = 1;
    Instruction();
    system("pause");
    while (C != 0)
    {
        system("cls");
        C = Menu();
        switch (C)
        {
        case 1: Buy(p);        break;
        case 2: Action(p);                         break;
        case 3: Showinfo(p);                                   break;
        case 4: Sold(p);                           break;
        case 5: SaveData(p);                       break;
        case 6: ReadData(p);                       break;
        case 0: system("CLS");                                  break;
        }
        system("pause");
        cout << endl;
        cout << "=========================================================" << endl;
    }
}

void Instruction()
{
    cout << "   ======您将成为一家宠物店的店员！======" << endl;
    cout << endl;
    cout << "       您可以通过键盘来和萌宠进行交互        " << endl;
    cout << "   它们的生理状况将完全取决于您的认真呵护" << endl;
    cout << "   您需要帮助它们吃饭，喝水，玩耍，睡觉……" << endl;
    cout << "  希望您能享受养育萌宠带来的快乐！祝您体验愉快！  " << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "规则：" << endl;
    cout << "一、宠物的属性值" << endl;
    cout << "不同宠物处于良好/不良状态的属性值不相同，例如猫猫和鱼儿的健康下限并不相同，作为店主的您需要自己摸索如何照顾它们。" << endl;
    cout << "您可以选择查询状态，通过宠物们的反应和对话来判断需要进行的操作。" << endl;
    cout << endl;
    cout << "二、操作带来的影响" << endl;
    cout << "喂食：     饱腹感增加，体力增加，健康值/心情可能增加或降低" << endl;
    cout << "喂水：     饱腹感增加，健康值/心情可能增加或降低" << endl;
    cout << "玩耍：     健康增加，心情增加，体力降低，饱腹感降低" << endl;
    cout << "哄睡：     体力增加，健康增加，饱腹感降低" << endl;
    cout << "看医生：   属性值恢复到初始状态" << endl;
    cout << "帮助如厕： 饱腹感降低，健康值增加" << endl;
    cout << endl;
    cout << "三、购买/出售宠物" << endl;
    cout << "目前店内所能容纳宠物总数不能超过10只 ，且每种宠物最多能拥有3只" << endl;
    cout << "获得宠物需要花费金钱，出售则获得金钱。 请合理分配您的资金 " << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << endl;
}

int Menu()
{
    int c;
    cout << "请问您想要进行什么操作？" << endl;
    cout << endl;
    cout << "       1、 -------------- 购买萌宠" << endl;
    cout << "       2、 -------------- 照顾萌宠" << endl;
    cout << "       3、 -------------- 查询状态" << endl;
    cout << "       4、 -------------- 出售萌宠" << endl;
    cout << "       5、 -------------- 储存档案" << endl;
    cout << "       6、 -------------- 读取档案" << endl;
    cout << "       0、 -------------- 退出菜单" << endl;
    cout << endl;
    cout << "===========================================" << endl;    //清屏函数  ------  system("CLS ")
    cout << "       当前余额：" << money << endl;
    cout << "   当前宠物数量：" << sum << endl;
    cin >> c;
    system("cls");
    return c;
}

void Buy(vector<Pet*> p1)
{
    int c;
    cout << "==================================" << endl;
    cout << "你想让店里拥有哪种萌宠？" << endl;
    cout << endl;
    cout << " 1--------------- 小猫咪               价格：200" << endl;
    cout << " 2--------------- 小狗狗               价格：150" << endl;
    cout << " 3--------------- 小兔兔               价格： 30" << endl;
    cout << " 4--------------- 小鱼儿               价格： 15" << endl;
    cout << endl;
    cin >> c;
    system("cls");
    switch (c)
    {
    case 1:
    {
        if (cn == 3)
        {
            cout << "已经有足够的猫猫了哦" << endl;
            return;
        }
        if (money < 200)
        {
            cout << "对不起，您的余额不足……" << endl;
            return;
        }
        cout << "==========================================================" << endl;
        cout << "         恭喜！一只可爱的喵喵将放入您的商店" << endl;
        cout << "   给您的猫猫起个名字吧！" << endl;
        cat cat1;
        Pet* pet = &cat1;
        string s;
        cin >> s;
        pet->Name(s);
        pet->Status(1);
        system("cls");
        cout << "==============================================================" << endl;
        cout << "      " << pet->ShowName() << "喜欢这个名字，并挠了挠你的衣角！" << endl;
        cout << "==============================================================" << endl;
        sum += 1;
        money -= pet->ShowPrice();
        cn += 1;
        p1.push_back(pet);
        break;
    }
    case 2:
    {
        if (dn == 3)
        {
            cout << "你的狗狗已经足够多了" << endl;
            return;
        }
        if (money < 150)
        {
            cout << "对不起，您的余额不足……" << endl;
            return;
        }
        cout << "==============================================================" << endl;
        cout << "                恭喜你得到了一只可爱的汪星人   " << endl;
        cout << "                   该怎么称呼它？" << endl;
        dog dog1;
        Pet* pet = &dog1;
        string s;
        cin >> s;
        pet->Name(s);
        pet->Status(1);
        system("cls");
        cout << "==============================================================" << endl;
        cout << "      " << pet->ShowName() << "喜欢这个名字，并挠了挠你的衣角！" << endl;
        cout << "==============================================================" << endl;
        sum += 1;
        money -= pet->ShowPrice();
        dn += 1;
        p1.push_back(pet);
        break;
    }
    case 3:
    {
        if (rn == 3)
        {
            cout << "你的兔兔已经满了！" << endl;
            return;
        }
        if (money < 30)
        {
            cout << "对不起，您的余额不足……" << endl;
            return;
        }
        cout << "==============================================================" << endl;
        cout << "    恭喜你得到了一只可爱的小兔子" << endl;
        cout << "    怎么称呼它？" << endl;
        rabbit rabbit1;
        Pet* pet = &rabbit1;
        string s;
        cin >> s;
        pet->Name(s);
        pet->Status(1);
        system("cls");
        cout << "       " << pet->ShowName() << endl;
        cout << "==============================================================" << endl;
        cout << "    兔兔接受了新名字，继续默默啃胡萝卜" << endl;
        cout << "==============================================================" << endl;
        sum += 1;
        money -= pet->ShowPrice();
        rn += 1;
        p1.push_back(pet);
        break;
    }
    case 4:
    {
        if (fn == 3)
        {
            cout << "您的鱼塘已经满了！" << endl;
            return;
        }
        if (money < 15)
        {
            cout << "对不起，您的余额不足……" << endl;
            return;
        }
        cout << "==============================================================" << endl;
        cout << "    恭喜你得到了一条小鱼" << endl;
        cout << "    起个名字吧" << endl;
        fish fish1;
        Pet* pet = &fish1;
        string s;
        cin >> s;
        pet->Name(s);
        pet->Status(1);
        system("cls");
        cout << "       " << pet->ShowName() << endl;
        cout << "==============================================================" << endl;
        cout << "    真是个不错的名字！" << endl;
        cout << "==============================================================" << endl;
        sum += 1;
        money -= pet->ShowPrice();
        fn += 1;
        p1.push_back(pet);
        break;
    }
    }
}

void Action(vector<Pet*> p2)
{
    int C = 1;
    int cc;
    while (C != 0)
    {

        system("cls");
        cout << "请选择一类萌宠" << endl;
        cout << " 1--------------- 猫咪           " << endl;
        cout << " 2--------------- 狗狗           " << endl;
        cout << " 3--------------- 兔兔           " << endl;
        cout << " 4--------------- 鱼儿           " << endl;
        cout << " 0--------------- 退出" << endl;
        cin >> C;
        switch (C)
        {
        case 1:
        {
            if (cn == 0)
            {
                cout << "你还没有猫咪呢" << endl;
                system("pause");
                break;
            }          
            for (vector<Pet* >::iterator iter = p2.begin(); iter != p2.end(); ++iter) 
            {
                if (( *iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 1)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           猫咪：" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money -= (*iter)->Action();
                    if ((*iter)->ShowStatus() == 0)
                    {
                        cn -= 1;
                        sum -= 1;
                    }
                }

            }
            break;
        }
        case 2:
        {
            if (dn == 0)
            {
                cout << "你还没有狗狗呢" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p2.begin(); iter != p2.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 2)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           狗狗：" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money -= (*iter)->Action();
                }
                if ((*iter)->ShowStatus() == 0)
                {
                    dn -= 1;
                    sum -= 1;
                }
            }
            break;
        }
        case 3:
        {
            if (rn == 0)
            {
                cout << "你还没有兔兔呢" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p2.begin(); iter != p2.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 3)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           兔兔：" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money -= (*iter)->Action();
                }
                if ((*iter)->ShowStatus() == 0)
                {
                    rn -= 1;
                    sum -= 1;
                }
            }
            break;
        }
        case 4:
        {
            if (fn == 0)
            {
                cout << "你还没有鱼儿呢" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p2.begin(); iter != p2.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 4)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           鱼儿：" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money -= (*iter)->Action();
                }
                if ((*iter)->ShowStatus() == 0)
                {
                    fn -= 1;
                    sum -= 1;
                }
            }
            break;
        }
        }

    }
}

void Sold(vector<Pet*> p3)
{
    int C = 1;
    int cc;
    while (C != 0)
    {
        system("cls");
        cout << "   请选择一类萌宠                " << endl;
        cout << " 1--------------- 猫咪           " << endl;
        cout << " 2--------------- 狗狗           " << endl;
        cout << " 3--------------- 兔兔           " << endl;
        cout << " 4--------------- 鱼儿           " << endl;
        cout << " 0--------------- 退出           " << endl;
        cin >> C;
        switch (C)
        {
        case 1:
        {
            if (cn == 0)
            {
                cout << "       您并没有猫咪" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p3.begin(); iter != p3.end(); ++iter)                    
            {
                if (( * iter) -> ShowStatus() == 0 || (*iter)->ShowKind() != 1)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           猫咪：" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += (*iter)->Sold();
                    sum -= 1;
                    cn -= 1;
                }
            }
            break;
        }
        case 2:
        {
            if (dn == 0)
            {
                cout << "       您并没有狗狗" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p3.begin(); iter != p3.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 2)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           狗狗：" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += (*iter)->Sold();
                    sum -= 1;
                    dn -= 1;
                }
            }
            break;
        }
        case 3:
        {
            if (rn == 0)
            {
                cout << "       您并没有兔兔" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p3.begin(); iter != p3.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 3)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           兔兔：" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += (*iter)->Sold();
                    sum -= 1;
                    rn -= 1;
                }
            }
            break;
        }
        case 4:
        {
            if (fn == 0)
            {
                cout << "       您并没有鱼儿" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p3.begin(); iter != p3.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 4)
                    continue;
                system("cls");
                cout << "           选择您出售的对象" << endl;
                cout << "           鱼儿：" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += (*iter)->Sold();
                    sum -= 1;
                    fn -= 1;
                }
            }
            break;
        }
        }
    }
    cout << "=========================================================" << endl;
    cout << "相逢即是缘~                                              " << endl;
    cout << "您的小可爱有话说：" << endl;
    cout << "主人，感谢你的一路相伴！你不在我身边的日子我也会好好的哦~" << endl;
    cout << "=========================================================" << endl;
    return;
}

void Showinfo(vector<Pet*> p4)
{
     cout << "            下面进行查询操作" << endl;
    cout << "================================================================" << endl;
    cout << "                你的账户余额：" << money << endl;
    cout << "                当前宠物数量：" << sum << endl;
    cout << "                当前猫咪数量：" << cn << endl;
    cout << "                当前狗狗数量：" << dn << endl;
    cout << "                当前兔兔数量：" << rn << endl;
    cout << "                当前鱼儿数量：" << fn << endl;
    cout << "================================================================" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------" << endl;
    for (int ss = 1; ss <= sum; )
    {
        for (vector<Pet* >::iterator iter = p4.begin(); iter != p4.end(); ++iter)
        {
            if ((*iter)->ShowStatus() == 0)
                continue;
            cout << "--编号---  " << ss << "  ---------" << endl;
            (*iter)->showPet();
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << endl;       
    }
    if (sum == 0)
    {
        cout << "               当前没有宠物!" << endl;
        system("pause");
    }
    cout << endl;
}

void SaveData(vector<Pet*> p5)
{
    ofstream Data("Database.txt");
    fstream file("Database.txt", ios::out);
    Data << sum << " " << money << " " << cn << " " << dn << " " << rn << " " << fn << endl;   
    for (vector<Pet* >::iterator iter = p5.begin(); iter != p5.end(); ++iter)
        Data << (*iter)->ShowHP() << " " << (*iter)->ShowEng() << " " << (*iter)->ShowFullness() << " " << (*iter)->ShowMood() << " " << (*iter)->ShowName() << " " << (*iter)->ShowPrice() << " " << (*iter)->ShowSpan() << " " << (*iter)->ShowStatus() << " " << endl;
    Data.close();
}

void ReadData(vector<Pet*> p6)
{

    ifstream ReadData("Database.txt");
    ReadData >> sum >> money >> cn >> dn >> rn >> fn;
    for (vector<Pet* >::iterator iter = p6.begin(); iter != p6.end(); ++iter)
        ReadData >> (*iter)->HP >> (*iter)->eng >> (*iter)->fullness >> (*iter)->mood >> (*iter)->name >> (*iter)->price >> (*iter)->span >> (*iter)->status;
    ReadData.close();
}