#include <bits/stdc++.h>
using namespace std;

int N, x = 1, y = 1;
char moveTypes[4] = { 'L','R','U','D' };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
string plans;


int main() {
	cin >> N;
	cin.ignore();
	getline(cin, plans);

	for (int i = 0; i < (int)plans.length(); i++) {
		
		auto nx = -1, ny = -1;
		
		for (int j = 0; j < 4; j++ ) {
			if (moveTypes[j] == plans[i]) {
				nx = x + dx[j];
				ny = y + dy[j];
				break;
			}
		}
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
			x = nx;
			y = ny;
		}
	}

	cout << x << ' ' << y << endl;
	return 0;
}