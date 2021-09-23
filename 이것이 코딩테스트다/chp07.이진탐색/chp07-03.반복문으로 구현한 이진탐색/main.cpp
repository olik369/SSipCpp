#include <bits/stdc++.h>

using namespace std;

//���� Ž�� �ҽ��ڵ� ����(�ݺ���)
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
		cout << "ã���� �ϴ� ���Ҵ� �������� �ʽ��ϴ�." << endl;
	}
	else {
		cout << result + 1 << endl;
	}

	return 0;
}