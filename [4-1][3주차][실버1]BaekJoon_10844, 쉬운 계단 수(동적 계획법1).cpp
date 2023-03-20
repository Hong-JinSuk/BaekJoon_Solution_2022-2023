#include<iostream>
#define endl "\n"
using namespace std;

int n;
int dp[10] = { 0,1,1,1,1,1,1,1,1,1 };
int temp[10];
int main() {

	cin >> n;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			temp[j] = dp[j];
		}
		for (int k = 0; k < 10; k++) {
			if (k == 0) dp[0] = temp[1];
			else if (k == 9) dp[9] = temp[8];
			else dp[k] = (temp[k - 1] + temp[k + 1]);
		}
		for (int k = 0; k < 10; k++) {
			dp[k] = dp[k] % 1000000000;
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[i];
		ans %= 1000000000;
	}
	cout << ans;

	return 0;
}