#include <bits/stdc++.h>
using namespace std;

void recursiveFunction(int i) {
	//100��° ȣ���� ���� �� ����ǵ��� ���� ���� ���
	if (i == 100) return;
	cout << i << "��° ��� �Լ����� " << i + 1 << "��° ����Լ��� ȣ���մϴ�." << endl;
	recursiveFunction(i + 1);
	cout << i << "��° ��� �Լ��� �����մϴ�." << endl;
}

int main() {
	recursiveFunction(1);

	return 0;
}