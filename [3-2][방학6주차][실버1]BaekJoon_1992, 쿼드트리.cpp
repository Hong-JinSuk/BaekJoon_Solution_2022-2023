#include<iostream>
#include<stdio.h>

using namespace std;

int n;
int tree[64][64];
bool isSame;

void compressior(int x, int y, int size) {
	int compare = tree[x][y];
	int half_s = size / 2;
	isSame = true;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			// 모두 같은 0 or 1이 아니라면
			if (compare != tree[i][j]) {
				isSame = false;
				break;
			}
		}
	}

	if (isSame) {
		if (compare) cout << 1;
		else cout << 0;
	}

	else {
		cout << "(";
		compressior(x, y, half_s);
		compressior(x, y + half_s, half_s);
		compressior(x + half_s, y, half_s);
		compressior(x + half_s, y + half_s, half_s);
		cout << ")";
	}
}

int main() {

	cin >> n;

	// 영상 data를 넣어줌.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int data;
			scanf_s("%1d", &data);
			tree[i][j] = data;
		}
	}

	compressior(0, 0, n);

	return 0;
}