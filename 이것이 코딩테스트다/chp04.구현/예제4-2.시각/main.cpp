#include <bits/stdc++.h>
using namespace std;

int N;
int result;

bool CheckClock(int H, int M, int S) {
	if (H % 10 == 3 || M % 10 == 3 || M / 10 == 3 || S % 10 == 3 || S / 10 == 3) {
		return true;
	}
	else { return false; }
}

int main() {
	cin >> N;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				if (CheckClock(i, j, k) == true) {
					result++;
				}
			}
		}
	}

	cout << result << endl;
	return 0;
}