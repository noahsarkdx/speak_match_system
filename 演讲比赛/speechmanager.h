#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <fstream>

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
	void creatspeaker();
	void startmatch();//开始比赛
	void chouqian();
	void bisaiing();
	void showscore();
	void savefile();
	void loadfile();
	bool fileisempty;
	map<int, vector<string>>m_record;//存放往届记录的容器
	void showrecord();
	void clearrecord();
};