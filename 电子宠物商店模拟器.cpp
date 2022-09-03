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
using namespace std;

static int sum = 0;          // 宠物总数
static int money = 1000;     // 你的资金
static int cn = 0;           // 猫咪的数量
static int dn = 0;           // 狗狗的数量
static int rn = 0;           // 兔兔的数量
static int fn = 0;           // 鱼儿的数量

void Instruction();//说明
int Menu();//菜单
void Buy(cat&, dog&, rabbit&, fish&);//购买
void Action(cat[], dog[], rabbit[], fish[]);//互动
void Sold(cat[], dog[], rabbit[], fish[]);//出售
void Showinfo(cat[], dog[], rabbit[], fish[]);//展示信息
void SaveData(cat[], dog[], rabbit[], fish[]);//存档
void ReadData(cat[], dog[], rabbit[], fish[]);//读档


//主程序
int main()
{
    cat c[10];
    dog d[10];
    rabbit r[10];
    fish f[10];
    int C = 1;
    Instruction();
    system("pause");
    while (C != 0)
    {
        system("cls");
        C = Menu();
        switch (C)
        {
        case 1: Buy(c[cn], d[dn], r[rn], f[fn]);      break;
        case 2: Action(c, d, r, f);                         break;
        case 3: Showinfo(c, d, r, f);                                   break;
        case 4: Sold(c, d, r, f);                           break;
        case 5: SaveData(c, d, r, f);                       break;
        case 6: ReadData(c, d, r, f);                       break;
        case 0: system("CLS");                                  break;
        }
        system("pause");
        cout << endl;
        cout << "=========================================================" << endl;
    }
}


//说明
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
    cout << "规则："<<endl;
    cout << "一、宠物的属性值" << endl;
    cout << "不同宠物处于良好/不良状态的属性值不相同，例如猫猫和鱼儿的健康下限并不相同，作为店主的您需要自己摸索如何照顾它们。" << endl;
    cout << "您可以选择查询状态，通过宠物们的反应和对话来判断需要进行的操作。" << endl;
    cout << endl;
    cout << "二、操作带来的影响" << endl;
    cout << "喂食：     饱腹感增加，体力增加，健康值/心情可能增加或降低"<<endl;
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

//菜单函数
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

//购买函数
void Buy(cat& c1, dog& d1, rabbit& r1, fish& f1)
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
        cin >> c1.name;
        c1.status = 1;
        system("cls");
        cout << "==============================================================" << endl;
        cout << "      "<<c1.name<<"喜欢这个名字，并挠了挠你的衣角！" << endl;
        cout << "==============================================================" << endl;
        sum += 1;
        money -= c1.price;
        cn += 1;
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
        cin >> d1.name;
        d1.status = 1;
        system("cls");
        cout << "==============================================================" << endl;
        cout << "      " << d1.name << "喜欢这个名字，并挠了挠你的衣角！" << endl;
        cout << "==============================================================" << endl;
        sum += 1;
        money -= d1.price;
        dn += 1;
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
        cin >> r1.name;
        r1.status = 1;
        system("cls");
        cout << "       " << r1.name << endl;
        cout << "==============================================================" << endl;
        cout << "    兔兔接受了新名字，继续默默啃胡萝卜" << endl;
        cout << "==============================================================" << endl;
        sum += 1;
        money -= r1.price;
        rn += 1;
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
        cin >> f1.name;
        f1.status = 1;
        system("cls");
        cout << "       " << f1.name << endl;
        cout << "==============================================================" << endl;
        cout << "    真是个不错的名字！" << endl;
        cout << "==============================================================" << endl;
        sum += 1;
        money -= f1.price;
        fn += 1;
        break;
    }
    }
}

