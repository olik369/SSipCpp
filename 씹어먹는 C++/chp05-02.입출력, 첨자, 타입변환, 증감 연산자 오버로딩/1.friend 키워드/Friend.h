#pragma once

class A {
private:
	void private_func() {}
	int private_num;
	int x;

	// B绰 A狼 模备
	friend class B;

	// func绰 A狼 模备
	friend void func();
};

class B {
private:
	int y;

public:
	void b();
};