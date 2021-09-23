#include <bits/stdc++.h>

using namespace std;

string S;
int numResult;
vector<char> strResult;

int main() {
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		if (S[i] >= '0' && S[i] <= '9') {
			numResult += S[i] - '0';
		}
		else {
			strResult.push_back(S[i]);
		}
	}
	sort(strResult.begin(), strResult.end());

	for (int i = 0; i < strResult.size(); i++) {
		cout << strResult[i];
	}
	cout << numResult;

	return 0;
}