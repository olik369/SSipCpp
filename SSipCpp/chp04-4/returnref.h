#pragma once
#include <iostream>

using namespace std;

class A {
	int x;

public:
	A(int c) : x(c) {}

	int& access_x() { return x; }
	int get_x() { return x; }
	void show_x() { cout << x << endl; }
};