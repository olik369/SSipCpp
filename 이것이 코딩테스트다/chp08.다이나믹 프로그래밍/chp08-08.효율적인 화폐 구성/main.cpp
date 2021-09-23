#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	vector<int> d(M + 1, 10001);

	d[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = arr[i]; j <= M; j++) {
			if (d[j - arr[i]] != 10001) {
				d[j] = min(d[j], d[j - arr[i]] + 1);
			}
		}
	}

	if (d[M] == 10001) {
		cout << -1 << endl;
	}
	else {
		cout << d[M] << endl;
	}

	return 0;
}