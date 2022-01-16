#pragma once

class MyString {
	char* string_content;	//문자열 데이터를 가리키는 포인터
	int string_length;		//문자열 길이

	int memory_capacity;	//현재 동적할당된 용량

public:
	//문자 하나로 생성
	MyString(char c);

	//문자열로 생성
	MyString(const char* str);

	//복사 생성자
	MyString(const MyString& str);

	~MyString();

	int length() const;
	int capacity() const;
	void reserve(int size);

	void print() const;
	void println() const;

	char at(int i) const;

	int compare(MyString& str);
	bool operator==(MyString& str);
};