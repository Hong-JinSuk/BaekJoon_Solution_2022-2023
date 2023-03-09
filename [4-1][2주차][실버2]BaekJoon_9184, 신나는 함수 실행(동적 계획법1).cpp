#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

vector<tuple<int, int, int>> ans;

int a, b, c;
int dp[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}
	if (dp[a][b][c]) {
		return dp[a][b][c];
	}

	if (a < b && b < c) dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

	else dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

	return dp[a][b][c];
}

int main() {

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		ans.push_back({ a,b,c });
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << "w(" << get<0>(ans[i]) << ", " << get<1>(ans[i]) << ", " << get<2>(ans[i]) << ") = " << w(get<0>(ans[i]),get<1>(ans[i]),get<2>(ans[i])) << "\n";
	}

	return 0;
}