#include<iostream>
#include<queue>
using namespace std;

int n, k;
bool isin[100];
vector<int> init;

int main() {

	cin >> n >> k;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		init.push_back(num);
	}

	int Min = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!isin[i]) { // 아직 탐색X인 수
			cnt++;
			isin[i] = true;
			int Min = init[i]; // 시작점
			for (int j = i + 1; j < n; j++) {
				if (init[j] > Min && !isin[j]) {
					Min = init[j];
					isin[j] = true;
				}
			}
		}
	}
	if (cnt <= k) cout << "YES";
	else cout << "NO";
}