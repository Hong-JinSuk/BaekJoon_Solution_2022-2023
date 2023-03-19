#include<iostream>
#include<vector>
#include<queue>
#define endl "\n";
using namespace std;

int n, m, Start, End, Cost, Next;
vector<vector<int>> Route(101, vector<int>(101, 0));
int Move[101][101];

void Search() {

	queue<int> q;
	int visit_cost[101];

	// 시작점이 n개
	for (int i = 1; i <= n; i++) {

		// 비용 초기화, 이 부분 100001 으로 해놨는데, 생각해보니 100000*100 보다 컸어야 됬다...
		for (int k = 0; k < 101; k++) {
			visit_cost[k] = 100000001;
		}

		// 시작하는 지점 push
		q.push(i);

		// 이 코드를 while문 안에서 visit_cost[cur]=0 으로 해놓고,, 왜 게속 0 되지 이럼..
		visit_cost[i] = 0; // 현재 지점은 항상 0

		// q가 빌때까지 실행
		while (!q.empty()) {

			int cur = q.front(); // 현재 지점
			q.pop(); // 정보 받아왔으니 pop

			for (int j = 1; j <= n; j++) { // 현재 지점에서 다른지점으로 경로 탐색
				Next = j; // j는 현재 지점에서 이동할 지점
				if (Route[cur][Next]) { // 현재 지점에서 이동할 경로가 있다면
					int move_cost = visit_cost[cur] + Route[cur][Next]; // 이전 지점까지의 비용+이동할 비용
					if (move_cost < visit_cost[j]) { // move_cost가 지금까지의 visit_cost보다 적다면
						q.push(Next); // 다음 지점을 시작하는 지점으로 한다. 
						visit_cost[Next] = move_cost; // visit_cost 값도 바꿔준다.
					}
				}
			}
		} // 모든 q 실행완료

		for (int j = 1; j <= n; j++) {
			Move[i][j] = visit_cost[j];
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> Start >> End >> Cost;
		// 같은 경로로 가는 버스가 2대 이상일 때, 더 빠른 버스만 취급
		if (Route[Start][End]) Route[Start][End] = min(Route[Start][End], Cost);
		else Route[Start][End] = Cost;
	}

	Search();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (Move[i][j] == 100000001) cout << 0 << " "; // 길이 없는경우 0
			else cout << Move[i][j] << " ";
		}
		cout << endl;
	}
	

	return 0;
}