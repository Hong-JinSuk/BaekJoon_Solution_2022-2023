#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;

vector<int> Building[501]; // 위상정렬에서 화살표가 나오는놈이 받는놈을 원소로 갖음.
vector<int> Building_2[501]; // 그냥 데이터 주는대로 받는 함수
int Time[501]; // 인덱스를 만드는데 걸리는 시간
int indegree[501]; // 위상정렬에서 쓰이는 화살표를 받는 갯수
int Buildtime[501]; // 지금까지 누적으로 걸리는 시간

void input() {
	cin >> n;
	int a, b;
	for (int i = 1; i <= n; i++) {
		cin >> Time[i]; // i번빼 건물 짓는데 걸리는 시간
		while (cin >> a) {
			if (a == -1) break;
			Building_2[i].push_back(a);
			Building[a].push_back(i); // i건물을 지어야 a건물을 지을 수 있음.
			indegree[i]++;
		}
	}

}

void solution() {
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) q.push(i);

	while (!q.empty()) {
		int q_size = q.size();

		for (int i = 0; i < q_size; i++) {
			int cur = q.front();
			q.pop();

			Buildtime[cur] += Time[cur];

			for (int j = 0; j < Building[cur].size(); j++) {
				int next = Building[cur][j];
				indegree[next]--; // 앞선 건물을 지음
				if (indegree[next] == 0) {
					q.push(next);
					int MAX = 0;
					for (auto a : Building_2[next]) {
						MAX = max(MAX, Buildtime[a]);	
					} // 아래 예시에서 4번째는 3,5중 더 큰것을 따라가게함.
					//cout << MAX << endl;
					Buildtime[next] += MAX;
					// 기존 코드는 시간 신경을 못씀.
					//Buildtime[next] += Buildtime[cur];
				}
			}
		}
	}
}

// 5
// 10 - 1
// 20 1 - 1
// 30 2 - 1
// 40 3 5 - 1
// 100 - 1
// 이처럼 순서는 맞는데, 시간과 관련된 문제가 있으
// 이정도면 dp가 아니고 그리디 문제인디??

int main() {

	input();
	solution();
	for (int i = 1; i <= n; i++) {
		cout << Buildtime[i] << endl;
	}

	return 0;
}