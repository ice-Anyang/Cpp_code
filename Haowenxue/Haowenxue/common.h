#pragma once
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm> //ÅÅÐòº¯Êý¿â 
#include<fstream>
using namespace std;

class Student
{
private:
	string number;
	string name;
	int chinese;
	int math;
	int english;
public:
	Student(){}
	~Student(){}

	void setNumber(string Number)
	{
		number = Number;
	}
	string getNumber()
	{
		return number;
	}
	void setName(string Name)
	{
		name = Name;
	}
	string getName()
	{
		return name;
	}
	void setMath(int Math)
	{
		math = Math;
	}
	int getMath()
	{
		return math;
	}
	void setEnglish(int English)
	{
		english = English;
	}
	int getEnglish()
	{
		return english;
	}
	int getSum()
	{
		return math + english;
	}
};
class ScoreManager :public  Student
{
private:
	Student score[100];
	int sum;
	int Select();
	int SearchByNumber(string);
	int SearchByName(string);
	void SortByNumber();
	void SortByName();
	void SortBySum();
	float getAverage();
public:
	ScoreManager(){ sum = 0; }
	~ScoreManager(){}
	void Add();
	void Delete();
	void Update();
	void Search();
	void ShowAll();
	void Sort();
	void Average();
	void PassRate();
};

void menu();