#include <bits/stdc++.h>

using namespace std;

int arr[10] = { 9,1,2,7,4,0,5,6,7,4 };
int n = 10;

int main() {
	for (int i = 0; i < n; i++) {
		auto minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}