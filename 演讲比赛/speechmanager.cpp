#include "speechmanager.h"
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>


speechmanager::speechmanager()
{
	this->initspeaker();
	this->creatspeaker();
	this->loadfile();
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
	this->m_record.clear();
}
void speechmanager::creatspeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "ѡ��";
		name += nameseed[i];
		speaker sp;
		sp.m_name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_score[i] = 0;
		}
		this->v1.push_back(i + 10001);
		this->m_speaker.insert(make_pair(i + 10001, sp));
	}
}
void speechmanager::startmatch()
{
	//��һ�ֱ���

	//��ǩ
	this->chouqian();
	//����
	this->bisaiing();
	//��ʾ�������
	this->showscore();
	//�ڶ��ֱ���
	this->m_index++;
	//��ǩ
	this->chouqian();
	//����
	this->bisaiing();
	//��ʾ�������
	this->showscore();
	this->savefile();
	this->initspeaker();
	this->creatspeaker();
	this->loadfile();
	cout << "����������" << endl;
	system("pause");
	system("cls");
}
void speechmanager::chouqian()
{
	cout << "��<<" << this->m_index << ">>�ֱ������ڳ�ǩ" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "��ǩ��˳������" << endl;
	if (this->m_index == 1)
	{
		random_shuffle(v1.begin(),v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it<<" ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------------" << endl;
	system("pause");
	cout << endl;
}
void speechmanager::bisaiing()
{
	cout << "��<<" << this->m_index << ">>�ֱ������ڽ���" << endl;
	cout << "-------------------------------------------" << endl;
	multimap<double, int, greater<double>> groupscore;//����һ����ʱ�����������
	int num = 0;
	vector<int>v_src;//����ѡ������
	if (this->m_index == 1)
	{
		v_src = v1;
	}
	else
	{
		v_src = v2;
	}
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
	{
		//��ί��֣���deque��������
		num++;
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(),greater<double>());//��������
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		this->m_speaker[*it].m_score[this->m_index-1]=avg;
		//cout << "��ţ� " << *it << "  ������ " << this->m_speaker[*it].m_name << "  ƽ���֣� " << this->m_speaker[*it].m_score[this->m_index] << endl;
		groupscore.insert(make_pair(avg, *it));
		//ÿ6��ȥǰ��
		if (num % 6 == 0)
		{
			cout << "��<<" << num/6 << ">>�����С������" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++)
			{
				cout << "��ţ� " << it->second << "  ������ " << this->m_speaker[it->second].m_name << "  ƽ���֣� " << this->m_speaker[it->second].m_score[this->m_index-1] << endl;
			}
			//ȡ��ǰ������������
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end()&&count<3; it++,count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					victory.push_back(it->second);
				}
			}
			groupscore.clear();
		}
	}
	cout << "��<<" << this->m_index << ">>�ֱ����Ѿ�����" << endl;
	system("pause");
}
void speechmanager::showscore()
{
	cout << "��<<" << this->m_index << ">>�ֱ�������ѡ����Ϣ����" << endl;
	cout << "---------------------------------------------------" << endl;
	vector<int>v;
	if (this->m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = victory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ� " << *it << "  ������ " << this->m_speaker[*it].m_name << "  ƽ���֣� " << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showmanue();
}
void speechmanager::savefile()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�
	for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++)
	{
		ofs << *it << "," << this->m_speaker[*it].m_name << "," 
			<< m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼������" << endl;
	this->fileisempty = false;
}
void speechmanager::loadfile()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileisempty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileisempty = true;
		cout << "�ļ�Ϊ��" << endl;
		ifs.close();
		return;
	}
	this->fileisempty = false;
	ifs.putback(ch);//�������ȡ�ĵ����ַ��ٷŻ���
	string data;
	int index = 0;
	while (ifs>>data)
	{
		//cout << data << endl;
		vector<string>v;
		int pos = -1;//�鵽���ŵ�λ��
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}
void speechmanager::showrecord()
{
	if (this->fileisempty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "��" << i + 1 << "������������" << endl;
			cout << "�ھ���ţ� " << this->m_record[i][0] << " ѡ�������� " << this->m_record[i][1] << " �ھ��÷֣� " << this->m_record[i][2] << endl;
			cout << "�Ǿ���ţ� " << this->m_record[i][3] << " ѡ�������� " << this->m_record[i][4] << " �Ǿ��÷֣� " << this->m_record[i][5] << endl;
			cout << "������ţ� " << this->m_record[i][6] << " ѡ�������� " << this->m_record[i][7] << " �����÷֣� " << this->m_record[i][8] << endl;
		}
	}
	system("pause");
	system("cls");
}
void speechmanager::clearrecord()
{
	cout << "�Ƿ�ȷ��������ݣ�" << endl;
	cout << "1����" << endl;
	cout << "2����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initspeaker();
		this->creatspeaker();
		this->loadfile();
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
speechmanager::~speechmanager()
{

}