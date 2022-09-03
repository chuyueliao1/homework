#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pet
{
public:
	virtual int Feed() = 0;//喂食
	virtual int Drink() = 0;//喂水
	virtual int Play() = 0;//玩耍
	virtual int Action() = 0;//行动操作
	virtual int showPet() = 0;//展示信息
	virtual int Sleep() = 0;//哄睡
	virtual int Doctor() = 0;//看医生
	virtual int Toilet() = 0;//如厕
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

