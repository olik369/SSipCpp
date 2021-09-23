#include <bits/stdc++.h>
#define MAX_VALUE 1000000

using namespace std;

int n, m;
int arr[MAX_VALUE + 1];	//왜냐하면 가장 작은 부품이 1이므로 1~1,000,000인덱스를 가져야함

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x] += 1;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;

		if (arr[target] > 0) {
			cout << "yes" << ' ';
		}
		else {
			cout << "no" << ' ';
		}
	}

	return 0;
}