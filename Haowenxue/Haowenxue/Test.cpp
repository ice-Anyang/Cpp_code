
#include"common.h"
int main()
{
	ScoreManager m;
	int n;
	while (1)//无限循环直到遇到break跳出循环
	{
		menu();
		cin >> n;
		switch (n)
		{
		case 1:
			m.Add();
			break;
		case 2:
			m.Delete();
			break;
		case 3:
			m.Update();
			break;
		case 4:
			m.Search();
			break;
		case 5:
			m.ShowAll();
			break;
		case 6:
			m.Sort();
			break;
		case 7:
			m.Average();
			break;
		case 8:
			m.PassRate();
			break;
		default:
		{
				   cout << "输入错误" << endl;
		}
		}
		system("pause");
	}
}
