#include <bits/stdc++.h>
using namespace std;

string str;

int count0 = 0, count1 = 0;	//count0 : ���� 0���� �ٲٴ� Ƚ��, count1 : ���� 1�� �ٲٴ� Ƚ��

int main() {
	cin >> str;

	if (str[0] == '1') {
		count0++;
	}
	else {
		count1++;
	}

	for (int i = 0; i < (int)(str.size() - 1); i++) {
		if (str[i] != str[i + 1]) {
			if (str[i + 1] == '1') {
				count0++;
			}
			else {
				count1++;
			}
		}
	}

	cout << min(count0, count1) << endl;
	return 0;
}