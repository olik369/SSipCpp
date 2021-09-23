#include <bits/stdc++.h>

using namespace std;

int N;

int d[101];	//최대 100칸의 식량창고가 있음
int food[101];

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		food[i] = x;
	}

	d[1] = food[1];
	d[2] = max(d[1], food[2]);
	for (int i = 3; i <= N; i++) {
		d[i] = max(d[i - 2] + food[i], d[i - 1]);
	}

	cout << d[N] << endl;

	return 0;
}