#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adventureGroup;

int main() {
	//모험가의 수 입력
	cin >> N;

	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		adventureGroup.push_back(X);
	}

	sort(adventureGroup.begin(), adventureGroup.end());

	//현재 만들 그룹의 인원수
	int count = 0;
	//결성한 그룹 수
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