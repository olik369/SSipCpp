#include <bits/stdc++.h>

using namespace std;

//이진 탐색 소스코드 구현(반복문)
int binarySearch(vector<int>& arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == target) return mid;
		else if (arr[mid] > target) end = mid - 1;
		else start = mid + 1;
	}

	return -1;
}

int n, target;
vector<int> arr;

int main() {
	cin >> n >> target;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	auto result = binarySearch(arr, target, 0, n - 1);

	if (result == -1) {
		cout << "찾고자 하는 원소는 존재하지 않습니다." << endl;
	}
	else {
		cout << result + 1 << endl;
	}

	return 0;
}