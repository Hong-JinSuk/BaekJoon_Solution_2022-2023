#include<iostream>
#include<queue>
using namespace std;

int h, w;
int MAP[1000][1000];
int next_x[] = { 1,1,1,0,0,-1,-1,-1 };
int next_y[] = { 1,0,-1,1,-1,1,0,-1 };
queue<pair<int, int>> q;

void input() {
	cin >> h >> w;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			char num; cin >> num;
			if (num == '.') {
				MAP[y][x] = -1;
				q.push({ x,y }); // .에 의해서만 업데이트 발생
			}
			else MAP[y][x] = num - '0';
		}
	}
}

void sol() {

	int answer = -1;
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int x = q.front().first, y = q.front().second; q.pop(); // 정보 받아오고 pop
			for (int i = 0; i < 8; i++) {
				int nx = x + next_x[i], ny = y + next_y[i];
				if (nx > -1 && nx < w && ny > -1 && ny < h) {
					MAP[ny][nx]--; // 인접한 곳은 -1씩
					if (MAP[ny][nx] == 0) q.push({ nx,ny }); // . 이 되면 넣어줌.
				}
			}
		}
		answer++;
	}
	cout << answer;
}

int main() {

	input();
	sol();

	return 0;
}