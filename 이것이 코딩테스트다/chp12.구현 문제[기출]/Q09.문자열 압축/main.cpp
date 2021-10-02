#include <bits/stdc++.h>

using namespace std;

//���� Ǭ ������ Ǯ��
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
		string prev = s.substr(0, step);	//�տ������� step��ŭ�� ���ڿ� ����
		int cnt = 1;
		//����(step)ũ�⸸ŭ ������Ű�� ���� ���ڿ��� ��
		for (int j = step; j < s.size(); j += step) {
			//���� ���¿� �����ϴٸ� ����Ƚ��(count)����
			if (prev == s.substr(j, step))	cnt += 1;
			//�ٸ� ���ڿ��� ���Դٸ�
			else {
				compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
				prev = s.substr(j, step);	//�ٽ� ���� �ʱ�ȭ
				cnt = 1;
			}
		}
		//�����ִ� ���ڿ��� ���ؼ� ó��
		compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
		//��������� ���� ���ڿ��� ���� ª�� ���� ����
		answer = min(answer, (int)compressed.size());
	}
	return answer;
}

int main() {
	string ex = "aaabbbccc";
	cout << solution(ex) << endl;
}