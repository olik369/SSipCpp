#pragma once
class Int
{
	int data;
	//some other data

public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}

	//타입 변환 연산자
	//operator (변환하고자 하는 타입) ()
	operator int() { return data; }
};

class Test {
	int x;

public:
	Test(int x) : x(x) {}
	Test(const Test& t) : x(t.x) {}

	Test& operator++();
	Test operator++(int);

	int get_x() const {
		return x;
	}
};

void func(const Test& t);