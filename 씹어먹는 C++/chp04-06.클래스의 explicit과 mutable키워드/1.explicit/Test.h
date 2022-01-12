#pragma once

class A {
	mutable int data_;

public:
	A(int data) : data_(data) {}
	void DoSomething(int x) const;
	void PrintData() const;
};