#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;
int n, k, num;
vector<int> coin;

int main() {

	cin >> n >> k;
	vector<int> DP(k + 1);

	/*vector<int> coin(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}*/


	vector<int> coin;
	while (n--) {
		cin >> num;
		coin.push_back(num);
	}

	sort(coin.begin(), coin.end());

	// 아무 동전도 선택하지 않은 경우
	DP[0] = 1;	

	// i는 모든 동전
	for (int i = 0; i < n; i++) {
		// j는 동전의 시작점
		for (int j = coin[i]; j <= k; j++) {
			DP[j] += DP[j - coin[i]];
		}
	}

	cout << DP[k];
	return 0;
}