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
        span = 9;//��˵è�о�����
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
//��ʾ���������Ϣ
void cat::showPet()
{
    cout << "       ��    �� ��" << this->name << endl;
    cout << "       �� �� ֵ ��" << this->HP << endl;
    cout << "       ��    �� ��" << this->span << endl;
    cout << "       �� �� ֵ : " << this->eng << endl;
    cout << "       ��    �� ��" << this->mood << endl;
    cout << "       �����̶� ��" << this->fullness << endl;
//ע��
    if (this->HP < 3)
        cout << "ע�⣡��        " << this->name << "ʮ������������һ�ţ���ʾ�Լ��е���������뼰ʱ����ȥ��ҽ����" << endl;
    if (this->eng < 4)
        cout << "ע�⣡��        " << this->name << "˯�����죬��ʾ�Լ��е������ˣ��뼰ʱ������˯��" << endl;
    if (this->mood <= 4)
        cout << "ע�⣡��        " << this->name << "�������ض��ڽ��䲻�����㣨����������������" << endl;
    if (this->fullness <= 4)
        cout << "ע�⣡��        " << this->name << "�۰ͰͿ��������е���ɣ������ʾ�Լ��ö����뼰ʱιʳ��" << endl;
    if (this->fullness >= 9)
        cout << "ע�⣡��        " << this->name << "���ǵ�ͨ�죬���������޵������뼰ʱ����ȥ������" << endl;
//��̬
    if (this->HP >= 2)
        cout << "��ϲ����        " << this->name << "���ڽ���״̬" << endl;
    if (this->eng >= 4)
        cout << "��ϲ����        " << this->name << "������������׷��һֻ��������ˣ" << endl;
    if (this->mood > 4)
        cout << "��ϲ����        " << this->name << "������죬������������~" << endl;
    if (this->fullness > 4&&this->fullness<9)
        cout << "��ϲ����        " << this->name << "�Եñ�����~" << endl;
    
}
//�Գ������
void cat::Action()
{
    int c = 1;
    while (c != 0)
    {
        cout << "   è�䣺" << this->name << endl;
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
//ιʳ����
void cat::Feed()
{
    if (this->fullness > 8)
    {
        this->fullness += 1;
        this->eng += 1;
        this->HP -= 1;
        this->mood -= 1;
        this->span -= 1;
        cout << "     ����~~~��������è���Ѿ��ܳ��ˣ�����Ҳ���Բ�Ĺĵ�" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   ����è��Ͷι��һЩ�����С��~" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng += 2;
    this->fullness += 2;
    this->mood += 2;
    this->span -= 1;
    system("pause");
}
//�������ˮ
void cat::Drink()
{
    if (this->fullness > 8)
    {
        this->fullness += 1;
        this->HP -= 1;
        this->mood -= 1;
        this->span -= 1;
        cout << "     ����~~~��������è���Ѿ��ܳ��ˣ�����Ҳ���Բ�Ĺĵ�" << endl;
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
//�������
void cat::Play()
{
    if (this->eng < 3)
    {
        cout << this->name << "ſ��è�Ѳ���ʾ���붯��" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return;
    }
    cout << "   ���" << this->name << "��ë����èè��ʾһ��Ҫ�˵�����" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 2;
    this->fullness -= 2;
    this->HP += 2;
    this->mood += 4;
    this->span -= 1;
    system("pause");
}
//��˯����
void cat::Sleep()
{
    this->HP += 2;
    this->eng += 4;
    this->fullness -= 2;
    this->span -= 1;
    system("pause");
}
//��ҽ������
void cat::Doctor()
{
    this->HP = 4;
    this->mood = 10;
    this->fullness = 8;
    this->eng = 10;
    this->span -= 1;
    cout << "����ҽС����ȫ�������£�����èè�Ѿ���Ѫ����Ժ�Ҫ�ú��չ���Ŷ��" << endl;
    system("pause");
    return;
}
//��޺���
void cat::Toilet()
{
    if (this->fullness > 8)
    {
        this->fullness -= 4;
        this->HP += 2;
        this->span -= 1;
        cout << "��~~~    èèһкǧ��,�������졭��" << endl;
        cout << this->name << "���ߵĶ�����Լ���С�ѣ�����������ɾ��ֳ�" << endl;
        system("pause");
    }
    else if(this->fullness >=4)
    {
        this->fullness -= 2;
        this->HP += 1;
        this->span -= 1;
        cout << "èè��èɰ�������һ��" << endl;
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
int cat::Sold()
{
    this->status = 0;
    return this->price*3;

}

//�ж��Ƿ���
int cat::check()
{
    if (this->span <= 0)
    {
        cout << "          ��ĳ�쿪ʼ��" << this->name << "����ӵ�д�ǰ������Ƥë���ж�Ҳ�𽥱�������ٻ���" << endl;
        cout << "          ���죬�����һ���������ϥ�ǣ�������Ļ����������ز���㣬�����������ǵش���������ȥ��" << endl;
        cout << "          Ϧ���£���һ��Ҫǿ��èè���������������Լ���Ϥ��С��,������Զ�ı������۾�����" << endl;
        cout << "          ��֪�������è����ֻ�ǻص�����������������" << endl;
        cout << endl;
        cout << "         ����ɽ�֡��� ��������" << endl;
        
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
        cout << "          ������һ��֮���Щ����û�о�������" << endl;
        cout << "          ���������չ˲��ܣ�Сè���������徣���Զ���뿪������" << endl;
        cout << "----------��Ȼ��˵è�о��������������컹�Ǽᶨ��ѡ���ջ�����èè���´λ���׼�����ٵ����˰ɡ�" << endl;
        cout << endl;
        cout << "         ����ɽ�֡��� ����ز��" << endl;

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