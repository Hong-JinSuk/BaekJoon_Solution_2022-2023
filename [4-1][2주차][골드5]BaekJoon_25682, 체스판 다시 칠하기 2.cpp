#include<iostream>

using namespace std;

int n, m, k;
char Board[2001][2001];
int numBoard[2001][2001];
int SumBoard[2001][2001];

void makeSum() {

	// 이부분에서 0부터 시작하는 이유는 가장자리도 포함을 해야하기 때문.
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			SumBoard[i][j + 1] = SumBoard[i][j] + numBoard[i][j + 1];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < n; j++) {
			SumBoard[j + 1][i] = SumBoard[j][i] + SumBoard[j + 1][i];
		}
	}
}

int partSum(int x, int y) {
	return (SumBoard[x][y] + SumBoard[x - k][y - k] - SumBoard[x - k][y] - SumBoard[x][y - k]);
}

int chess(char Color) {
	
	int val;

	// numBoard 구함. <- Color로 시작하는 체스판과 일치하는 부분=0 불일치=1
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// i+j가 짝수인 부분이 Board와 Color 값이 맞으면 0 아니면 1
			if ((i + j) % 2 == 0) val = Board[i][j] == Color ? 0 : 1;
			else val = Board[i][j] == Color ? 1 : 0;
			numBoard[i][j] = val;
		}
	}

	// sumBoard를 만들어서 누적합 보드를 만듦.
	makeSum();

	int answer = 99999999;
	for (int i = k; i <= n; i++) {
		for (int j = k; j <= m; j++) {
			answer = min(partSum(i, j), answer);
		}
	}
	return answer;
}

int main() {

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Board[i][j];
		}
	}
	cout << min(chess('B'), chess('W')) << endl;

	return 0;
}