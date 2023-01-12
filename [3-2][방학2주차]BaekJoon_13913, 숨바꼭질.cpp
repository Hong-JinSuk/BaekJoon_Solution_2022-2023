#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, k;
bool visited[100001];
int acc[100001] = { 0, };
int check[100001];
vector<int> path;
queue<int> q;

int Search() { //bfs형식

	q.push(n);
	visited[n] = true;
	int a = 1;
	while (!q.empty()) {

		int n = q.front(); // queue에서 맨앞에 있는거 가져옴
		q.pop(); // 가져온거 쳐냄

		int Next[3] = { n - 1,n + 1,n * 2 }; // 이동할 3가지 경우

		for (int i = 0; i < 3; i++) {

			// 다음 경로가 0이상 100000이하 방문 x인 경우
			if (Next[i] >= 0 && Next[i] <= 100000 && !visited[Next[i]]) {
				q.push(Next[i]); // queue에 넣어주우움
				visited[Next[i]] = true; // 방문 표시
				acc[Next[i]] = acc[n] + 1; // 누적적
				check[Next[i]] = n; // 도착지점에 출발지점 저장
			}

			if (Next[i] == k) {
				return acc[Next[i]];
			}
		}
	}
}

int main() {

	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	int answer = Search();
	cout << answer << endl;

	// 도착지점부터 하나씩 뒤로 저장해둔 경로로 찾아 가는거
	path.push_back(k);
	for (int i = 0; i < answer; i++) {
		path.push_back(check[k]);
		k = check[k];
	}
	for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";

	return 0;
}