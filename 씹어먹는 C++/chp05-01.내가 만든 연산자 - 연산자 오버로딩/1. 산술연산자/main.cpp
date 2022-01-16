#include "MyString.h"
#include "Complex.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
	/*
	MyString str1("a word");
	MyString str2("sentence");
	MyString str3("sentence");

	if (str1 == str2)
		cout << "str1 와 str2는 같다." << endl;
	else
		cout << "str1 와 str2는 다르다." << endl;

	if (str2 == str3)
		cout << "str2 와 str3는 같다." << endl;
	else
		cout << "str2 와 str3는 다르다." << endl;

	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);
	Complex c(0.0, 0.0);
	a += b;
	a.println();
	b.println();
	*/
	Complex a(0, 0);
	a = a + "-1.1+i3.923";
	a.println();
	a = a - "1.2-i1.823";
	a.println();
	a = a * "2.3+i22";
	a.println();
	a = a / "-12+i55";
	a.println();

	return 0;
}