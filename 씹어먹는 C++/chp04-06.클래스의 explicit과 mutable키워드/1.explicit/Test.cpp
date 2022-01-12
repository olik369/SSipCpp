#include "Test.h"
#include <bits/stdc++.h>

using namespace std;

void A::DoSomething(int x) const {
	data_ = x;
}

void A::PrintData() const {
	cout << "data: " << data_ << endl;
}