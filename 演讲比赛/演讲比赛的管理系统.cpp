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
		cout << "����������ѡ��" << endl;
		cin >> chioce;

		switch (chioce)
		{
		case 1://��ʼ����
			break;
		case 2://�鿴��¼
			break;
		case 3://��ռ�¼
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