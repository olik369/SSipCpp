#include <bits/stdc++.h>

using namespace std;

//내가 푼 쓰레기 풀이
/*
int solution(string s) {
	int result = (int)s.length();

	for (int zip_length = 1; zip_length <= s.length() / 2; zip_length++) {
		int count = 1;
		int cur_result = 0;

		for (int current_pos = 0; current_pos < s.length(); current_pos += zip_length) {
			bool is_same = true;
			for (int j = 0; j < zip_length; j++) {
				if (((int)s.length() - current_pos - zip_length) < 0) {
					is_same = false;
					break;
				}

				if (s[current_pos + j] != s[current_pos + j + zip_length]) {
					is_same = false;
					break;
				}
			}
			if (is_same == true) count++;
			else {
				if (count == 1) {
					cur_result += (current_pos + zip_length + 1) > s.length() ? (s.length() - current_pos) : zip_length;
				}
				else {

					while (count != 0) {
						count /= 10;
						cur_result++;
					}
					cur_result += (current_pos + zip_length + 1) > s.length() ? (s.length() - current_pos) : zip_length;
					count = 1;
				}
			}
		}
		result = min(result, cur_result);
	}

	return result;
}
*/

int solution(string s) {
	int answer = s.size();

	for (int step = 1; step < s.size() / 2 + 1; step++) {
		string compressed = "";
		string prev = s.substr(0, step);	//앞에서부터 step만큼의 문자열 추출
		int cnt = 1;
		//단위(step)크기만큼 증가시키며 이전 문자열과 비교
		for (int j = step; j < s.size(); j += step) {
			//이전 상태와 동일하다면 압축횟수(count)증가
			if (prev == s.substr(j, step))	cnt += 1;
			//다른 문자열이 나왔다면
			else {
				compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
				prev = s.substr(j, step);	//다시 상태 초기화
				cnt = 1;
			}
		}
		//남아있는 문자열에 대해서 처리
		compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
		//만들어지는 압축 문자열이 가장 짧은 것이 정답
		answer = min(answer, (int)compressed.size());
	}
	return answer;
}

int main() {
	string ex = "aaabbbccc";
	cout << solution(ex) << endl;
}