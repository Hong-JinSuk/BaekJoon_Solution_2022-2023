#include<iostream>

using namespace std;

int n, m, k;
char Board[2001][2001];
int numBoard[2001][2001];
int SumBoard[2001][2001];

void makeSum() {

	// �̺κп��� 0���� �����ϴ� ������ �����ڸ��� ������ �ؾ��ϱ� ����.
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

	// numBoard ����. <- Color�� �����ϴ� ü���ǰ� ��ġ�ϴ� �κ�=0 ����ġ=1
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// i+j�� ¦���� �κ��� Board�� Color ���� ������ 0 �ƴϸ� 1
			if ((i + j) % 2 == 0) val = Board[i][j] == Color ? 0 : 1;
			else val = Board[i][j] == Color ? 1 : 0;
			numBoard[i][j] = val;
		}
	}

	// sumBoard�� ���� ������ ���带 ����.
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