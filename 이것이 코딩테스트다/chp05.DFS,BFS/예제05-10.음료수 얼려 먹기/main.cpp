#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[1000][1000];

//DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
//bool DFS(int x, int y) {
//	//주어진 범위를 벗어나는 경우에는 즉시 종료
//	if (x <= -1 || x >= n || y <= -1 || y >= m) {
//		return false;
//	}
//
//	//현재 노드를 아직 방문하지 않았다면
//	if (graph[x][y] == 0) {
//		//해당 노드 방문 처리
//		graph[x][y] = 1;
//		//상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
//		DFS(x - 1, y);
//		DFS(x + 1, y);
//		DFS(x, y - 1);
//		DFS(x, y + 1);
//		return true;
//	}
//	else {
//		return false;
//	}
//}

bool DFS(int x, int y) {
	//아예 영역 밖으로 나가버리는 경우
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}

	if (graph[x][y] == 0) {
		//방문처리(얼음 채우기)
		graph[x][y] = 1;
		
		//상하좌우로 DFS를 시도하면 됨
		DFS(x - 1, y);
		DFS(x + 1, y);
		DFS(x, y - 1);
		DFS(x, y + 1);

		//자기 주변을 모두 DFS를 호출해서 방문처리 후 true반환
		return true;
	}
	else {
		return false;
	}
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		cin.ignore();
		for (int j = 0; j < m; j++) {
			graph[i][j] = input[j] - '0';
		}
	}

	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (DFS(i, j) == true) {
				result++;
			}
		}
	}

	cout << result << endl;
}