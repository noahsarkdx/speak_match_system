#include "speechmanager.h"
#include "speaker.h"

speechmanager::speechmanager()
{
	this->initspeaker();
}

void speechmanager::showmanue()
{
	cout << "*******************************************" << endl;
	cout << "*************��ӭ�μ��ݽ�����**************" << endl;
	cout << "*************1.��ʼ�ݽ�����****************" << endl;
	cout << "*************2.�鿴�����¼****************" << endl;
	cout << "*************3.��ձ�����¼****************" << endl;
	cout << "*************0.�˳�����ϵͳ****************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}

speechmanager::~speechmanager()
{

}
void speechmanager::exitsystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
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