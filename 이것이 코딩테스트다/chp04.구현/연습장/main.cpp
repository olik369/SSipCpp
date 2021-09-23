#include <bits/stdc++.h>

using namespace std;

int getMinimumMoves(vector<int> arr) {
	int n = arr.size();
	vector<bool> d(n, false);
	int minNum = 1e6;
	int minIndex = -1;
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < minNum) {
			minNum = arr[i];
			minIndex = i;
		}
	}
	result += minIndex;

	for (int i = 0; i < minIndex; i++) {
		d[i] = true;
		for (int j = minIndex + 1; j < n; j++) {
			if (d[j] == false && arr[i] < arr[j]) {
				d[j] = true;
				result++;
			}
		}
	}

	return result;
}

int main() {

}