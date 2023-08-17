#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> homework;

bool com(pair<int,int> &a, pair<int,int> b) {
	if(a.second==b.second) return a.first < b.first;
	return a.second > b.second;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		homework.push_back({ d,w });
	}
	sort(homework.begin(), homework.end(), com);
}

int solution() {
	int answer = 0;

	for (int i = 0; i < homework.size(); i++) {
		if (homework[i].first <= 0) continue; // ��ȿ�Ⱓ ������ �о�
		answer += homework[i].second;
		for (int j = i + 1; j < homework.size(); j++) {
			// ��� ������ �������� ������ �� �༮�� ���� -1
			// �ֳ�? �׳༮���� 5�� �������� �� 5���� �Ϸ�� ��� ������ ���� �ؾߵǼ�
			if (homework[i].first <= homework[j].first) {
				homework[j].first -= 1;
			}
		}
	}

	return answer;
}

int main() {

	input();
	cout << solution();

	return 0;
}