#include <bits/stdc++.h>

using namespace std;

int arr[30001];
int X;

int main() {
	cin >> X;

	//1은 0이고 2부터 점화식이 적용 됨
	for (int i = 2; i <= X; i++) {
		arr[i] = arr[i - 1] + 1;

		//2,3,5의 배수일때 1을 빼고서 계속 연산하는게 빠른지 아닌지 확인
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