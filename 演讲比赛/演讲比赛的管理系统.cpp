#include <iostream>
using namespace std;
#include "speechmanager.h"
#include "speaker.h"

int main()
{
	speechmanager sm;
	int chioce = 0;
	while (true)
	{
		sm.showmanue();
		cout << "请输入您的选择" << endl;
		cin >> chioce;

		switch (chioce)
		{
		case 1://开始比赛
			break;
		case 2://查看记录
			break;
		case 3://清空记录
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