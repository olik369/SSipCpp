#include <bits/stdc++.h>
using namespace std;

//0,1�϶��� ���ϱ� �׿ܿ��� ������ ���ϱ�
string num;
vector<int> Num;

int main() {
	cin >> num;
	
	for (int i = 0; i < (int)num.length(); i++) {
		auto x = num[i] - '0';
		Num.push_back(x);
	}

	int result = Num[0];

	for (int i = 1; i < (int)Num.size(); i++) {
		if (result <= 1 || Num[i] <= 1) {
			result = result + Num[i];
		}
		else { result = result * Num[i]; }
	}

	cout << result << endl;
	
	return 0;
}