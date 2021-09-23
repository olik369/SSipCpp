#include <bits/stdc++.h>
#define MAX_NODE (int)1e5

using namespace std;

int v, e;
int parent[MAX_NODE + 1];

//Ư�� ���Ұ� ���� ������ ã��
int findParent(int x) {
	if (x == parent[x]) return x;
	return findParent(parent[x]);
}

//�� ���Ұ� ���� ������ ��ġ��
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
	
	//�� ���Ұ� ���� ���� ����ϱ�
	cout << "�� ���Ұ� ���� ����: ";
	for (int i = 1; i <= v; i++) {
		cout << findParent(i) << ' ';
	}
	cout << endl;

	//�θ� ���̺� ���� ����ϱ�
	cout << "�θ� ���̺� ���� ����ϱ�: ";
	for (int i = 1; i <= v; i++) {
		cout << parent[i] << ' ';
	}
	cout << endl;

	return 0;
}