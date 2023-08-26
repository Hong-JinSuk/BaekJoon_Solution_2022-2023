#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#define endl "\n"
#define INF 987654321

using namespace std;

bool isvisit[101][101][5];
int MAP[101][101];
int cnt = 0;
int n, m, start_x, start_y, end_x, end_y, start_d, end_d;

queue<tuple<int, int, int>> q;

void input() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> MAP[i][j];
		}
	}
	cin >> start_y >> start_x >> start_d;
	cin >> end_y >> end_x >> end_d;
}

pair<int,int> can_turn(int cur_d) { // 옆으로 회전 할 수 있는 곳
	if (cur_d == 1) return { 3,4 };
	else if (cur_d == 2) return { 3,4 };
	else if (cur_d == 3) return { 1,2 };
	else if (cur_d == 4) return { 1,2 };
}

void go(int x, int y, int d) {
	for (int i = 1; i <= 3; i++) {
		if (d == 1) {
			if (MAP[y][x + i] == 1 || x + i > n) return;
			if (MAP[y][x + i] == 0 && x + i <= n && !isvisit[y][x+i][1]) {
				q.push({ x + i, y, 1 });
				isvisit[y][x + i][1] = true;
			}
		}
		else if (d == 2) {
			if (MAP[y][x - i] == 1 || x - i < 1) return;
			if (MAP[y][x - i] == 0 && x - i >= 1 && !isvisit[y][x - i][2]) {
				q.push({ x - i,y,2 });
				isvisit[y][x - i][2]= true;
			}
		}
		else if (d == 3) {
			if (MAP[y + i][x] == 1 || y + i > m) return;
			if (MAP[y + i][x] == 0 && y + i <= m && !isvisit[y + i][x][3]) {
				q.push({ x,y + i,3 });
				isvisit[y + i][x][3] = true;
			}
		}
		else if (d == 4) {
			if (MAP[y - i][x] == 1 || y - i < 1) return;
			if (MAP[y - i][x] == 0 && y - i >= 1 && !isvisit[y - i][x][4]) {
				q.push({ x, y - i, 4 });
				isvisit[y - i][x][4] = true;
			}
		}
	}
	return;
}

void Push(int x, int y, int d_1, int d_2) {
	if (!isvisit[y][x][d_1]) {
		q.push({ x, y, d_1 });
		isvisit[y][x][d_1] = true;
	}
	if (!isvisit[y][x][d_2]) {
		q.push({ x, y, d_2 });
		isvisit[y][x][d_2] = true;
	}
}

void BFS() {

	q.push({start_x, start_y, start_d}); // x,y,방향
	isvisit[start_y][start_x][start_d] = true; // 시작지점 초기화

	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur_x = get<0>(q.front());
			int cur_y = get<1>(q.front());
			int cur_d = get<2>(q.front());
			q.pop();
			if (cur_x == end_x && cur_y == end_y && cur_d == end_d) {
				cout << cnt << endl;
				return;
			}
			go(cur_x, cur_y, cur_d); // 현재 방향으로 이동
			auto next_d = can_turn(cur_d);
			Push(cur_x, cur_y, next_d.first, next_d.second); // 회전
		}
		cnt++;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	input();
	BFS();

}
