#include "Int.h"
#include <iostream>

using namespace std;

Test& Test::operator++()
{
	x = x + 1;
	cout << "���� ���� ������" << endl;
	return *this;
}

Test Test::operator++(int)
{
	Test temp(*this);
	x = x + 1;
	cout << "���� ���� ������" << endl;
	return temp;
}

void func(const Test& t)
{
	cout << "x : " << t.get_x() << endl;
}
