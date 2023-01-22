#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

int n, m;
int miro[101][101] = { 0, };
int Sum[101][101] = { 0, };
int x_[4] = { 1,-1,0,0 }; // 상하좌우
int y_[4] = { 0,0,-1,1 };
bool visited[101][101];

queue<pair<int, int>> q;

void BFS(int x, int y) {

	visited[x][y] = true;

	q.push(make_pair(x, y));

	while (!q.empty()) {

		int c_x = q.front().first;
		int c_y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {

			// 다음 좌표
			int next_x = c_x + x_[i];
			int next_y = c_y + y_[i];
			
			// 다음 좌표가 범위 안이고
			if (1 <= next_x && next_x < n + 1 && 0 < next_y && next_y < m + 1) {
				// 벽이 아니고, 방문하지 않았다면
				if (miro[next_x][next_y] != 0 && !visited[next_x][next_y]) {
					Sum[next_x][next_y] = Sum[c_x][c_y] + 1;
					visited[next_x][next_y] = true;
					q.push(make_pair(next_x, next_y));
				}
			}
		}

	}
}

int main() {

	cin >> n >> m;

	// 미로입력
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			scanf_s("%1d", &miro[i][j]);
		}
	}
	
	// 시작점
	Sum[1][1] = 1;

	BFS(1, 1);

	/*cout << endl;
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < m+1; j++) {
			cout << Sum[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	cout << Sum[n][m];

	return 0;
}