#include <bits/stdc++.h>
#define MAX_NODE (int)1e5
using namespace std;

int n, m;
int parent[MAX_NODE + 1];

int findParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int input, from, to;
		cin >> input >> from >> to;
		if (input == 0) {
			unionParent(from, to);
		}
		else if (input == 1) {
			if (findParent(from) == findParent(to)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}

	return 0;
}