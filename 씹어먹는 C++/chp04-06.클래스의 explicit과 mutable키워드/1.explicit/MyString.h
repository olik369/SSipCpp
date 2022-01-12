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
	char* string_content;	//���ڿ� �����͸� ����Ű�� ������
	int string_length;		//���ڿ� ����
	int memory_capacity;	//�Ҵ�� ����

public:
	// capacity ��ŭ �̸� �Ҵ���
	explicit MyString(int capacity);

	//���� �ϳ��� ����
	explicit MyString(char c);

	//���ڿ��� ���� ����
	MyString(const char* str);

	//���� ������
	MyString(const MyString& str);

	//�Ҹ���
	~MyString();

	//���ڿ� ���� �����ϴ� �Լ�
	int length() const;
	//���ڿ� ���尡�� ���� �����ϴ� �Լ�
	int capacity() const;
	//���ڿ� ���尡�� ���� �̸� �Ҵ��ϴ� �Լ�
	void reserve(int size);

	//���ڿ��� ����ϴ� �Լ�(���� X)
	void print() const;
	//���ڿ��� ����ϴ� �Լ�(���� O)
	void println() const;
	//������ ��ġ�� ���ڸ� �����ϴ� �Լ�
	char at(int i) const;

	//'=' �����ϴ� �Լ�
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	//�߰��� ���ڿ� �����ϴ� �Լ�
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);

	//���ڿ��� ����� �Լ�
	MyString& erase(int loc, int num);

	//ã���� �ϴ� ���ڿ��� ��ġ�� �����ϴ� �Լ�
	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	//���������� �迭�ؼ� � ���ڿ��� �� �ڿ� ������ �Ǵ��ϴ� �Լ�(ũ�� ���Լ�)
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

		//���� ������ �ִ� ���ڿ� �����ϱ�
		for (int i = 0; i < string_length; i++) {
			string_content[i] = prev_str_content[i];
		}

		//���� �Ҵ��� ���� �����
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
	//���� �Ҵ�� �������� �� ���ڿ��� �Ҵ��ؾ� �Ҷ��� ������ ���Ҵ���
	if (str.string_length > memory_capacity) {
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	//�Ҵ��� �������� ũ�� ���� ���� �Ҵ����� �ʰ� ���� ������ ���ο� ���ڸ� ����ְ� �� ������ ���ڴ�
	//�о������ �ʰԲ��ϸ� �����!

	string_length = str.string_length;

	for (int i = 0; i < string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	return *this;
}

MyString& MyString::assign(const char* str) {
	//���ο� ���ڿ� ���̴� ĳ����
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
	//���� ������ ��� ������ ���ڿ� ������ �� �� �������� ����
	if (loc < 0 || loc > string_length) return *this;

	MyString temp(*this);
	int new_strlen = string_length + str.string_length;

	//���� ���ο� ���ڿ� ���̰� �Ҵ�� ����������� ũ�� ���ο� ũ���� ������ �Ҵ���
	if (new_strlen > memory_capacity) {
		//�� ���ھ� �����Ҷ� ���� ��ĭ�� ������ �ø��� ��� �����Ҵ��� �õ����� ���� �ϱ� ������
		//�����ְ� ���� ������ 2�踦 �Ҵ��ϵ��� �ϰų� �� �̻��ϰ�쿡�� �� ���� ���̸�ŭ ������ �þ��
		//�ڵ带 �ۼ���
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
	//������ ����ų� ���ﰹ���� ������ ���� ��� ����ó��
	if (num < 0 || loc < 0 || loc >= string_length) return *this;
	//���� ��ġ���� ����� ������ ����Ҷ� ���ڿ������� �Ѿ�� ó��
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
	// (*this) - (str) �� �����ؼ� �� 1, 0, -1 �� �� ����� �����Ѵ�
	// 1 �� (*this) �� ���������� �� �ڿ� �´ٴ� �ǹ�. 0 �� �� ���ڿ�
	// �� ���ٴ� �ǹ�, -1 �� (*this) �� ���������� �� �տ� �´ٴ� �ǹ��̴�.

	for (int i = 0; i < min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i]) return 1;
		else if (string_content[i] < str.string_content[i]) return -1;
	}

	//���ڼ��� ���� ��찡 �� �ڿ� ���� ��
	if (string_length == str.string_length) return 0;
	else if (string_length > str.string_length) return 1;
	else return -1;
}

void DoSomethingWithString(MyString s) {
	// Do something...
}