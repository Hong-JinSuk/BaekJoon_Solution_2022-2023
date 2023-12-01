#include<iostream>
#include<vector>
using namespace std;

bool isvisited[2100004];
bool canMake[2100004];

int main() {
	ios_base::sync_with_stdio(false);

	int n; 
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		isvisited[num] = true;
		canMake[num] = true;
	}

	for (int i = 0; i < 2100000; i++) {
		if (!canMake[i]) {
			cout << i; return 0;
		}
		if (i == 0 || i == 1) continue;
		if (!isvisited[i]) continue;
		for (int j = 0; j < 2100000; j++) {
			if (i * j >= 2100000) break;
			if (!isvisited[j]) continue;
			canMake[i * j] = true;
		}
	}

	return 0;
}