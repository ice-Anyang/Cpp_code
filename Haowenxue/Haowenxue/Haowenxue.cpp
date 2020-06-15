#include"common.h"

int ScoreManager::Select()
{
	cout << "请选择查找方式:" << endl;
	cout << "1、学号" << endl;
	cout << "2、姓名" << endl;
	int n, i;
	string str;
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "请输入学号:";
		cin >> str;
		i = SearchByNumber(str);
		break;
	case 2:
		cout << "请输入姓名:";
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
void ScoreManager::SortByNumber()//按学号排序
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
void ScoreManager::SortByName()//按名字排序
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
void ScoreManager::SortBySum()//按总分
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
	cout << "请输入学号:";
	cin >> number;
	s.setNumber(number);
	cout << "请输入姓名:";
	cin >> name;
	s.setName(name);
	cout << "请输入数学:";
	cin >> math;
	s.setMath(math);
	if (math>100)
	{
		cout << "输入有误" << endl;
		return;
	}
	cout << "请输入英语:";
	cin >> english;
	s.setEnglish(english);
	score[sum] = s;
	sum++;
	cout << "添加成功" << endl;
}
void ScoreManager::Delete()
{
	int i = Select();
	if (i == -1)
	{
		cout << "学生不存在" << endl;
		return;
	}
	for (i++; i<sum; i++)
		score[i - 1] = score[i];
	sum--;
	cout << "删除成功" << endl;
}
void ScoreManager::Update()
{
	int i = Select();
	if (i == -1)
	{
		cout << "学生不存在" << endl;
		return;
	}
	Student s;
	string number;
	string name;
	int math;
	int english;
	cout << "请输入学号:";
	cin >> number;
	s.setNumber(number);
	cout << "请输入姓名:";
	cin >> name;
	s.setName(name);
	cout << "请输入数学:";
	cin >> math;
	s.setMath(math);
	cout << "请输入英语:";
	cin >> english;
	s.setEnglish(english);
	score[i] = s;
	cout << "修改成功" << endl;
}
void ScoreManager::Search()
{
	int i = Select();
	if (i == -1)
	{
		cout << "学生不存在" << endl;
		return;
	}
	cout << score[i].getNumber() << " " << score[i].getName() << " " << score[i].getMath() << " " << score[i].getEnglish() << endl;
}
void ScoreManager::ShowAll()
{
	int i;
	cout << "学号   姓名   数学   英语   总分" << endl;
	for (i = 0; i<sum; ++i)
		cout << score[i].getNumber() << " " << score[i].getName() << " " << score[i].getMath() << " " << score[i].getEnglish() << " " << score[i].getSum() << endl;
}
void ScoreManager::Sort()
{
	cout << "请选择排序方式:" << endl;
	cout << "1、学号" << endl;
	cout << "2、姓名" << endl;
	cout << "3、总分" << endl;
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
	cout << "排序完成" << endl;
}
void ScoreManager::Average()
{
	cout << "平均成绩:" << getAverage() << endl;
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
	cout << "及格率:" << s / (float)sum << endl;
}
void menu()
{
	system("cls");
	cout << "欢迎使用成绩分析系统,请按提示使用(输入数字即可)：" << endl;
	cout << "==============我是华丽的分割线=======================" << endl;
	cout << "                1、添加                              " << endl;
	cout << "                2、删除                              " << endl;
	cout << "                3、修改                              " << endl;
	cout << "                4、查询                              " << endl;
	cout << "                5、列表                              " << endl;
	cout << "                6、排序                              " << endl;
	cout << "                7、平均分                            " << endl;
	cout << "                8、及格率                            " << endl;
	cout << "==============我是华丽的分割线=======================" << endl;
}
