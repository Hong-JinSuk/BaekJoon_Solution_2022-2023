#include<iostream>
#include<vector>
#include<queue>
#define MAX 987654321
using namespace std;

int n, m;
int Miro[1001][1001];
bool isvisited[1001][1001][2];
int n_x[] = { -1,1,0,0 };
int n_y[] = { 0,0,-1,1 };

// cnt = ���� �μ� Ƚ��
//void DFS(int x, int y, int cnt, int dist) { // DFS�� �ð��ʰ��� �߻���.
//	cout << "x,y : " << x << ", " << y << endl;
//	if (x == m - 1 && y == n - 1) {
//		cout << endl;
//		return;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		int nx = x + n_x[i];
//		int ny = y + n_y[i];
//
//		// ���� �ȿ� ���� ��
//		if (nx > -1 && ny > -1 && nx < m && ny < n) {
//			// ���� �� ���� ���� �ʾ����� �������
//			if (Miro[ny][nx] == 1 && cnt == 0) {
//				Dist[ny][nx] = dist + 1;
//				DFS(nx, ny, cnt + 1, dist + 1);
//			}
//			// ���� ��, �̰� �� ������ �������
//			else if (Miro[ny][nx] == 0 && Dist[ny][nx] > dist + 1) {
//				Dist[ny][nx] = dist + 1;
//				DFS(nx, ny, cnt, dist + 1);
//			}
//		}
//	}
//
//}

int bfs(int x, int y) {

	int cnt = 1;
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x,y }, 0 });

	while (!q.empty()) {

		int q_size = q.size();
		for (int k = 0; k < q_size; k++) {
			bool isCrash = q.front().second;
			int cur_x = q.front().first.first;
			int cur_y = q.front().first.second;
			q.pop();
			if (cur_x == m - 1 && cur_y == n - 1) return cnt;
			for (int i = 0; i < 4; i++) {
				int nx = cur_x + n_x[i];
				int ny = cur_y + n_y[i];
				if (nx > -1 && ny > -1 && nx < m && ny < n) {
					// ���̰�, ���� �μ��� �ʾ��� ���
					if (Miro[ny][nx] == 1 && isCrash == 0) {
						isvisited[ny][nx][isCrash] = true;
						//cout << nx << ", " << ny << endl;
						q.push({ {nx,ny}, 1 });
					}
					// ���̰� ���� �湮���� �ʾ��� ���
					else if (Miro[ny][nx] == 0 && !isvisited[ny][nx][isCrash]) {
						isvisited[ny][nx][isCrash] = true;
						//cout << nx << ", " << ny << endl;
						q.push({ {nx,ny}, isCrash });
					}
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main() {

	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		string input;
		cin >> input;
		for (int x = 0; x < m; x++) {
			Miro[y][x] = input[x] - '0';
		}
	}

	cout << bfs(0, 0);

	return 0;
}