#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[1000][1000];

//DFS�� Ư�� ��带 �湮�ϰ� ����� ��� ���鵵 �湮
//bool DFS(int x, int y) {
//	//�־��� ������ ����� ��쿡�� ��� ����
//	if (x <= -1 || x >= n || y <= -1 || y >= m) {
//		return false;
//	}
//
//	//���� ��带 ���� �湮���� �ʾҴٸ�
//	if (graph[x][y] == 0) {
//		//�ش� ��� �湮 ó��
//		graph[x][y] = 1;
//		//��, ��, ��, ���� ��ġ�鵵 ��� ��������� ȣ��
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
	//�ƿ� ���� ������ ���������� ���
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}

	if (graph[x][y] == 0) {
		//�湮ó��(���� ä���)
		graph[x][y] = 1;
		
		//�����¿�� DFS�� �õ��ϸ� ��
		DFS(x - 1, y);
		DFS(x + 1, y);
		DFS(x, y - 1);
		DFS(x, y + 1);

		//�ڱ� �ֺ��� ��� DFS�� ȣ���ؼ� �湮ó�� �� true��ȯ
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