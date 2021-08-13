#include <bits/stdc++.h>
using namespace std;

//�ݺ������� ������ n!
int FactorialIterative(int n) {
	int result = 1;

	//1���� n������ ���� ���ʴ�� ���ϱ�
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

//��������� ������ n!
int FactorialRecursive(int n) {
	//n�� 1 ������ ��� 1�� ��ȯ
	if (n <= 1) return 1;
	//n! = n * (n - 1)!�� �״�� �ڵ�� �ۼ��ϱ�
	else return n * FactorialRecursive(n - 1);
}

int main() {
	//������ ������� ������ n! ���(n = 5)
	cout << "�ݺ������� ���� : " << FactorialIterative(5) << endl;
	cout << "��������� ���� : " << FactorialRecursive(5) << endl;

	return 0;
}