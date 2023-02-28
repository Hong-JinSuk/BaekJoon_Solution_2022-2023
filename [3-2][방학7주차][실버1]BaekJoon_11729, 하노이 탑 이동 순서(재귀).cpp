#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

int n;
int cnt = 0;

vector<pair<int, int>> answer;

// start 에서 mid를 거쳐서 end에 가져다 놔야한다.
void hanoi(int n, int start, int mid, int end) {
	cnt++;
	// 하나밖에 안남았으면 그냥 옮긴다.
	if (n == 1) {
		answer.push_back({ start,end });
		return;
	}

	// n-1개를 mid에 옮기고
	hanoi(n - 1, start, end, mid);
	// 가장 무거운 1개를 end에 옮겨준다.
	answer.push_back({ start,end });
	// 그리고 n-1개를 end에 옮기면 모두 옮겨진다.
	hanoi(n - 1, mid, start, end);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	hanoi(n, 1, 2, 3);
	cout << cnt << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first << " " << answer[i].second << "\n";
	}

	return 0;
}