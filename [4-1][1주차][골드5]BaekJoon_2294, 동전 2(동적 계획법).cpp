#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k;

int main() {

	cin >> n >> k;

	vector<int> coin(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	vector<int> dp(k + 1);
	for (int i = 1; i <= k; i++) {
		dp[i] = 10001;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 10001) cout << -1;
	else cout << dp[k];

	return 0;
}