#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321
using namespace std;

struct Subway
{
	int change = INF;
	int cost = INF;
};

int n, End_spot;
bool isB[1000];
Subway S[1000];
vector<pair<int, int>> MAP[1000]; // 다음지점, 비용

void input() {

	cin >> n >> End_spot;
	for (int i = 0; i < n; i++) {
		cin >> isB[i];
	}

	for (int Start = 0; Start < n; Start++) {
		for (int End = 0; End < n; End++) {
			int Cost; cin >> Cost;
			if (Cost == 0) continue;
			MAP[Start].push_back({ End,Cost });
		}
	}

	return;
}

void sol() {

	queue<pair<int,pair<int,int>>> q; // 위치, 환승, 비용
	q.push({ 0,{0,0} }); // 시작점
	S[0].change = 0;
	S[0].cost = 0;

	while (!q.empty()) {
		int Start = q.front().first, Change = q.front().second.first, Cost = q.front().second.second;
		q.pop();

		if (Start == End_spot) continue;
		for (int i = 0; i < MAP[Start].size(); i++) {
			int next = MAP[Start][i].first, move_cost = MAP[Start][i].second;
			if (isB[Start] == isB[next]) { // 환승이 아니라면
				if (Change < S[next].change) {
					q.push({ next,{Change, Cost + move_cost} });
					S[next].change = Change;
					S[next].cost = Cost + move_cost;
				}
				else if (Change == S[next].change && Cost+move_cost < S[next].cost) {
					q.push({ next,{Change, Cost + move_cost} });
					S[next].change = Change;
					S[next].cost = Cost + move_cost;
				}
			}
			else { // 환승이라면
				if (Change + 1 < S[next].change) {
					q.push({ next,{Change + 1, Cost + move_cost} });
					S[next].change = Change + 1;
					S[next].cost = Cost + move_cost;
				}
				else if (Change + 1 == S[next].change && Cost + move_cost < S[next].cost) {
					q.push({ next,{Change + 1, Cost + move_cost} });
					S[next].change = Change + 1;
					S[next].cost = Cost + move_cost;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	input();
	sol();

	cout << S[End_spot].change << " " << S[End_spot].cost;

	return 0;
}