#pragma once

class A {
private:
	void private_func() {}
	int private_num;
	int x;

	// B는 A의 친구
	friend class B;

	// func는 A의 친구
	friend void func();
};

class B {
private:
	int y;

public:
	void b();
};