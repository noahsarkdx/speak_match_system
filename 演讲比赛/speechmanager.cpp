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
	cout << "*************欢迎参加演讲比赛**************" << endl;
	cout << "*************1.开始演讲比赛****************" << endl;
	cout << "*************2.查看往届记录****************" << endl;
	cout << "*************3.清空比赛记录****************" << endl;
	cout << "*************0.退出比赛系统****************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
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
	this->m_record.clear();
}
void speechmanager::creatspeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "选手";
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
	//第一轮比赛

	//抽签
	this->chouqian();
	//比赛
	this->bisaiing();
	//显示比赛结果
	this->showscore();
	//第二轮比赛
	this->m_index++;
	//抽签
	this->chouqian();
	//比赛
	this->bisaiing();
	//显示比赛结果
	this->showscore();
	this->savefile();
	this->initspeaker();
	this->creatspeaker();
	this->loadfile();
	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
}
void speechmanager::chouqian()
{
	cout << "第<<" << this->m_index << ">>轮比赛正在抽签" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "抽签的顺序如下" << endl;
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
	cout << "第<<" << this->m_index << ">>轮比赛正在进行" << endl;
	cout << "-------------------------------------------" << endl;
	multimap<double, int, greater<double>> groupscore;//建立一个临时容器存放数据
	int num = 0;
	vector<int>v_src;//比赛选手容器
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
		//评委打分，用deque容器接受
		num++;
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(),greater<double>());//降序排列
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		this->m_speaker[*it].m_score[this->m_index-1]=avg;
		//cout << "编号： " << *it << "  姓名： " << this->m_speaker[*it].m_name << "  平均分： " << this->m_speaker[*it].m_score[this->m_index] << endl;
		groupscore.insert(make_pair(avg, *it));
		//每6人去前三
		if (num % 6 == 0)
		{
			cout << "第<<" << num/6 << ">>组比赛小组名次" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++)
			{
				cout << "编号： " << it->second << "  姓名： " << this->m_speaker[it->second].m_name << "  平均分： " << this->m_speaker[it->second].m_score[this->m_index-1] << endl;
			}
			//取走前三名放入容器
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
	cout << "第<<" << this->m_index << ">>轮比赛已经结束" << endl;
	system("pause");
}
void speechmanager::showscore()
{
	cout << "第<<" << this->m_index << ">>轮比赛晋级选手信息如下" << endl;
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
		cout << "编号： " << *it << "  姓名： " << this->m_speaker[*it].m_name << "  平均分： " << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showmanue();
}
void speechmanager::savefile()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件
	for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++)
	{
		ofs << *it << "," << this->m_speaker[*it].m_name << "," 
			<< m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录保存完" << endl;
	this->fileisempty = false;
}
void speechmanager::loadfile()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileisempty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileisempty = true;
		cout << "文件为空" << endl;
		ifs.close();
		return;
	}
	this->fileisempty = false;
	ifs.putback(ch);//将上面读取的单个字符再放回来
	string data;
	int index = 0;
	while (ifs>>data)
	{
		//cout << data << endl;
		vector<string>v;
		int pos = -1;//查到逗号的位置
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
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "第" << i + 1 << "届比赛结果如下" << endl;
			cout << "冠军编号： " << this->m_record[i][0] << " 选手姓名： " << this->m_record[i][1] << " 冠军得分： " << this->m_record[i][2] << endl;
			cout << "亚军编号： " << this->m_record[i][3] << " 选手姓名： " << this->m_record[i][4] << " 亚军得分： " << this->m_record[i][5] << endl;
			cout << "季军编号： " << this->m_record[i][6] << " 选手姓名： " << this->m_record[i][7] << " 季军得分： " << this->m_record[i][8] << endl;
		}
	}
	system("pause");
	system("cls");
}
void speechmanager::clearrecord()
{
	cout << "是否确认清空数据？" << endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initspeaker();
		this->creatspeaker();
		this->loadfile();
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
speechmanager::~speechmanager()
{

}