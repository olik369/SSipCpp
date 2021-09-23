#include <bits/stdc++.h>
#define INF (int)1e9
#define MAX_NODE (int)1e5
using namespace std;

int n, m, start;
vector<pair<int, int>> graph[MAX_NODE + 1];
int d[MAX_NODE + 1];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	//시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
	pq.push({ 0,start });
	d[start] = 0;
	while (pq.empty() == false) {
		int dist = -pq.top().first;	//C++에서는 최대힙기반으로 우선순위 큐가 짜여져 있어서 -를 붙임
		int nowIndex = pq.top().second;
		pq.pop();
		//현재 노드가 이미 처리된 적이 있다면 무시
		if (d[nowIndex] < dist) continue;	//방문을 한것이라면 저장된 최소거리가 큐에 있는 거리보다 크거나 같으므로
		//현재 노드가 연결된 다른 인접한 노드들을 확인
		for (int i = 0; i < (int)graph[nowIndex].size(); i++) {
			int cost = d[nowIndex] + graph[nowIndex][i].second;	//거리비용은 second에 저장함
			if (cost < d[graph[nowIndex][i].first]) {
				pq.push(make_pair(-cost, graph[nowIndex][i].first));
				d[graph[nowIndex][i].first] = cost;
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to,cost });
	}

	//최단 거리 테이블을 모두 무한으로 초기화
	fill(d, d + MAX_NODE + 1, INF);

	//다익스트라 알고리즘을 수행
	dijkstra(start);

	//모든 노드로 가기 위한 최단 거리를 출력
	for (int i = 1; i <= n; i++) {
		auto totalCost = d[i];

		if (totalCost != INF) {
			cout << d[i] << endl;
		}
		else {
			cout << "INFINITY" << endl;
		}
	}

	return 0;
}