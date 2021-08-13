#include <bits/stdc++.h>
using namespace std;

int x, y, result;
string curLocation;
int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };

int main() {
	cin >> curLocation;
	x = curLocation[0] - 'a' + 1;
	y = curLocation[1] - '1' + 1;

	for (int i = 0; i < 8; i++) {
		auto nx = x + dx[i];
		auto ny = y + dy[i];

		if (nx >= 1 && ny >= 1 && nx <= 8 && ny <= 8) {
			result++;
		}
	}

	cout << result << endl;
	return 0;
}