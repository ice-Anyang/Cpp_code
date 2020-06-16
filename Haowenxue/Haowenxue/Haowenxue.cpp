#include"common.h"

int ScoreManager::Select()
{
	cout << "��ѡ����ҷ�ʽ:" << endl;
	cout << "1��ѧ��" << endl;
	cout << "2������" << endl;
	int n, i;
	string str;
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "������ѧ��:";
		cin >> str;
		i = SearchByNumber(str);
		break;
	case 2:
		cout << "����������:";
		cin >> str;
		i = SearchByName(str);
	}
	return i;
}
int ScoreManager::SearchByNumber(string number)
{
	int i;
	for (i = 0; i<sum; ++i)
	{
		if (score[i].getNumber() == number)
			break;
	}
	if (i == sum)
		return -1;
	return i;
}
int ScoreManager::SearchByName(string name)
{
	int i;
	for (i = 0; i<sum; ++i)
	{
		if (score[i].getName() == name)
			break;
	}
	if (i == sum)
		return -1;
	return i;
}
void ScoreManager::SortByNumber()//��ѧ������
{
	int i, j;
	Student temp;
	for (i = 0; i<sum - 1; ++i)
	{
		for (j = i; j<sum - 1; ++j)
		if (score[j].getNumber()>score[j + 1].getNumber())
		{
			temp = score[j];
			score[j] = score[j + 1];
			score[j + 1] = temp;
		}
	}
}
void ScoreManager::SortByName()//����������
{
	int i, j;
	Student temp;
	for (i = 0; i<sum - 1; ++i)
	{
		for (j = i; j<sum - 1; ++j)
		if (score[j].getName()>score[j + 1].getName())
		{
			temp = score[j];
			score[j] = score[j + 1];
			score[j + 1] = temp;
		}
	}
}
void ScoreManager::SortBySum()//���ܷ�
{
	int i, j;
	Student temp;
	for (i = 0; i<sum - 1; ++i)
	{
		for (j = i; j<sum - 1; ++j)
		if (score[j].getSum()>score[j + 1].getSum())
		{
			temp = score[j];
			score[j] = score[j + 1];
			score[j + 1] = temp;
		}
	}
}
float ScoreManager::getAverage()
{
	int i, s;
	for (s = i = 0; i<sum; ++i)
		s += score[i].getSum();
	return s / (float)sum;
}
void ScoreManager::Add()
{
	Student s;
	string number;
	string name;
	int math;
	int english;
	cout << "������ѧ��:";
	cin >> number;
	s.setNumber(number);
	cout << "����������:";
	cin >> name;
	s.setName(name);
	cout << "��������ѧ:";
	cin >> math;
	s.setMath(math);
	if (math>100)
	{
		cout << "��������" << endl;
		return;
	}
	cout << "������Ӣ��:";
	cin >> english;
	s.setEnglish(english);
	score[sum] = s;
	sum++;
	cout << "��ӳɹ�" << endl;
}
void ScoreManager::Delete()
{
	int i = Select();
	if (i == -1)
	{
		cout << "ѧ��������" << endl;
		return;
	}
	for (i++; i<sum; i++)
		score[i - 1] = score[i];
	sum--;
	cout << "ɾ���ɹ�" << endl;
}
void ScoreManager::Update()
{
	int i = Select();
	if (i == -1)
	{
		cout << "ѧ��������" << endl;
		return;
	}
	Student s;
	string number;
	string name;
	int math;
	int english;
	cout << "������ѧ��:";
	cin >> number;
	s.setNumber(number);
	cout << "����������:";
	cin >> name;
	s.setName(name);
	cout << "��������ѧ:";
	cin >> math;
	s.setMath(math);
	cout << "������Ӣ��:";
	cin >> english;
	s.setEnglish(english);
	score[i] = s;
	cout << "�޸ĳɹ�" << endl;
}
void ScoreManager::Search()
{
	int i = Select();
	if (i == -1)
	{
		cout << "ѧ��������" << endl;
		return;
	}
	cout << score[i].getNumber() << " " << score[i].getName() << " " << score[i].getMath() << " " << score[i].getEnglish() << endl;
}
void ScoreManager::ShowAll()
{
	int i;
	cout << "ѧ��   ����   ��ѧ   Ӣ��   �ܷ�" << endl;
	for (i = 0; i<sum; ++i)
		cout << score[i].getNumber() << " " << score[i].getName() << " " << score[i].getMath() << " " << score[i].getEnglish() << " " << score[i].getSum() << endl;
}
void ScoreManager::Sort()
{
	cout << "��ѡ������ʽ:" << endl;
	cout << "1��ѧ��" << endl;
	cout << "2������" << endl;
	cout << "3���ܷ�" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		SortByNumber();
		break;
	case 2:
		SortByName();
		break;
	case 3:
		SortBySum();
		break;
	}
	cout << "�������" << endl;
}
void ScoreManager::Average()
{
	cout << "ƽ���ɼ�:" << getAverage() << endl;
}
void ScoreManager::PassRate()
{
	float average = getAverage();
	int i, s;
	for (s = i = 0; i<sum; ++i)
	{
		if (score[i].getSum()>average)
			s++;
	}
	cout << "������:" << s / (float)sum << endl;
}
void menu()
{
	system("cls");
	cout << "��ӭʹ�óɼ�����ϵͳ,�밴��ʾʹ��(�������ּ���)��" << endl;
	cout << "==============���ǻ����ķָ���=======================" << endl;
	cout << "                1�����                              " << endl;
	cout << "                2��ɾ��                              " << endl;
	cout << "                3���޸�                              " << endl;
	cout << "                4����ѯ                              " << endl;
	cout << "                5���б�                              " << endl;
	cout << "                6������                              " << endl;
	cout << "                7��ƽ����                            " << endl;
	cout << "                8��������                            " << endl;
	cout << "==============���ǻ����ķָ���=======================" << endl;
}
