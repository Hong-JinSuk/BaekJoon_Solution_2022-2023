#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int Map[501][501];
int n_x[] = { -1,1,0,0 };
int n_y[] = { 0,0,-1,1 };
int answer = 0;
int dp[501][501];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			dp[i][j] = -1;
		}
	}
}

int DFS(int cur_x, int cur_y) {

	// �̹� �湮�� ���̸� �׸�ŭ ������
	if (dp[cur_y][cur_x] != -1) return dp[cur_y][cur_x];
	// �������� �����ϸ� ������ �����ְ� �����ش�.
	if (cur_x == m - 1 && cur_y == n - 1) {
		// answer++;
		return 1;
	}
	dp[cur_y][cur_x] = 0;

	for (int i = 0; i < 4; i++) {
		int next_x = cur_x + n_x[i];
		int next_y = cur_y + n_y[i];

		// �������̰� ���������� �湮�� ������ �ƴ� ��
		if (next_x > -1 && next_y > -1 && next_x < m && next_y < n) {
			// �� ���� ���̶��
			if (Map[next_y][next_x] < Map[cur_y][cur_x]) {
				dp[cur_y][cur_x] += DFS(next_x, next_y);
			}
		}
	}
	return dp[cur_y][cur_x];
}

int main() {

	input();

	cout << DFS(0, 0);

	return 0;
}