#include <bits/stdc++.h>

using namespace std;

int v, e;
int parent[100001];
vector<pair<int, pair<int, int>>> edges;
int result = 0;

//특정 원소가 속한 집합을 찾기
int findParent(int x) {
	//루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

//두 원소가 속한 집합을 합치기
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> v >> e;

	//부모 테이블상에서, 부모를 자기 자신으로 초기화
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	//간선에 대한 정보를 입력 받기
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		edges.push_back({ cost,{a,b} });
	}

	//간선을 비용순으로 정렬
	sort(edges.begin(), edges.end());

	//간선을 하나씩 확인하며
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		//사이클이 발생하지 않는 경우에만 집합에 포함
		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			result += cost;
		}
	}
	cout << result << endl;

	return 0;
}