#include <bits/stdc++.h>
#define MAX_NODE 500
using namespace std;

int v;
int indegree[MAX_NODE + 1];
vector<int> graph[MAX_NODE + 1];	//각 노드에 연결된 간선 정보를 담기 위한 연결 리스트 초기화
int times[MAX_NODE + 1];

void topologySort() {
	vector<int> result(501);
	for (int i = 1; i <= v; i++) {
		result[i] = times[i];
	}

	queue<int> q;

	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (q.empty() == false) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int otherIndex = graph[now][i];
			result[otherIndex] = max(result[otherIndex], result[now] + times[otherIndex]);
			indegree[otherIndex] -= 1;
			if (indegree[otherIndex] == 0) {
				q.push(otherIndex);
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		cout << result[i] << endl;
	}
}

int main() {
	cin >> v;
	for (int i = 1; i <= v; i++) {
		int x;
		cin >> x;
		times[i] = x;
		while (true) {
			cin >> x;
			if (x == -1) break;
			graph[x].push_back(i); //여기 부분 이해안됨
			indegree[i] += 1;
		}
	}

	topologySort();

	return 0;
}