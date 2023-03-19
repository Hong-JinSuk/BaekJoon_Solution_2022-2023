#include<iostream>
#define endl "\n"
using namespace std;

int n;
int podo[10001];
int dp[10001];
void get_dp(int cur) {
	int MAX;
	// ���簡 dp4��� dp1 + podo3 + podo4 or dp2 + podo4 or dp3 3�����ۿ� ����.
	MAX = max(dp[cur - 2] + podo[cur], dp[cur - 3] + podo[cur - 1] + podo[cur]);
	MAX = max(MAX, dp[cur - 1]);
	dp[cur] = MAX;
}

int main() {

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> podo[i];
	}
	
	dp[0] = podo[0];
	dp[1] = podo[0] + podo[1];

	for (int i = 2; i < n; i++) {
		get_dp(i);
	}

	cout << dp[n-1];

	return 0;
}