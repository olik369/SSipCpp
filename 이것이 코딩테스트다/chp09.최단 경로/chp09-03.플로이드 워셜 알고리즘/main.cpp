#include <bits/stdc++.h>
#define INF (int)1e9
#define MAX_NODE (int)500
using namespace std;

int n, m;
int graph[MAX_NODE + 1][MAX_NODE + 1];	//�ִ� ��� ���� 500��

int main() {
	cin >> n >> m;

	//�ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	for (int i = 0; i < MAX_NODE + 1; i++) {
		fill(graph[i], graph[i] + MAX_NODE + 1, INF);
	}

	//�ڱ� �ڽ����� ���� ��� ����� 0���� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	//�� ������ ���� ������ �Է¹ޱ�
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from][to] = cost;
	}

	//��ȭ�Ŀ� ���� �÷��̵� ���� �˰����� ����
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	//����� ����� ���
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			//������ �� ���� ���, ����(INFINITY)��� ���
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