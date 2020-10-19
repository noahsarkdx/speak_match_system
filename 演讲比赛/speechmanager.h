#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"

//设计演讲管理类
class speechmanager
{
public:
	speechmanager();
	void showmanue();
	void exitsystem();
	~speechmanager();
	//成员属性
	vector<int> v1;//第一轮选手编号
	vector<int> v2;//第二轮选手编号
	vector<int> victory;//胜出选手编号
	map<int, speaker> m_speaker;//存放编号以及对应选手
	int m_index;
	void initspeaker();
};