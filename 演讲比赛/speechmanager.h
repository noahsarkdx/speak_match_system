#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"

//����ݽ�������
class speechmanager
{
public:
	speechmanager();
	void showmanue();
	void exitsystem();
	~speechmanager();
	//��Ա����
	vector<int> v1;//��һ��ѡ�ֱ��
	vector<int> v2;//�ڶ���ѡ�ֱ��
	vector<int> victory;//ʤ��ѡ�ֱ��
	map<int, speaker> m_speaker;//��ű���Լ���Ӧѡ��
	int m_index;
	void initspeaker();
};