#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<int> Next_do[10001]; // 이 작업이 끝나면 선행관계가 끝나는 것들
int isCan[10001]; // 선생해야될 작업 갯수
int Time[10001];
void input() {
	cin >> n;
	int cnt;
	for (int i = 1; i <= n; i++) {
		cin >> Time[i]; // 이 작업을 하는데 걸리는 시간
		cin >> cnt; // 선행해야될 작업 갯수
		isCan[i] = cnt;
		while (cnt--) {
			int do_first;
			cin >> do_first;
			Next_do[do_first].push_back(i); // do_first가 끝나면 현재 입력중인 작업 실행 제한 해소
		}
	}
}

void sol() {
	int answer = 0;
	priority_queue<pair<int,int>> q_1; // 작업시간, 작업 번호
	priority_queue<pair<int,int>> q_2;

	for (int i = 1; i <= n; i++) {
		if (isCan[i] == 0)
			q_1.push({-Time[i], i}); // 당장 시작할 수 있는 작업을 담았음.
	}
	while (!q_1.empty() || !q_2.empty()) { // 두 배열이 모두 빌때까지
		int Min = 0;
		if (q_1.empty()) {
			Min = -q_2.top().first;
			while (!q_2.empty()) {
				int cost = -q_2.top().first-Min, index = q_2.top().second; q_2.pop();
				if (cost > 0) q_1.push({ -cost,index });
				else {
					for (int i = 0; i < Next_do[index].size(); i++) { // 현재 작업이 끝남
						int End_ = Next_do[index][i]; // 이 작업이 끝나면 선행작업이 해결되는 작업
						isCan[End_]--;
						if (isCan[End_] == 0) { // 선행작업이 모두 완료되면
							q_1.push({ -Time[End_], End_ });
						}
					}
				}
			}
		}
		else if (q_2.empty()) {
			Min = -q_1.top().first;
			while (!q_1.empty()) {
				int cost = -q_1.top().first - Min, index = q_1.top().second; q_1.pop();
				if (cost > 0) q_2.push({ -cost,index });
				else {
					for (int i = 0; i < Next_do[index].size(); i++) { // 현재 작업이 끝남
						int End_ = Next_do[index][i]; // 이 작업이 끝나면 선행작업이 해결되는 작업
						isCan[End_]--;
						if (isCan[End_] == 0) { // 선행작업이 모두 완료되면
							q_2.push({ -Time[End_], End_ });
						}
					}
				}
			}
		}
		cout << Min << endl;
		answer += Min;
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	input();
	sol();

	return 0;
}