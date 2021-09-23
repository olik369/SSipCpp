#include <bits/stdc++.h>

using namespace std;

int v, e;
//모든 노드에 대한 진입차수는 0으로 초기화
int indegree[100001];
//각 노드에 연결된 간선 정보를 담기 위한 연결 리스트 초기화
vector<int>	graph[100001];

//위상 정렬 함수
void topologySort() {
	vector<int> result;	//알고리즘 수행 결과를 담을 리스트
	queue<int> q;

	//처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	//큐가 빌 때까지 반복
	while (q.empty() == false) {
		//큐에서 원소 꺼내기
		int now = q.front();
		q.pop();
		result.push_back(now);
		//해당 원소와 연결된 노드들의 진입차수에서 1 빼기
		for (int i = 0; i < graph[now].size(); i++) {
			int otherIndex = graph[now][i];
			indegree[otherIndex] -= 1;
			//새롭게 진입차수가 0이 되는 노드를 큐에 삽입
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
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b] += 1;
	}

	topologySort();

	return 0;
}