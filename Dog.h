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
    cout << "       ��    �� ��" << this->name << endl;
    cout << "       �� �� ֵ ��" << this->HP << endl;
    cout << "       ��    �� ��" << this->span << endl;
    cout << "       �� �� ֵ : " << this->eng << endl;
    cout << "       ��    �� ��" << this->mood << endl;
    cout << "       �����̶� ��" << this->fullness << endl;
    //ע��
    if (this->HP < 2)
        cout << "ע�⣡��        " << this->name << "ʮ������������һ�ţ���ʾ�Լ��е���������뼰ʱ����ȥ��ҽ����" << endl;
    if (this->eng < 3)
        cout << "ע�⣡��        " << this->name << "˯�����죬��ʾ�Լ��е������ˣ��뼰ʱ������˯��" << endl;
    if (this->mood <= 4)
        cout << "ע�⣡��        " << this->name << "��ͷɥ�������ʲ�ֹ���Ե�ʮ�ִ�ͷɥ��������������������" << endl;
    if (this->fullness <= 6)
        cout << "ע�⣡��        " << this->name << "�۰ͰͿ��������еĹ�ͷ����ˮ����һ�أ��뼰ʱιʳ��" << endl;
    if (this->fullness >= 10)
        cout << "ע�⣡��        " << this->name << "���ǵ�ͨ�죬���������޵������뼰ʱ����ȥ������" << endl;
    //��̬
    if (this->HP >= 2)
        cout << "��ϲ����        " << this->name << "���ڽ���״̬" << endl;
    if (this->eng >= 3)
        cout << "��ϲ����        " << this->name << "����������������һ��������ҡβ�ͣ�" << endl;
    if (this->mood > 4)
        cout << "��ϲ����        " << this->name << "������죬������������~" << endl;
    if (this->fullness > 6 && this->fullness < 10)
        cout << "��ϲ����        " << this->name << "�Եñ�����~" << endl;
}

void dog::Action()
{
    int c = 1;
    while (c != 0)
    {
        cout << "   ������" << this->name << endl;
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
        cout << "     ����~~~�������Ĺ����Ѿ��ܳ��ˣ�����Ҳ���Բ�Ĺĵ�" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   ��������Ͷι��һЩ����ĺ�����~" << endl;
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
        cout << "     ����~~~�������Ĺ����Ѿ��ܳ��ˣ�����Ҳ���Բ�Ĺĵ�" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << this->name << "������������ˮ" << endl;
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
        cout << this->name << "���������ţ�ò���Եò��Ǻ����飬�´���������ɡ�" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   ���" << this->name << "���ƿ����Ϸ�������ǿ������㶪��ƿ��֮�����̼������" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 2;
    this->fullness -= 2;
    this->HP += 2;
    this->mood += 4;
    this->span -= 1;
    system("pause");
}
//��˯����
void dog::Sleep()
{
    this->HP += 2;
    this->eng += 4;
    this->fullness -= 2;
    this->span -= 1;
    system("pause");
}
//��ҽ������
void dog::Doctor()
{
    this->HP = 7;
    this->mood = 10;
    this->fullness = 9;
    this->eng = 10;
    this->span -= 1;
    cout << "����ҽС����ȫ�������£����Ĺ����Ѿ���Ѫ����Ժ�Ҫ�ú��չ���Ŷ��" << endl;
    system("pause");
    return;
}
//��޺���
void dog::Toilet()
{
    if (this->fullness > 8)
    {
        this->fullness -= 4;
        this->HP += 2;
        this->span -= 1;
        cout << "��~~~    ����һкǧ��,�������졭��" << endl;
        cout << this->name << "�е㲻����˼�س�����������ͷ������������ͷ������ɾ��ֳ�" << endl;
        system("pause");
    }
    else if (this->fullness >= 4)
    {
        this->fullness -= 2;
        this->HP += 1;
        this->span -= 1;
        cout << "����������͵ؽ��һ�£�������������̵������������ɾ��Ĺ�����Ҫ������С��,����ĬĬ��ס�����а�����ͷ��ѡ�����˸�С�ݴԡ�" << endl;
        system("pause");
    }
    else
    {
        cout << this->name << "ãȻ�ؿ����㣬��ʾ�Լ���û�����������󡭡�" << endl;
        system("pause");
        return;
    }
}

//���ۺ���
int dog::Sold()
{
    this->status = 0;
    return this->price*2.5;

}

//�ж��Ƿ���
int dog::check()
{
    if (this->span <= 0)
    {
        cout << "          ��ĳ�쿪ʼ��" << this->name << "����һ�̲�ͣ��������������ԣ�����ë����ʼϡ�裬����Ҳ�������䣬Ψһ������Ƕ�����Զ�İ���" << endl;
        cout << "          ���죬�����һ�δյ������ߣ�����ܵ���ʪ�ȵ���ͷ�������㣬Ȼ�����ƺ����¶���ʲô�����Ƶģ��������Լ���Ϥ��С�ѡ�" << endl;
        cout << "          ����Ϊ��ֻ����Ϊ��ʹ��ˣ��߼���������ˣ���û��ѡ��ȥ������" << endl;
        cout << "          ���������æµ�ŵ��﹤����ʱ������Զ���뿪�������Ҳû�л�����" << endl;
        cout << "          ������ÿһ��������ȥ�ĵط�����û���κ���Ϥ��Ӱ�ӣ���������������һ�ο������Ѿ���д��" << endl;
        cout << "          �������ѡ���˶���ǰ��������һվ����" << endl;
        cout << endl;
        cout << "         ����ɽ�֡��� ��������" << endl;

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
        cout << "          ��һ�У���һ�С���Ϊ��Ա���㣬��ĳЩ�����ϻ���û�кϸ�" << endl;
        cout << "          ���������չ˲��ܣ�С�����������徣���Զ���뿪������" << endl;
        cout << endl;
        cout << "         ����ɽ�֡��� ����ز��" << endl;

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