#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pet
{
public:
	virtual void Feed() = 0;//喂食
	virtual void Drink() = 0;//喂水
	virtual void Play() = 0;//玩耍
	virtual void Action() = 0;//行动操作
	virtual void showPet() = 0;//展示信息
	virtual void Sleep() = 0;//哄睡
	virtual void Doctor() = 0;//看医生
	virtual void Toilet() = 0;//如厕
	virtual int Sold() = 0;//出售
	virtual int check() = 0;//判断是否存活

	string name;//姓名
	int HP = 8;//健康值
	int span = 10;//寿命
	int mood = 10;//心情
	int fullness = 8;//饱腹感
	int price = 10;//价格
	int eng = 10;//体力
	int status = 0;
};

