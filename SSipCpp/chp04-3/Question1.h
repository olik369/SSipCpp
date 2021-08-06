#pragma once
#include <iostream>
#include <string.h>

/*
* 문제 1
아래와 같은 문자열 클래스를 완성해보세요 (난이도 : 中)
실패 ㅜㅜ
*/

class String {
public:
	char* str;
	int len;

public:
	String(char c, int n);
	String(const char* s);
	String(const String& s);
	~String();

	void AddString(const String& s);
	void CopyString(const String& s);
	int Strlen();
};

String::String(char c, int n) {
	len = n;
	str = new char[n + 1];
	for (int i = 0; i < n; i++) {
		str[i] = c;
	}
}

String::String(const char* s) {
	len = 0;
	//const char* temp = s;
	while (s != NULL) {
		len++;
		s++;
	}
	s -= len;
	str = new char[len + 1];
	//strcpy(str, s);
	for (int i = 0; i < len; i++) {
		str[i] = s[i];
	}
	str[len] = '\0';
}

String::String(const String& s) {
	len = s.len;
	str = new char[s.len + 1];
	strcpy(str, s.str);
}

String::~String() {
	if (str != NULL) {
		delete[] str;
	}
}

/*
* void AddString(const string& s);
	void CopyString(const string& s);
	int strlen();
*/

void String::AddString(const String& s) {
	const char* temp = str;
	str = new char[len + s.len + 1];
	for (int i = 0; i < len; i++) {
		str[i] = temp[i];
	}

	for (int i = 0; i < s.len; i++) {
		str[i + len] = s.str[i];
	}

	str[len + s.len] = '\0';
	len = len + s.len + 1;
}

void String::CopyString(const String& s) {
	len = s.len;
	str = new char[s.len + 1];
	strcpy(str, s.str);
}

int String::Strlen() {
	return len;
}