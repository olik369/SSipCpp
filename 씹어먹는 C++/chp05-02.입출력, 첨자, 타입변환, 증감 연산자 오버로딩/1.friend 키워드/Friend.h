#pragma once

class A {
private:
	void private_func() {}
	int private_num;
	int x;

	// B�� A�� ģ��
	friend class B;

	// func�� A�� ģ��
	friend void func();
};

class B {
private:
	int y;

public:
	void b();
};