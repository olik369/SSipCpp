#include <bits/stdc++.h>

using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

void QuickSort(int* arr, int start, int end) {
	if (start >= end) return;
	auto pivot = start;
	auto left = start + 1;
	auto right = end;
	while (left <= right) {
		//왼쪽부터 큰것찾기
		while (left <= end && arr[pivot] >= arr[left]) left++;
		//오른쪽부터 작은것찾기
		while (right > start && arr[pivot] <= arr[right]) right--;

		if (left > right) swap(arr[right], arr[pivot]);
		else swap(arr[left], arr[right]);
	}

	QuickSort(arr, start, right - 1);
	QuickSort(arr, right + 1, end);
}

int main() {
	QuickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}