//操作函数
void Action(cat c2[], dog d2[], rabbit r2[], fish f2[])
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
            for (int i = 0; i < cn; i++)
            {
                if (c2[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           猫咪：" << c2[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money-=c2[i].Action();
                    if (c2[i].status == 0)
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
            for (int i = 0; i < dn; i++)
            {
                if (d2[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           狗狗：" << d2[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money-=d2[i].Action();
                }
                if (d2[i].status == 0)
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
            for (int i = 0; i < rn; i++)
            {
                if (r2[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           兔兔：" << r2[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money-=r2[i].Action();
                }
                if (r2[i].status == 0)
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
            for (int i = 0; i < fn; i++)
            {
                if (f2[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           鱼儿：" << f2[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money-=f2[i].Action();
                }
                if (f2[i].status == 0)
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

//出售函数
void Sold(cat c3[], dog d3[], rabbit r3[], fish f3[])
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
            for (int i = 0; i < cn; i++)
            {
                if (c3[i].status == 0)
                    break;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           猫咪：" << c3[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += c3[i].Sold();
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
            for (int i = 0; i < dn; i++)
            {
                if (d3[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           狗狗：" << d3[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += d3[i].Sold();
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
            for (int i = 0; i < rn; i++)
            {
                if (r3[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您操作的对象" << endl;
                cout << "           兔兔：" << r3[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += r3[i].Sold();
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
            for (int i = 0; i < fn; i++)
            {
                if (f3[i].status == 0)
                    continue;
                system("cls");
                cout << "           选择您出售的对象" << endl;
                cout << "           鱼儿：" << f3[i].name << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  确定    ||   0  -----  下一个；" << endl;
                cout << "---------------------------------------------------------" << endl;
                cin >> cc;
                if (cc == 1)
                {
                    system("cls");
                    money += f3[i].Sold();
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
    cout << "您的小可爱有话说："                                        << endl;
    cout << "主人，感谢你的一路相伴！你不在我身边的日子我也会好好的哦~" << endl;
    cout << "=========================================================" << endl;
    return;
}

//查询函数
void Showinfo(cat c[], dog d[], rabbit r[], fish f[])
{
    cout << "            下面进行查询操作" << endl;
    cout << "================================================================" << endl;
    cout << "                你的账户余额：" << money << endl;
    cout << "                当前宠物数量：" << sum << endl;
    cout << "================================================================" << endl;
    cout << "----------------------------------------------------------------" << endl;
    for (int ss = 1; ss <= sum; )
    {
        cout << "       当前猫咪数量：" << cn << endl;
        for (int i = 0; i < 10; i++, ss++)
        {
            if (c[i].status == 0)
                continue;
            cout << "--编号---  " << ss << "  ---------" << endl;
            c[i].showPet();
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << endl;
        cout << "================================================================" << endl;
        cout << "       当前狗狗数量：" << dn << endl;
        for (int i1 = 0; i1 < 10; i1++, ss++)
        {
            if (d[i1].status == 0)
                continue;
            cout << "--编号---  " << ss << "  ---------" << endl;
            d[i1].showPet();
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << endl;
        cout << "================================================================" << endl;
        cout << "       当前兔兔数量：" << rn << endl;
        for (int i2 = 0; i2 < 10; i2++, ss++)
        {
            if (r[i2].status == 0)
                continue;
            cout << "--编号---  " << ss << "  ---------" << endl;
            r[i2].showPet();
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << endl;
        cout << "================================================================" << endl;
        cout << "       当前鱼儿数量：" << fn << endl;
        for (int i3 = 0; i3 < 10; i3++, ss++)
        {
            if (f[i3].status == 0)
                continue;
            cout << "--编号---  " << ss << "  ---------" << endl;
            f[i3].showPet();
            cout << "----------------------------------------------------------------" << endl;
        }
    }
    if (sum == 0)
    {
        cout << "               当前没有宠物!" << endl;
        system("pause");
    }
    cout << endl;
}

//存档
void SaveData(cat c4[], dog d4[], rabbit r4[], fish f4[])
{
    ofstream Data("Database.txt");
    fstream file("Database.txt", ios::out);
    Data << sum <<" "<< money <<" "<< cn <<" "<< dn <<" "<< rn <<" "<< fn << endl;
    int n;
    for (n = 0;n < cn; n++)
        Data << c4[n].HP << " " << c4[n].eng << " " << c4[n].fullness << " " << c4[n].mood << " " << c4[n].name << " " << c4[n].price << " " << c4[n].span << " " << c4[n].status << " " << endl;
    for (n = 0; n < dn; n++)
        Data << d4[n].HP << " " << d4[n].eng << " " << d4[n].fullness << " " << d4[n].mood << " " << d4[n].name << " " << d4[n].price << " " << d4[n].span << " " << d4[n].status << " " << endl;
    for (n = 0; n < rn; n++)
        Data << r4[n].HP << " " << r4[n].eng << " " << r4[n].fullness << " " << r4[n].mood << " " << r4[n].name << " " << r4[n].price << " " << r4[n].span << " " << r4[n].status << " " << endl;
    for (n = 0; n < fn; n++)
        Data << f4[n].HP << " " << f4[n].eng << " " << f4[n].fullness << " " << f4[n].mood << " " << f4[n].name << " " << f4[n].price << " " << f4[n].span << " " << f4[n].status << " " << endl;
    Data.close();
 }

//读档
void ReadData(cat c5[], dog d5[], rabbit r5[], fish f5[])
{
    ifstream ReadData("Database.txt");
    ReadData >> sum >> money >> cn >> dn >> rn >> fn;
    int n;
    for (n = 0; n < cn; n++)
        ReadData >> c5[n].HP >> c5[n].eng >> c5[n].fullness >> c5[n].mood >> c5[n].name >> c5[n].price >> c5[n].span >> c5[n].status ;
    for (n = 0; n < dn; n++)
        ReadData >> d5[n].HP >> d5[n].eng >> d5[n].fullness >> d5[n].mood >> d5[n].name >> d5[n].price >> d5[n].span >> d5[n].status ;
    for (n = 0; n < rn; n++)
        ReadData >> r5[n].HP >> r5[n].eng >> r5[n].fullness >> r5[n].mood >> r5[n].name >> r5[n].price >> r5[n].span >> r5[n].status;
    for (n = 0; n < fn; n++)
        ReadData >> f5[n].HP >> f5[n].eng >> f5[n].fullness >> f5[n].mood >> f5[n].name >> f5[n].price >> f5[n].span >> f5[n].status ;
    ReadData.close();
}

