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
    cout << "       ��    �� ��" << this->name << endl;
    cout << "       �� �� ֵ ��" << this->HP << endl;
    cout << "       ��    �� ��" << this->span << endl;
    cout << "       �� �� ֵ : " << this->eng << endl;
    cout << "       ��    �� ��" << this->mood << endl;
    cout << "       �����̶� ��" << this->fullness << endl;
    //ע��
    if (this->HP < 4)
        cout << "ע�⣡��        " << this->name << "ʮ������������һ�ţ���ʾ�Լ��е���������뼰ʱ����ȥ��ҽ����" << endl;
    if (this->eng < 3)
        cout << "ע�⣡��        " << this->name << "���۾���Ϊ�����Եø��Ӻ��ˣ��뼰ʱ������˯��" << endl;
    if (this->mood <= 4)
        cout << "ע�⣡��        " << this->name << "���������ں��ܲ��Աߣ�����������������" << endl;
    if (this->fullness <= 4)
        cout << "ע�⣡��        " << this->name << "�۰ͰͿ��������еĺ��ܲ�����ˮ����һ�أ��뼰ʱιʳ��" << endl;
    if (this->fullness >= 8)
        cout << "ע�⣡��        " << this->name << "���ǵ�ͨ�죬���������޵������뼰ʱ����ȥ������" << endl;
    //��̬
    if (this->HP >= 4)
        cout << "��ϲ����        " << this->name << "���ڽ���״̬" << endl;
    if (this->eng >= 3)
        cout << "��ϲ����        " << this->name << "�����������ı�������" << endl;
    if (this->mood > 4)
        cout << "��ϲ����        " << this->name << "������죬��Ը�����㸧��" << endl;
    if (this->fullness > 4 && this->fullness < 8)
        cout << "��ϲ����        " << this->name << "�Եñ�����~" << endl;
    return 0;
}

int rabbit::Action()
{
    int cost = 0;//���������Ļ���
    int c = 1;
    while (c != 0)
    {
        cout << "   ���ã�" << this->name << endl;
        cout << "   ��ѡ�����Ĳ�����" << endl;
        cout << "   1 -------------- ιʳ" << endl;
        cout << "   2 -------------- ��ˮ" << endl;
        cout << "   3 -------------- ��ˣ" << endl;
        cout << "   4 -------------- ����" << endl;
        cout << "   5 -------------- ��˯" << endl;
        cout << "   6 -------------- ���" << endl;
        cout << "   0 -------------- ����" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "   ����ֵ��" << this->eng << endl;
        cout << "   ����ֵ��" << this->HP << endl;
        cout << " Ԥ��������" << this->span << endl;
        cout << "   ����ֵ��" << this->mood << endl;
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
    cout << "       ��������Ͷι����ʳ�" << endl;
    cout << "       1�� -------------- ���ܲ�  (5r)" << endl;
    cout << "       2�� -------------- ��ײ�Ҷ(10r)" << endl;
    cout << "       3�� -------------- �ڰ�����(0r)" << endl;
    cout << "       0�� -------------- �˳�" << endl;
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
            cout << "     ����~~~�����������þ��ܳ��ˣ�����Ҳ���Բ�Ĺĵ�" << endl;
            cout << "-----------------------------------------------------" << endl;
            system("pause");
            return 5;
        }
        cout << "   ��������Ͷι��һЩ����ĺ��ܲ�~" << endl;
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
            cout << "     ����~~~�����������þ��ܳ��ˣ�����Ҳ���Բ�Ĺĵ�" << endl;
            cout << "-----------------------------------------------------" << endl;
            system("pause");
            return 5;
        }
        cout << "   ��ײ˺ܿ챻һɨ����~" << endl;
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
        cout << "   ����һ��֮��" << this->name << "��ֱ��ҧ�㣺���ˣ����Ӽ���Ҳ��ҧ���أ�" << endl;
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
        cout << "     ����~~~�����������þ��ܳ��ˣ�����Ҳ���Բ�Ĺĵ�" << endl;
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
        cout << "     ����~~~�������������Ѿ��ܳ��ˣ�����Ҳ���Բ�Ĺĵ�" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return 0;
    }
    cout << this->name << "������������ˮ" << endl;
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
        cout << this->name << "���������ţ�ò���Եò��Ǻ����飬�´���������ɡ�" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return 0;
    }
    cout << "   ���" << this->name << "����������Ϸ������ϲ�������Ϸ��" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 2;
    this->fullness -= 2;
    this->HP += 2;
    this->mood += 4;
    this->span -= 1;
    system("pause");
}
//��˯����
int rabbit::Sleep()
{
    this->HP += 2;
    this->eng += 4;
    this->fullness -= 2;
    this->span -= 1;
    system("pause");
    return 0;
}
//��ҽ������
int rabbit::Doctor()
{
    this->HP = 8;
    this->mood = 10;
    this->fullness = 7;
    this->eng = 10;
    this->span -= 1;
    cout << "����ҽС����ȫ�������£����������Ѿ���Ѫ����Ժ�Ҫ�ú��չ���Ŷ��(�ķ� 50r)" << endl;
    system("pause");
    return 20;
}
//��޺���
int rabbit::Toilet()
{
    if (this->fullness > 8)
    {
        this->fullness -= 4;
        this->HP += 2;
        this->span -= 1;
        cout << "��~~~    ����һкǧ��,�������졭��" << endl;
        cout << this->name << "¶����������������һЦ���������˸���" << endl;
        system("pause");
    }
    else if (this->fullness >= 4)
    {
        this->fullness -= 2;
        this->HP += 1;
        this->span -= 1;
        cout << "������������ĳЩ�¡�" << endl;
        system("pause");
    }
    else
    {
        cout << this->name << "ãȻ�ؿ����㣬��ʾ�Լ���û�����������󡭡�" << endl;
        system("pause");
        return 0;
    }
}

//���ۺ���
int rabbit::Sold()
{
    this->status = 0;
    return this->price * 1.5;

}

//�ж��Ƿ���
int rabbit::check()
{
    if (this->span <= 0)
    {
        cout << "          ��ĳ�쿪ʼ��" << this->name << "��������ǰһ�������ı�����������ʱ����ѡ�������������Զ����" << endl;
        cout << "          ������ʱ���е��ڣ�δ���Լ���ǿ��׳��ʱ��Ϊ�Լ��������������ѣ�Ҳ��Ӯ��һ�������ĳƺš�"<<endl;
        cout << "          ÿÿ�뵽���£������۾��ͻ���ϼ��֡�������~" << endl;
        cout << "          ������Σ���������ĳ��������۾�����" << endl;
        cout << endl;
        cout << "         ����ɽ�֡��� ��������" << endl;       
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
        cout << "          ��С���ӹԹԣ����Ŷ������������Ǵ������" << endl;
        cout << "          �Բ������������չ˲��ܣ��������������徣���Զ���뿪������" << endl;
        cout << endl;
        cout << "         ����ɽ�֡��� ����ز��" << endl;

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