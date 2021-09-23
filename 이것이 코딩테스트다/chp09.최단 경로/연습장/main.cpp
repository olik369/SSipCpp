#include <bits/stdc++.h>
#define MAX_NODE (int)1e5
#define INF (int)1e9

using namespace std;

int n, m, start;
vector<pair<int, int>> graph[MAX_NODE + 1];	//graph[from] = {to, cost}
int d[MAX_NODE + 1];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;	//{cost, to}
	pq.push({ 0,start });
	d[start] = 0;
	
	while (pq.empty() == false) {
		int dist = -pq.top().first;
		int nowIndex = pq.top().second;
		pq.pop();

		if (d[nowIndex] < dist) continue;

		for (int i = 0; i < graph[nowIndex].size(); i++) {
			int otherIndex = graph[nowIndex][i].first;
			int cost = d[nowIndex] + graph[nowIndex][i].second;
			if (cost < d[otherIndex]) {
				pq.push({ -cost,otherIndex });
				d[otherIndex] = cost;
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;

	fill(d, d + MAX_NODE + 1, INF);

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to,cost });
	}

	dijkstra(start);

	for (int i = 1; i <= n; i++) {
		if (d[i] != INF) {
			cout << d[i] << endl;
		}
		else {
			cout << "INFINITY" << endl;
		}
	}

	return 0;
}