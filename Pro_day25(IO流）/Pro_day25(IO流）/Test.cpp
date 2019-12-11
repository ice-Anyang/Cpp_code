#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


/*
void main()
{
	FILE *fp = fopen("Test1.txt", "r");
	int pos = 1;
	int value;
	while (1)
	{
		cout << "input pos:>";
		cin >> pos;
		fseek(fp, pos * 3, SEEK_SET);
		fscanf(fp, "%d", &value);
		printf("value = %d\n", value);
	}
	fclose(fp);
}
void TestCWrite(int ar[], int n)
{
	FILE *fp = fopen("Test1.txt", "w");
	if (fp == NULL)
	{
		return;
	}
	for (int i = 0; i<n; ++i)
	{
		fprintf(fp, "%d ", ar[i]);
	}
	fclose(fp);
}
void TestCRead(int ar[], int n)
{
	FILE *fp = fopen("Test1.txt", "r");
	if (fp == NULL)
		return;
	for (int i = 0; i<n; ++i)
	{
		fscanf(fp, "%d", &ar[i]);
	}
	fclose(fp);
}
void TestCppWrite(int ar[], int n)
{
	//ofstream ofile;  //1
	//ofile.open("Test2.txt", ios::out);  //2
	ofstream ofile("Test3.txt", ios::out);
	if (!ofile)
	{
		cout << "Open File Error." << endl;
		return;
	}
	for (int i = 0; i<n; ++i)
	{
		ofile << ar[i] << " ";  //3
	}
	ofile.close();     //4
}
void TestCppRead(int ar[], int n)
{
	ifstream ifile;
	ifile.open("Test2.txt", ios::in);
	if (!ifile)
		return;
	for (int i = 0; i<n; ++i)
	{
		ifile >> ar[i];
	}
	ifile.close();
}

/*
void TestCRead(int arr[], int n)
{
	FILE *fp = fopen("Test3.txt", "wb");
	if (fp == NULL)
		return;
	fread(arr, sizeof(int), n, fp);
	fclose(fp);
}

void TestCwrite(int *arr, int s)
{
	FILE *fp = fopen("Test3.txt", "wb");
	if (fp == NULL)
	{
		return;
	}
	fwrite(arr, sizeof(int), s, fp); //C
	fclose(fp);
}

void TestCppwrite(int *arr, int s)
{
	ofstream ofile("Test4.txt", ios::out | ios::binary);
	if (!ofile)
	{
		cout << "Open File Error." << endl;
		return;
	}
	ofile.write((const char*)arr, sizeof(int)*s);
	ofile.close();
}

void TestCppRead(int *arr, int n)
{
	ifstream ifile;
	ifile.open("Test4.txt", ios::in | ios::binary);
	if (!ifile)
		return;
	ifile.read((char*)arr, sizeof(int)*n);
	ifile.close();
}

int main()
{
	int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
	int sz = sizeof(arr) / sizeof(int);
	TestCwrite(arr,sz);
	TestCppwrite(arr, sz);
	return 0;
}

/*
int main()
{
	int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 100 };
	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n; ++i)
	{
		cout.width(4);
		cout.flags(ios::left);
		cout << arr[i];
	}
	cout << endl;
	return 0;
}*/