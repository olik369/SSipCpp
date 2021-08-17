#include <bits/stdc++.h>	
using namespace std;

int graph[201][201];
int N, M;
//�����¿�
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (q.empty() == false) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//���� ��ġ���� 4���� ���������� ��ġȮ��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//�̷�ã�� ������ ��� ��� ����
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			//���� ��� ����
			if (graph[nx][ny] == 0)continue;
			//�ش� ��带 ó�� �湮�ϴ� ��쿡�� �ִܰŸ� ���
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	//���� ������ �Ʒ������� �ִ� �Ÿ� ��ȯ
	return graph[N - 1][M - 1];
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string inputMap;
		cin >> inputMap;
		cin.ignore();
		for (int j = 0; j < M; j++) {
			graph[i][j] = inputMap[j] - '0';
		}
	}

	cout << BFS(0, 0) << endl;
	return 0;
}