/*����4.3 ���ӳ����̵�

Ҫ��ʵ�֣�
�����в�ͬ���͵ĵ��ӳ��
1.	ÿ�ֵ��ӳ�����ͨ����ʾ�������ı������Ҫ���ʾ�����磺�����ʡ����ǡ���������������ˡ����������ġ����������ĵȡ�
2.	��Ա�û�ͨ�����̲��������������ӳ������ʵʩι����ιˮ�������ϲ�����������ˣ������˯�������������ȶ����������������������µ��ӳ������������������������������ã������ӳ���ָ�����ޡ��������ޡ���
3.	���Թ����µĳ�������۳����
4.	����ͳ�Ƴ�����������ѯ����״̬���۸�
5.	Ϊ�����������ҵ�������ܡ�

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

static int sum = 0;          // ��������
static int money = 1000;     // ����ʽ�
static int cn = 0;           // è�������
static int dn = 0;           // ����������
static int rn = 0;           // ���õ�����
static int fn = 0;           // ���������

void Instruction();//˵��
int Menu();//�˵�
void Buy(vector<Pet*>);//����
void Action(vector<Pet*>);//����
void Sold(vector<Pet*>);//����
void Showinfo(vector<Pet*>);//չʾ��Ϣ
void SaveData(vector<Pet*>);//�浵
void ReadData(vector<Pet*>);//����

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
    cout << "   ======������Ϊһ�ҳ����ĵ�Ա��======" << endl;
    cout << endl;
    cout << "       ������ͨ�����������ȳ���н���        " << endl;
    cout << "   ���ǵ�����״������ȫȡ������������ǻ�" << endl;
    cout << "   ����Ҫ�������ǳԷ�����ˮ����ˣ��˯������" << endl;
    cout << "  ϣ���������������ȳ�����Ŀ��֣�ף��������죡  " << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "����" << endl;
    cout << "һ�����������ֵ" << endl;
    cout << "��ͬ���ﴦ������/����״̬������ֵ����ͬ������èè������Ľ������޲�����ͬ����Ϊ����������Ҫ�Լ���������չ����ǡ�" << endl;
    cout << "������ѡ���ѯ״̬��ͨ�������ǵķ�Ӧ�ͶԻ����ж���Ҫ���еĲ�����" << endl;
    cout << endl;
    cout << "��������������Ӱ��" << endl;
    cout << "ιʳ��     ���������ӣ��������ӣ�����ֵ/����������ӻ򽵵�" << endl;
    cout << "ιˮ��     ���������ӣ�����ֵ/����������ӻ򽵵�" << endl;
    cout << "��ˣ��     �������ӣ��������ӣ��������ͣ������н���" << endl;
    cout << "��˯��     �������ӣ��������ӣ������н���" << endl;
    cout << "��ҽ����   ����ֵ�ָ�����ʼ״̬" << endl;
    cout << "������ޣ� �����н��ͣ�����ֵ����" << endl;
    cout << endl;
    cout << "��������/���۳���" << endl;
    cout << "Ŀǰ�����������ɳ����������ܳ���10ֻ ����ÿ�ֳ��������ӵ��3ֻ" << endl;
    cout << "��ó�����Ҫ���ѽ�Ǯ���������ý�Ǯ�� �������������ʽ� " << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << endl;
}

int Menu()
{
    int c;
    cout << "��������Ҫ����ʲô������" << endl;
    cout << endl;
    cout << "       1�� -------------- �����ȳ�" << endl;
    cout << "       2�� -------------- �չ��ȳ�" << endl;
    cout << "       3�� -------------- ��ѯ״̬" << endl;
    cout << "       4�� -------------- �����ȳ�" << endl;
    cout << "       5�� -------------- ���浵��" << endl;
    cout << "       6�� -------------- ��ȡ����" << endl;
    cout << "       0�� -------------- �˳��˵�" << endl;
    cout << endl;
    cout << "===========================================" << endl;    //��������  ------  system("CLS ")
    cout << "       ��ǰ��" << money << endl;
    cout << "   ��ǰ����������" << sum << endl;
    cin >> c;
    system("cls");
    return c;
}

void Buy(vector<Pet*> p1)
{
    int c;
    cout << "==================================" << endl;
    cout << "�����õ���ӵ�������ȳ裿" << endl;
    cout << endl;
    cout << " 1--------------- Сè��               �۸�200" << endl;
    cout << " 2--------------- С����               �۸�150" << endl;
    cout << " 3--------------- С����               �۸� 30" << endl;
    cout << " 4--------------- С���               �۸� 15" << endl;
    cout << endl;
    cin >> c;
    system("cls");
    switch (c)
    {
    case 1:
    {
        if (cn == 3)
        {
            cout << "�Ѿ����㹻��èè��Ŷ" << endl;
            return;
        }
        if (money < 200)
        {
            cout << "�Բ����������㡭��" << endl;
            return;
        }
        cout << "==========================================================" << endl;
        cout << "         ��ϲ��һֻ�ɰ������������������̵�" << endl;
        cout << "   ������èè������ְɣ�" << endl;
        cat cat1;
        Pet* pet = &cat1;
        string s;
        cin >> s;
        pet->Name(s);
        pet->Status(1);
        system("cls");
        cout << "==============================================================" << endl;
        cout << "      " << pet->ShowName() << "ϲ��������֣�������������½ǣ�" << endl;
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
            cout << "��Ĺ����Ѿ��㹻����" << endl;
            return;
        }
        if (money < 150)
        {
            cout << "�Բ����������㡭��" << endl;
            return;
        }
        cout << "==============================================================" << endl;
        cout << "                ��ϲ��õ���һֻ�ɰ���������   " << endl;
        cout << "                   ����ô�ƺ�����" << endl;
        dog dog1;
        Pet* pet = &dog1;
        string s;
        cin >> s;
        pet->Name(s);
        pet->Status(1);
        system("cls");
        cout << "==============================================================" << endl;
        cout << "      " << pet->ShowName() << "ϲ��������֣�������������½ǣ�" << endl;
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
            cout << "��������Ѿ����ˣ�" << endl;
            return;
        }
        if (money < 30)
        {
            cout << "�Բ����������㡭��" << endl;
            return;
        }
        cout << "==============================================================" << endl;
        cout << "    ��ϲ��õ���һֻ�ɰ���С����" << endl;
        cout << "    ��ô�ƺ�����" << endl;
        rabbit rabbit1;
        Pet* pet = &rabbit1;
        string s;
        cin >> s;
        pet->Name(s);
        pet->Status(1);
        system("cls");
        cout << "       " << pet->ShowName() << endl;
        cout << "==============================================================" << endl;
        cout << "    ���ý����������֣�����ĬĬ�к��ܲ�" << endl;
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
            cout << "���������Ѿ����ˣ�" << endl;
            return;
        }
        if (money < 15)
        {
            cout << "�Բ����������㡭��" << endl;
            return;
        }
        cout << "==============================================================" << endl;
        cout << "    ��ϲ��õ���һ��С��" << endl;
        cout << "    ������ְ�" << endl;
        fish fish1;
        Pet* pet = &fish1;
        string s;
        cin >> s;
        pet->Name(s);
        pet->Status(1);
        system("cls");
        cout << "       " << pet->ShowName() << endl;
        cout << "==============================================================" << endl;
        cout << "    ���Ǹ���������֣�" << endl;
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
        cout << "��ѡ��һ���ȳ�" << endl;
        cout << " 1--------------- è��           " << endl;
        cout << " 2--------------- ����           " << endl;
        cout << " 3--------------- ����           " << endl;
        cout << " 4--------------- ���           " << endl;
        cout << " 0--------------- �˳�" << endl;
        cin >> C;
        switch (C)
        {
        case 1:
        {
            if (cn == 0)
            {
                cout << "�㻹û��è����" << endl;
                system("pause");
                break;
            }          
            for (vector<Pet* >::iterator iter = p2.begin(); iter != p2.end(); ++iter) 
            {
                if (( *iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 1)
                    continue;
                system("cls");
                cout << "           ѡ���������Ķ���" << endl;
                cout << "           è�䣺" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  ȷ��    ||   0  -----  ��һ����" << endl;
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
                cout << "�㻹û�й�����" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p2.begin(); iter != p2.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 2)
                    continue;
                system("cls");
                cout << "           ѡ���������Ķ���" << endl;
                cout << "           ������" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  ȷ��    ||   0  -----  ��һ����" << endl;
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
                cout << "�㻹û��������" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p2.begin(); iter != p2.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 3)
                    continue;
                system("cls");
                cout << "           ѡ���������Ķ���" << endl;
                cout << "           ���ã�" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  ȷ��    ||   0  -----  ��һ����" << endl;
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
                cout << "�㻹û�������" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p2.begin(); iter != p2.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 4)
                    continue;
                system("cls");
                cout << "           ѡ���������Ķ���" << endl;
                cout << "           �����" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  ȷ��    ||   0  -----  ��һ����" << endl;
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
        cout << "   ��ѡ��һ���ȳ�                " << endl;
        cout << " 1--------------- è��           " << endl;
        cout << " 2--------------- ����           " << endl;
        cout << " 3--------------- ����           " << endl;
        cout << " 4--------------- ���           " << endl;
        cout << " 0--------------- �˳�           " << endl;
        cin >> C;
        switch (C)
        {
        case 1:
        {
            if (cn == 0)
            {
                cout << "       ����û��è��" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p3.begin(); iter != p3.end(); ++iter)                    
            {
                if (( * iter) -> ShowStatus() == 0 || (*iter)->ShowKind() != 1)
                    continue;
                system("cls");
                cout << "           ѡ���������Ķ���" << endl;
                cout << "           è�䣺" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  ȷ��    ||   0  -----  ��һ����" << endl;
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
                cout << "       ����û�й���" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p3.begin(); iter != p3.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 2)
                    continue;
                system("cls");
                cout << "           ѡ���������Ķ���" << endl;
                cout << "           ������" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  ȷ��    ||   0  -----  ��һ����" << endl;
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
                cout << "       ����û������" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p3.begin(); iter != p3.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 3)
                    continue;
                system("cls");
                cout << "           ѡ���������Ķ���" << endl;
                cout << "           ���ã�" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  ȷ��    ||   0  -----  ��һ����" << endl;
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
                cout << "       ����û�����" << endl;
                system("pause");
                break;
            }
            for (vector<Pet* >::iterator iter = p3.begin(); iter != p3.end(); ++iter)
            {
                if ((*iter)->ShowStatus() == 0 || (*iter)->ShowKind() != 4)
                    continue;
                system("cls");
                cout << "           ѡ�������۵Ķ���" << endl;
                cout << "           �����" << (*iter)->ShowName() << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "           1  -----  ȷ��    ||   0  -----  ��һ����" << endl;
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
    cout << "��꼴��Ե~                                              " << endl;
    cout << "����С�ɰ��л�˵��" << endl;
    cout << "���ˣ���л���һ·��飡�㲻������ߵ�������Ҳ��úõ�Ŷ~" << endl;
    cout << "=========================================================" << endl;
    return;
}

void Showinfo(vector<Pet*> p4)
{
     cout << "            ������в�ѯ����" << endl;
    cout << "================================================================" << endl;
    cout << "                ����˻���" << money << endl;
    cout << "                ��ǰ����������" << sum << endl;
    cout << "                ��ǰè��������" << cn << endl;
    cout << "                ��ǰ����������" << dn << endl;
    cout << "                ��ǰ����������" << rn << endl;
    cout << "                ��ǰ���������" << fn << endl;
    cout << "================================================================" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------" << endl;
    for (int ss = 1; ss <= sum; )
    {
        for (vector<Pet* >::iterator iter = p4.begin(); iter != p4.end(); ++iter)
        {
            if ((*iter)->ShowStatus() == 0)
                continue;
            cout << "--���---  " << ss << "  ---------" << endl;
            (*iter)->showPet();
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << endl;       
    }
    if (sum == 0)
    {
        cout << "               ��ǰû�г���!" << endl;
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