#include <bits/stdc++.h>
#define INF (int)1e9
#define MAX_NODE (int)1e5
using namespace std;

int n, m, start;
vector<pair<int, int>> graph[MAX_NODE + 1];
int d[MAX_NODE + 1];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	//���� ���� ���� ���� �ִ� ��δ� 0���� �����Ͽ�, ť�� ����
	pq.push({ 0,start });
	d[start] = 0;
	while (pq.empty() == false) {
		int dist = -pq.top().first;	//C++������ �ִ���������� �켱���� ť�� ¥���� �־ -�� ����
		int nowIndex = pq.top().second;
		pq.pop();
		//���� ��尡 �̹� ó���� ���� �ִٸ� ����
		if (d[nowIndex] < dist) continue;	//�湮�� �Ѱ��̶�� ����� �ּҰŸ��� ť�� �ִ� �Ÿ����� ũ�ų� �����Ƿ�
		//���� ��尡 ����� �ٸ� ������ ������ Ȯ��
		for (int i = 0; i < (int)graph[nowIndex].size(); i++) {
			int cost = d[nowIndex] + graph[nowIndex][i].second;	//�Ÿ������ second�� ������
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

	//�ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	fill(d, d + MAX_NODE + 1, INF);

	//���ͽ�Ʈ�� �˰����� ����
	dijkstra(start);

	//��� ���� ���� ���� �ִ� �Ÿ��� ���
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