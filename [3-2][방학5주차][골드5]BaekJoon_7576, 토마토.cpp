#include<iostream>
#include<queue>

using namespace std;

int n, m;

int tomato[1001][1001];
int day[1001][1001] = { 0, };
queue<pair<int, int>> q;

int x_[4] = { -1, 1, 0, 0 };
int y_[4] = { 0, 0, 1, -1 };

void bfs() {

	while (!q.empty()) {
		int c_y = q.front().first;
		int c_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = c_x + x_[i];
			int next_y = c_y + y_[i];

			//cout << "next_x : " << next_x << ", next_y : " << next_y << endl;

			if (0 <= next_x && next_x < m && 0 <= next_y && next_y < n) {
				if (tomato[next_y][next_x] == 0) {
					tomato[next_y][next_x] = tomato[c_y][c_x] + 1;
					q.push(make_pair(next_y, next_x));
				}
			}
		}
	}
}

int main() {

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	bfs();

	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << tomato[i][j] << " ";
		}
		cout << endl;
	}

	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				cout << -1;
				return 0;
			}
			answer = max(answer, tomato[i][j]);
		}
	}

	cout << answer - 1;

	return 0;
}