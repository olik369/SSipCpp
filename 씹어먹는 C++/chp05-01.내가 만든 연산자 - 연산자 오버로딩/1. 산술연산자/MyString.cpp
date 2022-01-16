#include "MyString.h"
#include <bits/stdc++.h>

using namespace std;

MyString::MyString(char c)
{
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}

MyString::MyString(const char* str)
{
	string_length = strlen(str);
	memory_capacity = string_length;

	string_content = new char[string_length];
	for (int i = 0; i < string_length; i++) {
		string_content[i] = str[i];
	}
}

MyString::MyString(const MyString& str)
{
	string_length = str.string_length;
	memory_capacity = str.memory_capacity;
	
	string_content = new char[string_length];
	for (int i = 0; i < string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}

MyString::~MyString()
{
	delete[] string_content;
}

int MyString::length() const { return string_length; }

int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size)
{
	if (size > memory_capacity) {
		memory_capacity = size;

		char* prev_string_content = string_content;
		string_content = new char[size];

		for (int i = 0; i < string_length; i++) {
			string_content[i] = prev_string_content[i];
		}

		delete[] prev_string_content;
	}
}

void MyString::print() const
{
	for(int i=0;i<string_length;i++) cout<<string_content[i];
}

void MyString::println() const
{
	for (int i = 0; i < string_length; i++) cout << string_content[i];

	cout << endl;
}

char MyString::at(int i) const
{
	if (i < 0 || i >= string_length) return 0;
	else return string_content[i];
}

int MyString::compare(MyString& str)
{
	// (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
	// 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
	// 이 같다는 의미, -1 은 (*this) 사 사전식으러 더 앞에 온다는 의미이다.
	for (int i = 0; i < min(string_length, str.string_length); i++) {
		if (string_content[i] < str.string_content[i]) 
			return -1;
		else if (string_content[i] > str.string_content[i])
			return 1;
	}

	if (string_length < str.string_length)
		return -1;
	else if (string_length > str.string_length)
		return 1;
	else
		return 0;
}

bool MyString::operator==(MyString& str)
{
	/*if (string_length != str.string_length) return false;
	else {
		for (int i = 0; i < string_length; i++) {
			if (string_content[i] != str.string_content[i])
				return false;
		}
		return true;
	}*/

	return !compare(str);
}
