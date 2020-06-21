#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include<queue>
//#include<stack>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<functional>
#include<math.h>
#include<thread>
#include<assert.h>
#include<string.h>
using namespace std;



/*
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define ERR_EXIT(m) \
do \
{ \
	perror(m); \
	exit(EXIT_FAILURE); \
} while (0)
int main(int argc, char *argv[])
{
	int pipefd[2];
	if (pipe(pipefd) == -1)
		ERR_EXIT("pipe error");
	pid_t pid;
	pid = fork();
	if (pid == -1)
		ERR_EXIT("fork error");
	if (pid == 0) {
		close(pipefd[0]);
		write(pipefd[1], "hello", 5);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	close(pipefd[1]);
	char buf[10] = { 0 };
	read(pipefd[0], buf, 10);
	printf("buf=%s\n", buf);
	return 0;
}


/*
class people
{
public:
	virtual void fun()
	{
		printf("this is people::fun()\n");
	}

	virtual void print()
	{
		cout << "this is people::print()" << endl;
	}

private:
	int _val;
};

class student
{
	void fun()
	{
		cout << "this is student::fun()" << endl;
	}
	void print()
	{
		cout << "this is student::print()" << endl;
	}
private:
	int _sval;
};

void Func(people& pe)
{
	pe.fun();
	pe.print();
}

int main()
{
	people stu;
	Func(stu);

	return 0;
}*/