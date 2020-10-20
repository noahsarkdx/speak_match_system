#include <iostream>
using namespace std;
#include "speechmanager.h"
#include "speaker.h"
#include <ctime>

int main()
{
	srand((unsigned int)time(NULL));
	speechmanager sm;
	/*for (map<int, speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end(); it++)
	{
		cout << "选手编号" << it->first << " " << "选手姓名" << it->second.m_name << endl;
	}*/
	int chioce = 0;
	while (true)
	{
		sm.showmanue();
		cout << "请输入您的选择" << endl;
		cin >> chioce;

		switch (chioce)
		{
		case 1://开始比赛
			sm.startmatch();
			break;
		case 2://查看记录
			sm.showrecord();
			break;
		case 3://清空记录
			sm.clearrecord();
			break;
		case 0://退出系统
			sm.exitsystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	sm.showmanue();
	system("pause");
	return 0;
}