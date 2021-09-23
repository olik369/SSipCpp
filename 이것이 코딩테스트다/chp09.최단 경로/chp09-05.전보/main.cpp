#include <bits/stdc++.h>
#define INF (int)1e9
#define MAX_NODE (int)30000

using namespace std;

int n, m, c;	//c는 출발점
vector<pair<int, int>> graph[MAX_NODE + 1];	//graph[from] = {to, cost}
int d[MAX_NODE + 1];

void Dijkstra(int start) {
	priority_queue<pair<int, int>> pq;	//{cost, to}
	d[start] = 0;
	pq.push({ 0,start });

	while (pq.empty() == false) {
		int dist = -pq.top().first;
		int nowIndex = pq.top().second;
		pq.pop();

		if (d[nowIndex] < dist) continue;

		for (int i = 0; i < graph[nowIndex].size(); i++) {
			int otherIndex = graph[nowIndex][i].first;
			int cost = d[nowIndex] + graph[nowIndex][i].second;
			if (cost < d[otherIndex]) {
				d[otherIndex] = cost;
				pq.push({ -cost,otherIndex });
			}
		}
	}
}

int main() {
	//입력값 받기
	cin >> n >> m >> c;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to,cost });
	}

	//무한대의 값으로 초기화
	fill(d, d + MAX_NODE + 1, INF);

	Dijkstra(c);

	//결과값 출력
	int count = 0;
	int maxTime = 0;
	for (int i = 1; i <= n; i++) {
		auto cost = d[i];
		if (cost == INF || cost == 0) continue;

		count += 1;
		maxTime = max(maxTime, cost);
	}
	cout << count << ' ' << maxTime << endl;
}