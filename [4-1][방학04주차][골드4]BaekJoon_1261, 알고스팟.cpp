#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl "\n"

using namespace std;

int n, m, answer;
int n_x[] = { 1,-1,0,0 };
int n_y[] = { 0,0,1,-1 };
int Miro[100][100];
int Dist[100][100];

void BFS(int x, int y) {

	queue<pair<int,int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = cur_x + n_x[j];
				int ny = cur_y + n_y[j];
				if (nx > -1 && ny > -1 && nx < n && ny < m) { // ¹üÀ§ ¾È
					if (Miro[ny][nx] == 0) {
						if (Dist[ny][nx] > Dist[cur_y][cur_x]) {
							Dist[ny][nx] = Dist[cur_y][cur_x];
							q.push({ nx,ny });
						}
					}
					else {
						if (Dist[ny][nx] > Dist[cur_y][cur_x] + 1) {
							Dist[ny][nx] = Dist[cur_y][cur_x] + 1;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n >> m;
	string input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		for (int j = 0; j < n; j++) {
			int num = input[j] - '0';
			Miro[i][j] = num;
			Dist[i][j] = 987654321;
		}
	}
	Dist[0][0] = 0;
	BFS(0, 0);
	//cout << Dist[m - 1][n - 1];
	for (int yy = 0; yy < m; yy++) {
		for (int xx = 0; xx < n; xx++) {
			cout << Dist[yy][xx] << " ";
		}
		cout << endl;
	}

	return 0;
}