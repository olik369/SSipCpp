#include <bits/stdc++.h>

using namespace std;
int N, K;
vector<int> A, B;

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		A.push_back(x);
	}
	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		B.push_back(x);
	}
	sort(B.begin(), B.end());
	
	for (int i = 0; i < K; i++) {
		if (A[i] < B[N - 1 - i]) {
			swap(A[i], B[N - 1 - i]);
			/*auto temp = A[i];
			A[i] = B[N - 1 - i];
			B[N - 1 - i] = temp;*/
		}
		else break;
	}

	long long result = 0;
	for (int i = 0; i < N; i++) {
		result += A[i];
	}
	cout << result;

	return 0;
}