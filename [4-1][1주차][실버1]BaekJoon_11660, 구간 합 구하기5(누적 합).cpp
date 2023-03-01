#include<iostream>

using namespace std;

int n, m, x_1, x_2, y_1, y_2;
int Sum[1025][1025];

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Sum[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			Sum[i][j] += Sum[i][j - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			Sum[j][i] += Sum[j - 1][i];
		}
	}

	while (m--) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		// 아래 출력에서 endl을 쓰면 시간 초과 발생
		cout << Sum[x_2][y_2] + Sum[x_1 - 1][y_1 - 1] - Sum[x_2][y_1-1] - Sum[x_1-1][y_2] << "\n"; 
	}

	return 0;
}
