#include <bits/stdc++.h>
#define MAX_VALUE 1000000

using namespace std;

int n, m;
int arr[MAX_VALUE + 1];	//�ֳ��ϸ� ���� ���� ��ǰ�� 1�̹Ƿ� 1~1,000,000�ε����� ��������

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