//#include <bits/stdc++.h>
//using namespace std;
//
//bool visited[9];
//vector<int> graph[9];
//
////DFS �Լ� ����
//void DFS(int x) {
//	//���� ��带 �湮 ó��
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
//	//���� 1
//	graph[1].push_back(2);
//	graph[1].push_back(3);
//	graph[1].push_back(8);
//
//	//���� 2
//	graph[2].push_back(1);
//	graph[2].push_back(7);
//	
//	//���� 3
//	graph[3].push_back(1);
//	graph[3].push_back(4);
//	graph[3].push_back(5);
//
//	//���� 4
//	graph[4].push_back(3);
//	graph[4].push_back(5);
//
//	//���� 5
//	graph[5].push_back(3);
//	graph[5].push_back(4);
//
//	//���� 6
//	graph[6].push_back(7);
//
//	//���� 7
//	graph[7].push_back(2);
//	graph[7].push_back(6);
//	graph[7].push_back(8);
//
//	//���� 8
//	graph[8].push_back(1);
//	graph[8].push_back(7);
//
//	DFS(1);
//}

#include <bits/stdc++.h>
using namespace std;

bool visited[9];
vector<int> graph[9];	//graph�� index�� ����(vertex)��ȣ

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
	//���� 1
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	//���� 2
	graph[2].push_back(1);
	graph[2].push_back(7);

	//���� 3
	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	//���� 4
	graph[4].push_back(3);
	graph[4].push_back(5);

	//���� 5
	graph[5].push_back(3);
	graph[5].push_back(4);

	//���� 6
	graph[6].push_back(7);

	//���� 7
	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);

	//���� 8
	graph[8].push_back(1);
	graph[8].push_back(7);

	DFS(1);
}