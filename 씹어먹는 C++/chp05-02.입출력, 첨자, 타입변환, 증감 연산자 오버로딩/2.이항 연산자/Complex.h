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

	//C++은 a(이항연산자@)b를
	//1. a.operator@(b) 혹은 2. operator@(a,b)둘 중 가능한 경우를 선택해서 처리함
	
	//이제 이 함수는 Complex 클래스의 친구이므로 private멤버 변수에 접근 가능!
	friend Complex operator+(const Complex& a, const Complex& b);
	friend ostream& operator<<(ostream& os, const Complex& c);
private:
	double get_number(const char* str, int from, int to) const;
};