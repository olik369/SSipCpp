#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}