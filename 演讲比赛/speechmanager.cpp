#include "speechmanager.h"
#include "speaker.h"

speechmanager::speechmanager()
{
	this->initspeaker();
}

void speechmanager::showmanue()
{
	cout << "*******************************************" << endl;
	cout << "*************欢迎参加演讲比赛**************" << endl;
	cout << "*************1.开始演讲比赛****************" << endl;
	cout << "*************2.查看往届记录****************" << endl;
	cout << "*************3.清空比赛记录****************" << endl;
	cout << "*************0.退出比赛系统****************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}

speechmanager::~speechmanager()
{

}
void speechmanager::exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void speechmanager::initspeaker()
{
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_speaker.clear();
	this->m_index = 1;
}