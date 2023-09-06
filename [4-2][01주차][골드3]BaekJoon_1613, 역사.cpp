#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int n, k, s;
int MAP[401][401];

void Floyd() {
	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			if (start == mid) continue;
			for (int end = 1; end <= n; end++) {
				if (start == end || mid == end) continue;
				// 길이 없으면 1->3->4 에서 2->3->4 같은 거 제외
				if (MAP[start][end] == 0 && MAP[end][start] == 0) {
					// 길이 있으면 연결
					if (MAP[start][mid] == -1 && MAP[mid][end] == -1) MAP[start][end] = -1;
					if (MAP[end][mid] == 1 && MAP[mid][start] == 1) MAP[end][start] = 1;
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); // 이거안하면 시간초과;;

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int start, end;
		cin >> start >> end;
		MAP[start][end] = -1; // start -> end 이면 -1 출력
		MAP[end][start] = 1; // end -> start 이면 1 출력
	}

	Floyd();

	cin >> s;
	while (s--) {
		int start, end;
		cin >> start >> end;
		cout << MAP[start][end] << endl;
	}


	return 0;
}