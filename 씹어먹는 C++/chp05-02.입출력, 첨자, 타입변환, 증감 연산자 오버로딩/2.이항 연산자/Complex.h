#pragma once
#include <iostream>
using namespace std;
class Complex {
private:
	double real, img;

public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);

	//Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;

	/*Complex operator+(const char* str);
	Complex operator-(const char* str) const;
	Complex operator*(const char* str) const;
	Complex operator/(const char* str) const;*/

	Complex& operator=(const Complex& c);
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

	void println() const;

	//C++�� a(���׿�����@)b��
	//1. a.operator@(b) Ȥ�� 2. operator@(a,b)�� �� ������ ��츦 �����ؼ� ó����
	
	//���� �� �Լ��� Complex Ŭ������ ģ���̹Ƿ� private��� ������ ���� ����!
	friend Complex operator+(const Complex& a, const Complex& b);
	friend ostream& operator<<(ostream& os, const Complex& c);
private:
	double get_number(const char* str, int from, int to) const;
};