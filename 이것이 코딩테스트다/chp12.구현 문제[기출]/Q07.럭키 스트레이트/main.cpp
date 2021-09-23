#include <bits/stdc++.h>

using namespace std;

string N;

int main() {
	cin >> N;

	int length = N.length();
	
	int front = 0;
	for (int i = 0; i < length / 2; i++) {
		int x = N[i] - '0';
		front += x;
	}

	int rear = 0;
	for (int i = length / 2; i < length; i++) {
		int x = N[i] - '0';
		rear += x;
	}

	if (front == rear) {
		cout << "LUCKY" << endl;
	}
	else {
		cout << "READY" << endl;
	}
	return 0;
}