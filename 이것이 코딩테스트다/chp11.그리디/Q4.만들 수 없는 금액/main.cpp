#include <bits/stdc++.h>
using namespace std;

//동전 갯수
int N;
//동전을 받아들일 벡터
vector<int> coins;

int main() {
	int target = 1;	//처음 타겟값 1
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