#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[11];

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr[x]++;
	}

	int result = 0;
	for (int i = 1; i <= M; i++) {
		N = N - arr[i];
		result += arr[i] * N;
	}

	cout << result << endl;
}