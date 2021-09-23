#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//문제 1번
//int solution(int A, int B) {
//	long long AB = (long long)A * (long long)B;
//	int result = 1;
//	while (AB != 1) {
//		if (AB % 2 == 1) result++;
//		AB /= 2;
//	}
//	return result;
//}

//문제 2번

vector<int> B;
int solution(vector<int>& A) {
	int result = 0;

	//처음과 끝의 숫자를 합한것 배열에 넣어주기
	int x = A[0] + A[(int)A.size() - 1];
	B.push_back(x);
	//0~(n-1)까지 앞뒤의 값을 합한것을 넣어줌
	for (int i = 0; i < (int)A.size() - 1; i++) {
		int y = A[i] + A[i + 1];
		B.push_back(y);
	}

	int j = 0;
	//처음부터 짝수가 나올때마다 갯수 늘리고 인덱스를 원래 증가보다 1 더늘리기
	while (j < (int)B.size() - 1); {
		if (B[j] % 2 == 0) {
			result += 1;
			j += 2;
		}
		else j++;
	}
	//마지막 인덱스는 첫번째 것이 짝수인지에 따라 제외
	/*if (B[(int)B.size() - 1] % 2 == 0) {
		if (B[0] % 2 == 1) result += 1;
	}*/

	return result;
}

//문제 3번
//int solution(string& S) {
//	istringstream split(S);
//	vector<string> line;
//	string num;
//	stack<int> result;
//
//	while (getline(split, num, ' ')) {
//		line.push_back(num);
//	}
//
//	for (int i = 0; i < line.size(); i++) {
//		if (line[i] == "DUP" || line[i] == "POP" || line[i] == "+" || line[i] == "-") {
//			//DUP과 POP은 반드시 숫자가 들어가 있어야함
//			if (line[i] == "DUP") {
//				if (result.empty() == true) {
//					return -1;
//				}
//
//				result.push(result.top());
//			}
//			else if (line[i] == "POP") {
//				if (result.empty() == true) return -1;
//				result.pop();
//			}
//			//+,-는 반드시 사이즈가 2이상
//			else if (line[i] == "+") {
//				if (result.size() < 2) return -1;
//				int x1 = result.top();
//				result.pop();
//				int x2 = result.top();
//				result.pop();
//				result.push((x1 + x2));
//			}
//			else {
//				if (result.size() < 2) return -1;
//				int x1 = result.top();
//				result.pop();
//				int x2 = result.top();
//				result.pop();
//				if ((x1 - x2) < 0) return -1;
//				result.push((x1 - x2));
//			}
//		}
//		else {
//			int x = stoi(line[i]);
//			result.push(x);
//		}
//	}
//	return result.top();
//}

int main() {
	vector<int> A = { 1000000000,999999998,999999998,999999996 };
	cout << solution(A);

}