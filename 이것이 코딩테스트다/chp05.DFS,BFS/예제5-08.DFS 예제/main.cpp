//#include <bits/stdc++.h>
//using namespace std;
//
//bool visited[9];
//vector<int> graph[9];
//
////DFS 함수 정의
//void DFS(int x) {
//	//현재 노드를 방문 처리
//	visited[x] = true;
//	cout << x << ' ';
//	for (int i = 0; i < (int)graph[x].size(); i++) {
//		int y = graph[x][i];
//
//		if (visited[y] == false) {
//			DFS(y);
//		}
//	}
//}
//
//int main() {
//	//정점 1
//	graph[1].push_back(2);
//	graph[1].push_back(3);
//	graph[1].push_back(8);
//
//	//정점 2
//	graph[2].push_back(1);
//	graph[2].push_back(7);
//	
//	//정점 3
//	graph[3].push_back(1);
//	graph[3].push_back(4);
//	graph[3].push_back(5);
//
//	//정점 4
//	graph[4].push_back(3);
//	graph[4].push_back(5);
//
//	//정점 5
//	graph[5].push_back(3);
//	graph[5].push_back(4);
//
//	//정점 6
//	graph[6].push_back(7);
//
//	//정점 7
//	graph[7].push_back(2);
//	graph[7].push_back(6);
//	graph[7].push_back(8);
//
//	//정점 8
//	graph[8].push_back(1);
//	graph[8].push_back(7);
//
//	DFS(1);
//}

#include <bits/stdc++.h>
using namespace std;

bool visited[9];
vector<int> graph[9];	//graph의 index가 정점(vertex)번호

void DFS(int vertexNum) {
	visited[vertexNum] = true;
	cout << vertexNum << ' ';

	for (int i = 0; i < (int)graph[vertexNum].size(); i++) {
		auto nextVertexNum = graph[vertexNum][i];
		if (visited[nextVertexNum] == false) {
			DFS(nextVertexNum);
		}
	}
}

int main() {
	//정점 1
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	//정점 2
	graph[2].push_back(1);
	graph[2].push_back(7);

	//정점 3
	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	//정점 4
	graph[4].push_back(3);
	graph[4].push_back(5);

	//정점 5
	graph[5].push_back(3);
	graph[5].push_back(4);

	//정점 6
	graph[6].push_back(7);

	//정점 7
	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);

	//정점 8
	graph[8].push_back(1);
	graph[8].push_back(7);

	DFS(1);
}