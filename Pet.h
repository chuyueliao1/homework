#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pet
{
public:
	virtual int Feed() = 0;//ιʳ
	virtual int Drink() = 0;//ιˮ
	virtual int Play() = 0;//��ˣ
	virtual int Action() = 0;//�ж�����
	virtual int showPet() = 0;//չʾ��Ϣ
	virtual int Sleep() = 0;//��˯
	virtual int Doctor() = 0;//��ҽ��
	virtual int Toilet() = 0;//���
	virtual int Sold() = 0;//����
	virtual int check() = 0;//�ж��Ƿ���
	virtual void Name(string) = 0;//ȡ��
	virtual void Status(int) = 0;
	
	virtual string ShowName() = 0;
	virtual int ShowStatus() = 0;
	virtual int ShowKind() = 0;
	virtual int ShowPrice() = 0;
	virtual int ShowHP() = 0;
	virtual int ShowSpan() = 0;
	virtual int ShowMood() = 0;
	virtual int ShowFullness() = 0;
	virtual int ShowEng() = 0;

	string name;//����
	int kind;//����
	int HP = 8;//����ֵ
	int span = 10;//����
	int mood = 10;//����
	int fullness = 8;//������
	int price = 10;//�۸�
	int eng = 10;//����
	int status = 0;
};

