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
    cout << "       ��    �� ��" << this->name << endl;
    cout << "       �� �� ֵ ��" << this->HP << endl;
    cout << "       ��    �� ��" << this->span << endl;
    cout << "       �� �� ֵ : " << this->eng << endl;
    cout << "       ��    �� ��" << this->mood << endl;
    cout << "       �����̶� ��" << this->fullness << endl;
    //ע��
    if (this->HP < 2)
        cout << "ע�⣡��        " << this->name << "�����ݵĵ��ٶ����Ա仺��������ˮ����ʱ�޷�����ƽ�⣨�뼰ʱ����ȥ��ҽ����" << endl;
    if (this->eng < 2)
        cout << "ע�⣡��        " << this->name << "��Ȼ�����۾���������ˮ�б����˾�ֹ���뼰ʱ������˯��" << endl;
    if (this->mood <= 4)
        cout << "ע�⣡��        " << this->name << "���ĵ�������ױڣ��ܾ������ζ�������������������" << endl;
    if (this->fullness <= 2)
        cout << "ע�⣡��        " << this->name << "����̽ͷ����ˮ�棬�ƺ����ڴ���ʲô���뼰ʱιʳ��" << endl;
    if (this->fullness >= 7)
        cout << "ע�⣡��        " << this->name << "���ǵ�ͨ�죬���������޵������뼰ʱ������޲���ˮ��" << endl;
    //��̬
    if (this->HP >= 2)
        cout << "��ϲ����        " << this->name << "���ڽ���״̬" << endl;
    if (this->eng >= 2)
        cout << "��ϲ����        " << this->name << "������������ˮ���������ڳ��ˣ�" << endl;
    if (this->mood > 4)
        cout << "��ϲ����        " << this->name << "������죬��������ˮ�л�����~" << endl;
    if (this->fullness > 2 && this->fullness < 7)
        cout << "��ϲ����        " << this->name << "�Եñ�����~" << endl;
}

void fish::Action()
{
    int c = 1;
    while (c != 0)
    {
        cout << "   �����" << this->name << endl;
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
void fish::Feed()
{
    if (this->fullness > 6)
    {
        this->fullness += 1;
        this->eng += 1;
        this->HP -= 1;
        this->mood -= 1;
        this->span -= 1;
        cout << "     ����~~~������������Ѿ��ܳ��ˣ�����Ҳ���Բ�Ĺĵ�" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   �������Ͷι��һЩ�����ˮ��~" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->fullness += 1;
    this->mood += 2;
    this->span -= 1;
    system("pause");
}

void fish::Drink()
{
    cout << this->name << "��Ȼ��ˮ�У��������̲�ס���㷭�˸�����ۡ����ģ� Сү������ס��ˮ����Ҫ��ιˮ��" << endl;
    cout << "-----------------------------------------------------" << endl;
    system("pause");
}


void fish::Play()
{
    if (this->eng < 2)
    {
        cout << "     ��������Ѿ������ˣ��벻Ҫ������ˣ�ˣ�������Ϣһ�������ͣӪҵ�ɣ�";
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   �������ˣ��������ǵ������������" << endl;
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
//��ҽ������
void fish::Doctor()
{
    this->HP = 6;
    this->mood = 10;
    this->fullness = 6;
    this->eng = 6;
    this->span -= 1;
    cout << "����ҽС����ȫ�������£���������Ѿ���Ѫ����Ժ�Ҫ�ú��չ���Ŷ��" << endl;
    system("pause");
    return;
}
//��޺���
void fish::Toilet()
{
    if (this->fullness > 6)
    {
        this->fullness -= 2;
        this->HP += 1;
        this->span -= 1;
        cout << "     ������������ˮ����ʱ��ͣ�٣�ˮ��ͻȻ�������ĺ�ɫ�������ʡ���" << endl;
        cout << this->name << "ת�˸���������ˣ��·�ʲôҲû�з�����" << endl;
        system("pause");
    }
    else if (this->fullness >= 3)
    {
        this->fullness -= 1;
        this->HP += 1;
        this->span -= 1;
        cout << "ˮ�г�����΢��ɫ��������" << endl;
        system("pause");
    }
    else
    {
        cout << this->name << "��ȫ�����㡭��" << endl;
        system("pause");
        return;
    }
}

int fish::Sold()
{
    this->status = 0;
    return this->price*1.2;
}

//�ж��Ƿ���
int fish::check()
{
    if (this->span <= 0)
    {
        cout << "          ��ĳ�쿪ʼ��������������ʵ�֡�����ǳ�ף�����˪�쾺���ɡ���"<<this->name<<"Ҳ�𽥿�ʼ��ˮ�оþ�����,��������������һ�����͵�ˮ�ݡ�" << endl;
        cout << "          �����ף�����������װ�������������Ϊ�Լ���δʵ�ֵġ�����Ծ���š����ź���������δ�����Լ�������׳־��ֻ����˥�ϵ�����ʵ���޷�֧������ô���ˡ�" << endl;
        cout << "          ż����Ҳ����������С��������������ݣ���������Ϊ��������أ��෴�����������������һ���������ɹ�!" << endl;
        cout << "          ���죬���������ڲ��ټ����źϡ���" << endl;
        cout << endl;
        cout << "         ����ɽ�֡��� ��������" << endl;

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
        cout << "          ������ʵ����û��ʲô�����������ʣ����ƺ�û�������������" << endl;
        cout << "          �Բ������������չ˲��ܣ�������������徣���Զ���뿪������" << endl;
        cout << endl;
        cout << "         ����ɽ�֡��� ����ز��" << endl;

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
