#include <bits/stdc++.h>

using namespace std;

//���� ����� �����ϱ� ���� �迭
long long d[100];

long long fibo(int x) {
	if (x == 1 || x == 2) {
		return 1;
	}

	//�̹� ����� �� �ִ� ������� �״�� ��ȯ
	if (d[x] != 0) {
		return d[x];
	}
	else {
		d[x] = fibo(x - 1) + fibo(x - 2);
		return d[x];
	}
}

int main() {
	cout << fibo(60) << endl;

	return 0;
}