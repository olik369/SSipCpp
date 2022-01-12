#pragma once

#include <iostream>

using namespace std;

int strlength(const char* str) {
	int string_length = 0;
	while (str[string_length]) {
		string_length++;
	}
	return string_length;
}

class MyString {
	char* string_content;	//문자열 데이터를 가리키는 포인터
	int string_length;		//문자열 길이
	int memory_capacity;	//할당된 공간

public:
	// capacity 만큼 미리 할당함
	explicit MyString(int capacity);

	//문자 하나로 생성
	explicit MyString(char c);

	//문자열로 부터 생성
	MyString(const char* str);

	//복사 생성자
	MyString(const MyString& str);

	//소멸자
	~MyString();

	//문자열 길이 리턴하는 함수
	int length() const;
	//문자열 저장가능 공간 리턴하는 함수
	int capacity() const;
	//문자열 저장가능 공간 미리 할당하는 함수
	void reserve(int size);

	//문자열을 출력하는 함수(개행 X)
	void print() const;
	//문자열을 출력하는 함수(개행 O)
	void println() const;
	//임의의 위치의 문자를 리턴하는 함수
	char at(int i) const;

	//'=' 지정하는 함수
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	//중간에 문자열 삽입하는 함수
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);

	//문자열을 지우는 함수
	MyString& erase(int loc, int num);

	//찾고자 하는 문자열의 위치를 리턴하는 함수
	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	//사전식으로 배열해서 어떤 문자열이 더 뒤에 오는지 판단하는 함수(크기 비교함수)
	int compare(const MyString& str) const;
};

MyString::MyString(int capacity) {
	string_content = new char[capacity];
	string_length = 0;
	memory_capacity = capacity;
	cout << "Capacity : " << capacity << endl;
}

MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
	memory_capacity = 1;
}

MyString::MyString(const char* str)
{
	string_length = strlength(str);
	string_content = new char[string_length];
	memory_capacity = string_length;

	for (int i = 0; i < string_length; i++) {
		string_content[i] = str[i];
	}
}

MyString::MyString(const MyString& str)
{
	string_length = str.string_length;
	string_content = new char[string_length];
	memory_capacity = string_length;

	for (int i = 0; i < string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }

int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_str_content = string_content;
		string_content = new char[size];
		memory_capacity = size;

		//기존 공간에 있던 문자열 복붙하기
		for (int i = 0; i < string_length; i++) {
			string_content[i] = prev_str_content[i];
		}

		//기존 할당한 공간 지우기
		delete[] prev_str_content;
	}
}

void MyString::print() const {
	for (int i = 0; i < string_length; i++) {
		cout << string_content[i];
	}
}

void MyString::println() const {
	for (int i = 0; i < string_length; i++) {
		cout << string_content[i];
	}

	cout << endl;
}

char MyString::at(int i) const {
	if (i >= 0 || i < string_length) {
		return string_content[i];
	}
	else {
		return NULL;
	}
}

MyString& MyString::assign(const MyString& str) {
	//만약 할당된 공간보다 긴 문자열을 할당해야 할때는 공간을 재할당함
	if (str.string_length > memory_capacity) {
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	//할당할 공간보다 크면 굳이 새로 할당하지 않고 기존 공간에 새로운 문자를 집어넣고 그 이후의 문자는
	//읽어들이지 않게끔하면 깔끔함!

	string_length = str.string_length;

	for (int i = 0; i < string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	return *this;
}

MyString& MyString::assign(const char* str) {
	//새로운 문자열 길이는 캐싱함
	int new_strlen = strlength(str);
	if (new_strlen > memory_capacity) {
		delete[] string_content;
		string_content = new char[new_strlen];
		memory_capacity = new_strlen;
	}

	string_length = new_strlen;

	for (int i = 0; i < string_length; i++) {
		string_content[i] = str[i];
	}
	return *this;
}

MyString& MyString::insert(int loc, const MyString& str) {
	//만약 범위를 벗어난 곳에서 문자열 삽입을 할 시 수행하지 않음
	if (loc < 0 || loc > string_length) return *this;

	MyString temp(*this);
	int new_strlen = string_length + str.string_length;

	//만약 새로운 문자열 길이가 할당된 저장공간보다 크면 새로운 크기의 공간을 할당함
	if (new_strlen > memory_capacity) {
		//한 글자씩 삽입할때 굳이 한칸씩 공간을 늘리면 계속 동적할당을 시도때도 없이 하기 때문에
		//여유있게 현재 공간의 2배를 할당하도록 하거나 그 이상일경우에는 그 글자 길이만큼 공간이 늘어나게
		//코드를 작성함
		if (new_strlen > 2 * memory_capacity) {
			this->reserve(new_strlen);
		}
		else {
			this->reserve(2 * memory_capacity);
		}
	}

	for (int i = 0; i < str.string_length; i++) {
		string_content[i + loc] = str.string_content[i];
	}

	for (int i = 0; i < (new_strlen - loc - str.string_length); i++) {
		string_content[i + loc + str.string_length] = temp.at(i + loc);
	}
	string_length = new_strlen;

	return *this;
}

MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
	//범위를 벗어나거나 지울갯수를 음수로 적는 경우 예외처리
	if (num < 0 || loc < 0 || loc >= string_length) return *this;
	//현재 위치부터 지우는 갯수를 고려할때 문자열끝보다 넘어갈때 처리
	else if ((loc + num) >= string_length) {
		string_length = loc;
		return *this;
	}

	for (int i = 0; i < num; i++) {
		string_content[i + loc] = string_content[i + loc + num];
	}
	string_length -= num;

	return *this;
}

int MyString::find(int find_from, MyString& str) const {
	for (int i = find_from; i < string_length; i++) {
		if (string_content[i] == str.at(0)) {
			for (int j = 1; j < str.string_length; j++) {
				if (string_content[i + j] != str.at(j)) break;

				if (j == (str.string_length - 1)) return i;
			}
		}
	}
	return -1;
}

int MyString::find(int find_from, const char* str) const {
	MyString temp(str);
	return find(find_from, temp);
}

int MyString::find(int find_from, char c) const {
	MyString temp(c);
	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
	// (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
	// 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
	// 이 같다는 의미, -1 은 (*this) 가 사전식으로 더 앞에 온다는 의미이다.

	for (int i = 0; i < min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i]) return 1;
		else if (string_content[i] < str.string_content[i]) return -1;
	}

	//글자수가 많은 경우가 더 뒤에 오게 됨
	if (string_length == str.string_length) return 0;
	else if (string_length > str.string_length) return 1;
	else return -1;
}

void DoSomethingWithString(MyString s) {
	// Do something...
}