#include <bits/stdc++.h>	
using namespace std;

int graph[201][201];
int N, M;
//상하좌우
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (q.empty() == false) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//현재 위치에서 4가지 방향으로의 위치확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//미로찾기 공간을 벗어난 경우 무시
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			//벽인 경우 무시
			if (graph[nx][ny] == 0)continue;
			//해당 노드를 처음 방문하는 경우에만 최단거리 기록
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	//가장 오른쪽 아래까지의 최단 거리 반환
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