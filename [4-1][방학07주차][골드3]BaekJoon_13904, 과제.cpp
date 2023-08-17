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
		if (homework[i].first <= 0) continue; // 유효기간 지난건 패쑤
		answer += homework[i].second;
		for (int j = i + 1; j < homework.size(); j++) {
			// 방금 더해준 숙제보다 기한이 긴 녀석들 기한 -1
			// 왜냐? 그녀석들이 5일 남았으면 그 5일중 하루는 방금 더해준 숙제 해야되서
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
