#include <iostream>
#include <algorithm>

using namespace std;

int r, c;
int answer = 0;
char Map[20][20];
bool isvisitied[26];

int n_x[] = { 1,-1,0,0 };
int n_y[] = { 0,0,-1,1 };

void DFS(int x, int y, int cnt) {
	if (answer == 26) return;
	answer = max(answer, cnt);

	for (int i = 0; i < 4; i++) {
		int next_x = x + n_x[i];
		int next_y = y + n_y[i];
		if (next_x > -1 && next_x < c && next_y > -1 && next_y < r) {
			int alpha = Map[next_y][next_x] - 'A';
			if (!isvisitied[alpha]) {
				isvisitied[alpha] = true;
				//cout << Map[next_y][next_x];
				DFS(next_x, next_y, cnt + 1);
				isvisitied[alpha] = false;
			}
		}
	}

	return;
}

int main() {

	cin >> r >> c;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> Map[i][j];
		}
	}

	isvisitied[Map[0][0] - 'A'] = true;
	DFS(0, 0, 1);

	cout << answer;
	return 0;
}