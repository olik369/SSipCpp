#pragma once
#include <iostream>

class SelfString {
private:
	const char* char_arr;
	int char_size;

public:
	//0. 기본 생성자
	SelfString() { char_size = 0; }

	//1. 문자열 만드는 생성자
	SelfString(const char* source) : char_arr(source) {
		char cur_char = *source;
		while (cur_char != NULL) {
			char_size++;
			cur_char = *(source + sizeof(char));
		}
	}

	//2. 문자열 길이를 구하는 함수
	int StringSize();

	//3. 문자열 뒤에 다른 문자열 붙이기
	SelfString& ConnectString(SelfString& str);

	//4. 문자열 내에 포함되어 있는 문자열 구하기
	void FindString(SelfString& str);

	//5. 문자열이 같은지 비교
	static void CompareString(SelfString& str1, SelfString& str2);

	//6. 문자열 크기 비교(사전 순)
	static void CompareStringSize(SelfString& str1, SelfString& str2);
};

int SelfString::StringSize() {
	return this->char_size;
}

SelfString& SelfString::ConnectString(SelfString& str) {
	SelfString new_str;
	int str_size = this->char_size + str.StringSize();
	return new_str;
}