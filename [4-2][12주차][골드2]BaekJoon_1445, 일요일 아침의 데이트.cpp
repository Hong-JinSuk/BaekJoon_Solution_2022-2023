#include<iostream>
#include<algorithm>
#include<queue>
#define INF 987654321
using namespace std;

int n, m, sx, sy, ex, ey;
char MAP[52][52];
int next_x[] = { -1,1,0,0 };
int next_y[] = { 0,0,1,-1 };

struct X
{
	int near = INF;
	int step = INF;
};

X isvisited[51][51];

void input() {
	cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			cin >> MAP[y][x];
			if (MAP[y][x] == 'S') {
				sx = x;
				sy = y;
			}
			if (MAP[y][x] == 'F') {
				ex = x;
				ey = y;
			}
		}
	}
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			for (int i = 0; i < 4; i++) {
				int nx = x + next_x[i];
				int ny = y + next_y[i];
				if (MAP[ny][nx] == 'g' && MAP[y][x] == '.') MAP[y][x] = '*';
			}
		}
	}
}

void BFS() {
	
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	isvisited[sy][sx].near = 0;
	isvisited[sy][sx].step = 0;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		int x = cur.first, y = cur.second;
		
		for (int i = 0; i < 4; i++) {
			int Near = isvisited[y][x].near, Step = isvisited[y][x].step;
			int nx = x + next_x[i], ny = y + next_y[i];
			if (nx > 0 && nx <= m && ny > 0 && ny <= n) {
				if (MAP[ny][nx] == 'g') {
					Step++;
					if (isvisited[ny][nx].step > Step) {
						q.push({ nx,ny });
						isvisited[ny][nx].step = Step;
						isvisited[ny][nx].near = Near;
					}
					else if (isvisited[ny][nx].step == Step && isvisited[ny][nx].near > Near) {
						q.push({ nx,ny });
						isvisited[ny][nx].step = Step;
						isvisited[ny][nx].near = Near;
					}
				}
				else if (MAP[ny][nx] == '*') {
					Near++;
					if (isvisited[ny][nx].step > Step) {
						q.push({ nx,ny });
						isvisited[ny][nx].step = Step;
						isvisited[ny][nx].near = Near;
					}
					else if (isvisited[ny][nx].step == Step && isvisited[ny][nx].near > Near) {
						q.push({ nx,ny });
						isvisited[ny][nx].step = Step;
						isvisited[ny][nx].near = Near;
					}
				}
				else if (MAP[ny][nx] == '.') {
					if (isvisited[ny][nx].step > Step) {
						q.push({ nx,ny });
						isvisited[ny][nx].step = Step;
						isvisited[ny][nx].near = Near;
					}
					else if (isvisited[ny][nx].step == Step && isvisited[ny][nx].near > Near) {
						q.push({ nx,ny });
						isvisited[ny][nx].step = Step;
						isvisited[ny][nx].near = Near;
					}
				}
				else if (MAP[ny][nx] == 'F') {
					if (isvisited[ny][nx].step > Step) {
						isvisited[ny][nx].step = Step;
						isvisited[ny][nx].near = Near;
					}
					else if (isvisited[ny][nx].step == Step && isvisited[ny][nx].near > Near) {
						isvisited[ny][nx].step = Step;
						isvisited[ny][nx].near = Near;
					}
				}
			}
		}
	}

}
int main() {

	input();
	BFS();
	
	cout << isvisited[ey][ex].step << " " << isvisited[ey][ex].near;

	return 0;
}