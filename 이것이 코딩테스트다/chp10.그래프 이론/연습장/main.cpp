#include <bits/stdc++.h>
#define MAX_NODE (int)1e5
using namespace std;

int v, e;
int indegree[MAX_NODE + 1];
vector<int> graph[MAX_NODE + 1];

void topologySort() {
	queue<int> q;
	vector<int> result;

	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (q.empty() == false) {
		int nowIndex = q.front();
		result.push_back(nowIndex);
		q.pop();
		for (int i = 0; i < graph[nowIndex].size(); i++) {
			int otherIndex = graph[nowIndex][i];
			indegree[otherIndex] -= 1;
			if (indegree[otherIndex] == 0) {
				q.push(otherIndex);
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
}

int main() {
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		indegree[to] += 1;
	}

	topologySort();

	return 0;
}