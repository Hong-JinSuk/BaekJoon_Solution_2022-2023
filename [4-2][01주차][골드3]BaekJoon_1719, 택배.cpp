#include<iostream>
#include<vector>
#define INF 987654321

using namespace std;
int n, m;
int Dist[201][201];
int answer[201][201];

void input() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) Dist[i][j] = 0;
			else Dist[i][j] = INF;
		}
	}

	for (int i = 1; i <= m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		Dist[start][end] = cost;
		Dist[end][start] = cost;
		answer[start][end] = end;
		answer[end][start] = start;
	}
}

void floyd() {

	for (int Mid = 1; Mid <= n; Mid++) {
		for (int Start = 1; Start <= n; Start++) {
			if (Mid == Start) continue;
			for (int End = 1; End <= n; End++) {
				if (Mid == Start || Mid == End || Start == End) continue;
				if (Dist[Start][End] > Dist[Start][Mid] + Dist[Mid][End]) {
					Dist[Start][End] = Dist[Start][Mid] + Dist[Mid][End];
					answer[Start][End] = answer[Start][Mid];
				}
			}
		}
	}
	
	return;
}

int main() {

	input();

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << answer[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}