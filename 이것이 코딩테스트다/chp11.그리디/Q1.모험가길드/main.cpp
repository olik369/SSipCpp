#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adventureGroup;

int main() {
	//���谡�� �� �Է�
	cin >> N;

	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		adventureGroup.push_back(X);
	}

	sort(adventureGroup.begin(), adventureGroup.end());

	//���� ���� �׷��� �ο���
	int count = 0;
	//�Ἲ�� �׷� ��
	int result = 0;

	for (int i = 0; i < N; i++) {
		count++;
		if (adventureGroup[i] <= count) {
			result++;
			count = 0;
		}
	}

	cout << result << endl;
	return 0;
}