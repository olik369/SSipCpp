#include <bits/stdc++.h>

using namespace std;

int v, e;
//��� ��忡 ���� ���������� 0���� �ʱ�ȭ
int indegree[100001];
//�� ��忡 ����� ���� ������ ��� ���� ���� ����Ʈ �ʱ�ȭ
vector<int>	graph[100001];

//���� ���� �Լ�
void topologySort() {
	vector<int> result;	//�˰��� ���� ����� ���� ����Ʈ
	queue<int> q;

	//ó�� ������ ���� ���������� 0�� ��带 ť�� ����
	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	//ť�� �� ������ �ݺ�
	while (q.empty() == false) {
		//ť���� ���� ������
		int now = q.front();
		q.pop();
		result.push_back(now);
		//�ش� ���ҿ� ����� ������ ������������ 1 ����
		for (int i = 0; i < graph[now].size(); i++) {
			int otherIndex = graph[now][i];
			indegree[otherIndex] -= 1;
			//���Ӱ� ���������� 0�� �Ǵ� ��带 ť�� ����
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