#pragma once

#include <iostream>
/*
* Wrapper Ŭ������ ���𰡸� �����ϴ� Ŭ������� �ǹ���
* C++������ ���α׷��� �� �� ���� �⺻ �ڷ������� ��ü�ν� �ٷ��� �� ���� ����
* �̷� ��, �⺻ �ڷ������� Ŭ������ �����ؼ� ������ �ڷ����� ��ü�� ����ϴ� ���� Wrapper Ŭ����
* 
* �׷���, Wrapper Ŭ������ ����Ҷ� ������ �⺻ �ڷ����鿡 �����ϴ� �����ڸ� �������ؾߵǴ� ����
* �ʹ����� ������ ��!!!
* �׷���, Ÿ�� ��ȯ �����ڸ� �����
* ���� : operator (��ȯ �ϰ��� �ϴ� Ÿ��) ()
*/
class Int
{
	int data;
	// some other data
public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}
	
	operator int() { return data; }
};

