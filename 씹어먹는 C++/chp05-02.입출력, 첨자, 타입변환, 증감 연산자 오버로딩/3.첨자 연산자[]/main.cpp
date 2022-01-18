#include "MyString.h"
#include "Int.h"
#include <iostream>

using namespace std;

int main() {
	Test t(3);

	func(++t);
	func(t++);
	cout << "x : " << t.get_x() << endl;
}