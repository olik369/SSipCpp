#include <bits/stdc++.h>
using namespace std;

//���� ����
int N;
//������ �޾Ƶ��� ����
vector<int> coins;

int main() {
	int target = 1;	//ó�� Ÿ�ٰ� 1
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		coins.push_back(x);
	}
	sort(coins.begin(), coins.end());

	for (int i = 0; i < N; i++) {
		if (coins[i] <= target) {
			target += coins[i];
		}
		else break;
	}

	cout << target << endl;
}