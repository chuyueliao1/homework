#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pet
{
public:
	virtual void Feed() = 0;//ιʳ
	virtual void Drink() = 0;//ιˮ
	virtual void Play() = 0;//��ˣ
	virtual void Action() = 0;//�ж�����
	virtual void showPet() = 0;//չʾ��Ϣ
	virtual void Sleep() = 0;//��˯
	virtual void Doctor() = 0;//��ҽ��
	virtual void Toilet() = 0;//���
	virtual int Sold() = 0;//����
	virtual int check() = 0;//�ж��Ƿ���

	string name;//����
	int HP = 8;//����ֵ
	int span = 10;//����
	int mood = 10;//����
	int fullness = 8;//������
	int price = 10;//�۸�
	int eng = 10;//����
	int status = 0;
};

