#include <bits/stdc++.h>
#define MAX_NODE (int)1e5

using namespace std;

int v, e;
int parent[MAX_NODE + 1];

//특정 원소가 속한 집합을 찾기
int findParent(int x) {
	if (x == parent[x]) return x;
	return findParent(parent[x]);
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

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}
	
	//각 원소가 속한 집합 출력하기
	cout << "각 원소가 속한 집합: ";
	for (int i = 1; i <= v; i++) {
		cout << findParent(i) << ' ';
	}
	cout << endl;

	//부모 테이블 내용 출력하기
	cout << "부모 테이블 내용 출력하기: ";
	for (int i = 1; i <= v; i++) {
		cout << parent[i] << ' ';
	}
	cout << endl;

	return 0;
}