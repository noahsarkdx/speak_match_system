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
		cout << "ѡ�ֱ��" << it->first << " " << "ѡ������" << it->second.m_name << endl;
	}*/
	int chioce = 0;
	while (true)
	{
		sm.showmanue();
		cout << "����������ѡ��" << endl;
		cin >> chioce;

		switch (chioce)
		{
		case 1://��ʼ����
			sm.startmatch();
			break;
		case 2://�鿴��¼
			sm.showrecord();
			break;
		case 3://��ռ�¼
			sm.clearrecord();
			break;
		case 0://�˳�ϵͳ
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