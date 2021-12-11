#pragma once
#include <iostream>

class SelfString {
private:
	const char* char_arr;
	int char_size;

public:
	//0. �⺻ ������
	SelfString() { char_size = 0; }

	//1. ���ڿ� ����� ������
	SelfString(const char* source) : char_arr(source) {
		char cur_char = *source;
		while (cur_char != NULL) {
			char_size++;
			cur_char = *(source + sizeof(char));
		}
	}

	//2. ���ڿ� ���̸� ���ϴ� �Լ�
	int StringSize();

	//3. ���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�
	SelfString& ConnectString(SelfString& str);

	//4. ���ڿ� ���� ���ԵǾ� �ִ� ���ڿ� ���ϱ�
	void FindString(SelfString& str);

	//5. ���ڿ��� ������ ��
	static void CompareString(SelfString& str1, SelfString& str2);

	//6. ���ڿ� ũ�� ��(���� ��)
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