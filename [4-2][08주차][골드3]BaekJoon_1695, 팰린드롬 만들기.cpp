#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define endl "\n"
using namespace std;

int n;
int dp[5000][5000]; // 느린 지점은 제외
vector<int> palindrome;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		palindrome.push_back(num);
	}
	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < 5000; j++) {
			dp[i][j] = -1;
		}
	}
}

int sol(int left, int right) {
	
	if (dp[left][right] != -1) return dp[left][right];
	
	if (left >= right) return dp[left][right] + 1;

	if (palindrome[left] == palindrome[right]) {
		dp[left][right] = sol(left + 1, right - 1);
	}
	else { // 왼쪽을 줄이거나 오른쪽을 줄이거나 둘중 적게 실행하는 곳을 받아온다.
		dp[left][right] = min(sol(left + 1, right) + 1, sol(left, right - 1) + 1);
	}

	return dp[left][right];
}
// 1 2 3 4 2 / 1 2 3 3 5 1
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	input();
	cout << sol(0, n-1);

	return 0;
}