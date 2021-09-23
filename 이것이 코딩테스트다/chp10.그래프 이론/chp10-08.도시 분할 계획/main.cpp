#include <bits/stdc++.h>
#define MAX_NODE (int)1e5
using namespace std;

vector<pair<int, pair<int, int>>> edges;
int parent[MAX_NODE + 1];
int N, M;

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

void kruskal() {
	int totalCost = 0;
	int maxCost = 0;
	for (int i = 0; i < edges.size(); i++) {
		int nowIndex = edges[i].second.first;
		int toIndex = edges[i].second.second;
		int cost = edges[i].first;
		if (findParent(nowIndex) != findParent(toIndex)) {
			totalCost += cost;
			maxCost = cost;
			unionParent(nowIndex, toIndex);
		}
	}

	cout << totalCost - maxCost << endl;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edges.push_back({ cost,{from,to} });
	}
	sort(edges.begin(), edges.end());

	kruskal();

	return 0;
}