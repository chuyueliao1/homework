#pragma once
#include "Cat.h"
void cat::Name(string s)
{
    this->name = s;
}

string cat::ShowName()
{
    return this->name;
}
void cat::Status(int s)
{
    this->status = s;
}
int cat::ShowStatus()
{
    return status;
}
int cat::ShowKind()
{
    return this->kind;
}

int cat::ShowPrice()
{
    return this->price;
}
int cat::ShowHP()
{
    return this->HP;
}
int cat::ShowSpan()
{
    return this->span;
}
int cat::ShowMood()
{
    return this->mood;
}
int cat::ShowFullness()
{
    return this->fullness;

}
int cat::ShowEng()
{
    return this->eng;
}
//��ʾ���������Ϣ
int cat::showPet()
{
    cout << "       ��    �� ��" << this->name << endl;
    cout << "       Ʒ    �� ��" << this->kind << endl;
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
    if (this->fullness > 4 && this->fullness < 9)
        cout << "��ϲ����        " << this->name << "�Եñ�����~" << endl;
    return 0;
}
//�Գ������
int cat::Action()
{
    int cost = 0;//���������Ļ���
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
//ιʳ����
int cat::Feed()
{
    system("cls");
    cout << "       ��������Ͷι����ʳ�" << endl;
    cout << "       1�� -------------- С���  (10r)" << endl;
    cout << "       2�� -------------- è�����(20r)" << endl;
    cout << "       3�� -------------- �ڰ�����(0r)" << endl;
    cout << "       0�� -------------- �˳�" << endl;
    system("pause");
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        if (this->fullness > 8)
        {
            this->fullness += 1;
            this->eng += 1;
            this->HP -= 2;
            this->mood -= 1;
            this->span -= 1;
            cout << "     ����~~~��������è���Ѿ��ܳ��ˣ�����Ҳ���Բ�Ĺĵ�" << endl;
            cout << "-----------------------------------------------------" << endl;
            system("pause");
            return 10;
        }
        cout << "     ������~���ԡ���" << this->name << "�����ζ�ؽ������������Ƴ�����һ����������èè������������ɣ�" << endl;
        this->fullness += 1;
        this->eng += 2;
        this->HP += 1;
        this->mood += 2;
        this->span -= 1;
        cout << "---------------------------------------------------------------------------" << endl;
        system("pause");
        return 10;
    }
    case 2:
    {
        if (this->fullness > 8)
        {
            this->fullness += 1;
            this->eng += 1;
            this->HP -= 2;
            this->mood -= 1;
            this->span -= 1;
            cout << "     ����~~~��������è���Ѿ��ܳ��ˣ�����Ҳ���Բ�Ĺĵ�" << endl;
            cout << "-----------------------------------------------------" << endl;
            system("pause");
            return 20;
        }
        cout << "       èè���ű��ɣ������̧ͷ�����㣬�ƺ���˵��������Ҳ����Ŷ����" << endl;
        this->fullness += 2;
        this->eng += 2;
        this->HP += 1;
        this->mood += 1;
        this->span -= 1;
        cout << "---------------------------------------------------------------------------" << endl;
        system("pause");
        return 20;
    }
    case 3:
    {
        cout << "         yue~~~" << this->name << "ǳ����һ�ڣ������ؿ�����һ�ۣ����ˣ���������������𣿣����Ծ��������ͣ�" << endl;
        this->fullness -= 1;
        this->eng -= 1;
        this->HP -= 2;
        this->mood -= 1;
        this->span -= 1;
        system("pause");
        return 0;
    }
    case 0:
    {
        return 0;
    }
    }

}
//�������ˮ
int cat::Drink()
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
        return 0;
    }
    cout << this->name << "������������ˮ" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->HP += 2;
    this->fullness += 2;
    this->mood += 2;
    this->span -= 1;
    system("pause");
    return 0;
}
//�������
int cat::Play()
{
    if (this->eng < 3)
    {
        cout << this->name << "ſ��è�Ѳ���ʾ���붯��" << endl;
        cout << "-----------------------------------------------------" << endl;
        system("pause");
        return 0;
    }
    cout << "   ���" << this->name << "��ë����èè��ʾһ��Ҫ�˵�����" << endl;
    cout << "-----------------------------------------------------" << endl;
    this->eng -= 2;
    this->fullness -= 2;
    this->HP += 2;
    this->mood += 4;
    this->span -= 1;
    system("pause");
    return 0;
}
//��˯����
int cat::Sleep()
{
    this->HP += 2;
    this->eng += 4;
    this->fullness -= 2;
    this->span -= 1;
    system("pause");
    return 0;
}
//��ҽ������
int cat::Doctor()
{
    this->HP = 4;
    this->mood = 10;
    this->fullness = 8;
    this->eng = 10;
    this->span -= 1;
    cout << "����ҽС����ȫ�������£�����èè�Ѿ���Ѫ����Ժ�Ҫ�ú��չ���Ŷ��(�ķ�100r)" << endl;
    system("pause");
    return 100;
}
//��޺���
int cat::Toilet()
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
    else if (this->fullness >= 4)
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
        return 0;
    }
}

//���ۺ���
int cat::Sold()
{
    this->status = 0;
    return this->price * 3;

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
        cout << "           # # # # # # # # # # # # #" << endl;
        cout << "         #                           #~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "    ##   #       ##                  #" << endl;
        cout << "    #  # #     #  #                  #~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "    #   # # # #   #                  #       # #" << endl;
        cout << "   #               #                 # # # #    #~~~~~~~~~" << endl;
        cout << " #      *     *      #               #        #" << endl;
        cout << " #                   #               # # # # #~~~~~~~~~~~~" << endl;
        cout << "   #    |__|__|    #                 #" << endl;
        cout << "     # # # # # # # # # # # # # # # #  ~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "      # #     # #       # #     # #   " << endl;


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
        cout << "          ������һ��֮���Щ���������������á�" << endl;
        cout << "          ���������չ˲��ܣ�Сè���������徣���Զ���뿪������" << endl;
        cout << "----------��Ȼ��˵è�о��������������컹�Ǽᶨ��ѡ���ջ�����èè���´λ���׼�����ٵ����˰ɡ�" << endl;
        cout << endl;
        cout << "         ����ɽ�֡��� ����ز��" << endl;
        cout << "           # # # # # # # # # # # # #" << endl;
        cout << "         #                           #~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "    ##   #       ##                  #" << endl;
        cout << "    #  # #     #  #                  #~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "    #   # # # #   #                  #       # #" << endl;
        cout << "   #               #                 # # # #    #~~~~~~~~~" << endl;
        cout << " #     --     --     #               #        #" << endl;
        cout << " #                   #               # # # # #~~~~~~~~~~~~" << endl;
        cout << "   #    |__|__|    #                 #" << endl;
        cout << "     # # # # # # # # # # # # # # # #  ~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "      # #     # #       # #     # #   " << endl;
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
