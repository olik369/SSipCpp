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

	int start = 0;
	int end = 1e9;	//10억
	int result = 0;
	while (start <= end) {
		long long total = 0;
		int mid = (start + end) / 2;

		for (int i = 0; i < N; i++) {
			if (arr[i] > mid) {
				total += arr[i] - mid;
			}
		}

		//남은 떡이 부족할때, 더 작은 높이로(왼쪽 탐색)
		if (total < M) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			result = mid;
		}
	}

	cout << result << endl;
	return 0;
}