#include <bits/stdc++.h>
#define INF (int)1e9

using namespace std;

//1~n회사, m은 간선 갯수, x는 첫번째 방문 회사, k는 두번째 방문회사
int n, m, x, k;
int graph[101][101];

void PrintResult(int result) {
	
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, INF);
	}

	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int from = 1; from <= n; from++) {
			for (int to = 1; to <= n; to++) {
				graph[from][to] = min(graph[from][to], graph[from][mid] + graph[mid][to]);
			}
		}
	}

	cin >> x >> k;
	auto result_1 = graph[1][k];
	auto result_2 = graph[k][x];

	if (result_1 == INF || result_2 == INF) {
		cout << -1 << endl;
	}
	else {
		cout << result_1 + result_2 << endl;
	}

	return 0;
}