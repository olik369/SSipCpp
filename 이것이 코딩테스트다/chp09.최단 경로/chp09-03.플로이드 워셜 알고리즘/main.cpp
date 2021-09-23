#include <bits/stdc++.h>
#define INF (int)1e9
#define MAX_NODE (int)500
using namespace std;

int n, m;
int graph[MAX_NODE + 1][MAX_NODE + 1];	//최대 노드 갯수 500개

int main() {
	cin >> n >> m;

	//최단 거리 테이블을 모두 무한으로 초기화
	for (int i = 0; i < MAX_NODE + 1; i++) {
		fill(graph[i], graph[i] + MAX_NODE + 1, INF);
	}

	//자기 자신으로 가는 모든 비용은 0으로 초기화
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	//각 간선에 대한 정보를 입력받기
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from][to] = cost;
	}

	//점화식에 따라 플로이드 워셜 알고리즘을 수행
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	//수행된 결과를 출력
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			//도달할 수 없는 경우, 무한(INFINITY)라고 출력
			if (graph[a][b] == INF) {
				cout << "INFINITY" << ' ';
			}
			else {
				cout << graph[a][b] << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}