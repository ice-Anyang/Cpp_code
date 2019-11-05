#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
class String
{
	friend ostream& operator<<(ostream &out, const String &s);
public:
	String(char *str = "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if (this != &s)
		{
			free(m_data);
			m_data = new char[strlen(s.m_data) + 1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		delete[]m_data;
		m_data = NULL;
	}
public:
	int length()const
	{
		return strlen(m_data);
	}
public:
	char operator[](int i)
	{
		assert(i >= 0 && i<length());
		return m_data[i];
	}
	String operator+(const String &s)
	{
		int total_size = length() + s.length() + 1;
		char *tmp = new char[total_size];
		strcpy(tmp, m_data);
		strcat(tmp, s.m_data);
		String tmps(tmp);
		delete[]tmp;
		return tmps;
	}
	String& operator+=(const String &s)
	{
		int new_size = length() + s.length() + 1;
		char *tmp = new char[new_size];
		strcpy(tmp, m_data);
		strcat(tmp, s.m_data);
		delete[]m_data;
		m_data = tmp;
		return *this;
	}
public:
	bool operator==(const String &s)
	{
		if (strcmp(m_data, s.m_data) == 0)
			return true;
		return false;
	}
	bool operator!=(const String &s)
	{
		return !(*this == s);
	}
	bool operator>(const String &s)
	{
		if (strcmp(m_data, s.m_data) == 1)
			return true;
		return false;
	}
	bool operator<(const String &s)
	{
		if (strcmp(m_data, s.m_data) == -1)
			return true;
		return false;
	}
	bool operator>=(const String &s)
	{
		return !(*this < s);
	}
	bool operator<=(const String &s)
	{
		return !(*this > s);
	}
private:
	char *m_data;
};
ostream& operator<<(ostream &out, const String &s)
{
	out << s.m_data;
	return out;
}
int main()
{
	String s1("Hello"); //s1[0] ==> H
	String s2("Bit.");
	for (int i = 0; i<s1.length(); ++i)
		cout << s1[i];
	cout << endl;
	//String s = s1 + s2; //s = HelloBit
	//cout << s1 << endl;
	s1 += s2;  
	//cout<<s1<<endl;//
	/*if(s1 == s2)
	cout<<"s1 == s2"<<endl;
	if(s1 != s2)
	cout<<"s1 != s2"<<endl;
	if(s1 > s2)
	cout<<"s1 > s2"<<endl;
	if(s1 < s2)
	cout<<"s1 < s2"<<endl;
	if(s1 >= s2)
	cout<<"s1 >= s2"<<endl;
	if(s1 <= s2)
	cout<<"s1 <= s2"<<endl;
	*/
	return 0;
	}