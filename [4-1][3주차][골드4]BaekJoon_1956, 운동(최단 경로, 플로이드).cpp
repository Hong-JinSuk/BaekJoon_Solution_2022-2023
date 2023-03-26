#include<iostream>
#include<vector>
#define endl "\n"
#define INF 987654321
using namespace std;

int v, e, a, b, c, answer;
vector<vector<int>> Route(401, vector<int>(401, INF));

void Search() {

	for (int mid = 1; mid <= v; mid++) {
		for (int start = 1; start <= v; start++) {
			for (int end = 1; end <= v; end++) {
				if (Route[start][mid] != INF && Route[mid][end] != INF) {
					if (Route[start][end] > (Route[start][mid] + Route[mid][end]))
						Route[start][end] = Route[start][mid] + Route[mid][end];
				}
			}
		}
	}

	answer = INF;

	for (int start = 1; start <= v; start++) {
		for (int end = 1; end <= v; end++) {
			if (start == end) answer = min(answer, Route[start][end]);
			else answer = min(answer, (Route[start][end] + Route[end][start]));
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		Route[a][b] = c;
	}

	Search();

	if (answer == INF) cout << -1;
	else cout << answer;

	return 0;
}