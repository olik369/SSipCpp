#include <bits/stdc++.h>

using namespace std;

int arr[30001];
int X;

int main() {
	cin >> X;

	//1�� 0�̰� 2���� ��ȭ���� ���� ��
	for (int i = 2; i <= X; i++) {
		arr[i] = arr[i - 1] + 1;

		//2,3,5�� ����϶� 1�� ���� ��� �����ϴ°� ������ �ƴ��� Ȯ��
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}

		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}

		if (i % 5 == 0) {
			arr[i] = min(arr[i], arr[i / 5] + 1);
		}
	}

	cout << arr[X] << endl;

	return 0;
}