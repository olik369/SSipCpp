#pragma once

class MyString {
	char* string_content;  // ���ڿ� �����͸� ����Ű�� ������
	int string_length;     // ���ڿ� ����

	int memory_capacity;  // ���� �Ҵ�� �뷮

public:
	// ���� �ϳ��� ����
	MyString(char c);

	// ���ڿ��� ���� ����
	MyString(const char* str);

	// ���� ������
	MyString(const MyString& str);

	~MyString();

	int length();

	void print() const;
	void println() const;

	char& operator[](const int index);
};