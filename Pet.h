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

	string name;//����
	int HP = 8;//����ֵ
	int span = 10;//����
	int mood = 10;//����
	int fullness = 8;//������
	int price = 10;//�۸�
	int eng = 10;//����
	int status = 0;
};

