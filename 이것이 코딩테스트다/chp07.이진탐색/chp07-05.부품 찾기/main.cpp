#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> arr;

int binarySearch(vector<int>& arr, int target, int start, int end) {
	//찾지 못하면 -1 리턴
	if (start > end) return -1;
	
	int mid = (start + end) / 2;

	if (arr[mid] == target) return 1;
	else if (arr[mid] > target) return binarySearch(arr, target, start, mid - 1);
	else return binarySearch(arr, target, mid + 1, end);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;

		auto result = binarySearch(arr, target, 0, n - 1);

		if (result == -1) {
			cout << "no" << ' ';
		}
		else {
			cout << "yes" << ' ';
		}
	}
}