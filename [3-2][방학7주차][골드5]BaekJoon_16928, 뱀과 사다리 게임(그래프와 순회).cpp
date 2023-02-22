#include<iostream>
#include<queue>
#include<deque>
#include<vector>

using namespace std;

int n, m, x, y;
bool visited[101];
int answer;
vector<pair<int, int>> Move;

void bfs() {
	
	answer = 0;
	deque<int> q;
	q.push_back(1);

	while (!q.empty()) {

		int re = q.size();

		while (re--) {

			int cur = q.front();
			q.pop_front();

			if (cur == 100) {
				cout << answer;
				return;
			}

			for (int i = 1; i < 7; i++) {
				int next = cur + i;
				if (!visited[next] && next <= 100) { // next 조건안하면 answer가 259가 나옴 이상한 오류 발생
					for (int j = 0; j < Move.size(); j++) {
						if (Move[j].first == next) {
							q.push_back(Move[j].second);
							visited[Move[j].first] = true;
							break;
						}
						else if(j == Move.size() - 1){
							q.push_back(next);
							visited[next] = true;
						}
					}
				}
			}
		}
		answer++;
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n + m; i++) {
		cin >> x >> y;
		Move.push_back({ x,y });
	}

	bfs();

	return 0;
}