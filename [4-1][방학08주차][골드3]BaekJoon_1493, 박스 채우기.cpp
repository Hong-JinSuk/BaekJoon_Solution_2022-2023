#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long int len, wid, hei;
int Cube[21];
int length[21]; // 2^20 > 10^6
int width[21];
int height[21];
long long int Need[21];

void make_binary(int x, int bin[]) {
	int i = 0;
	while (x > 0) {
		if (x % 2 == 1) {
			bin[i] = 1;
		}
		i++;
		x /= 2;
	}
}

void input() {
	cin >> len >> wid >> hei;
	make_binary(len, length); // 이진수로 고쳐서 32+16+8+ ... 형태로 만듬
	make_binary(wid, width);
	make_binary(hei, height);

	long long n, l, cnt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> cnt;
		Cube[l] = cnt;
	}
}

long long solution() {
	long long answer = 0;
	for (int l = 20; l > -1; l--) {
		int Min = 0;
		if (length[l] == 1) {
			for (int w = 20; w > -1; w--) {
				if (width[w] == 1) {
					for (int h = 20; h > -1; h--) {
						if (height[h] == 1) { // 3개다 1이면
							Min = min(l, w);
							Min = min(Min, h); // Min = 3개중 가장 작은 것
							// 길이가 2^Min인 블록이 필요한 갯수
							// ex) 2,3,3 이면 2^8 부피인데, 길이가 4인 블록의부피 = 4^3
							Need[Min] += pow(2,l+w+h) / pow(pow(2,Min), 3); 
						}
					}
				}
			}
		}
	}

	for (int i = 20; i > -1; i--) {
		if (i == 0) {
			if (Need[i] > Cube[i]) return -1; // 전부 못채우면
		}
		if (Need[i] > 0) {
			cout << "NEED_" << i << " : " << Need[i] << endl;
			if (Cube[i] >= Need[i]) { // 크기가 맞는 큐브 갯수가 충분하다면
				answer += Need[i];
			}
			else {
				Need[i] -= Cube[i]; // 일단 모두 넣음
				answer += Cube[i]; // 그만큼 추가
				Need[i - 1] += Need[i] * 8; // 그보다 작은건 8개가 필요함 ㅇㅇ.
			}
		}
	}
	return answer;
}

int main() {

	input();
	cout << solution();
	//cout << endl;
	//이진수를 볼 수 있는 코드
	/*for (int i = 20; i > -1; i--) {
		cout << length[i];
	}
	cout << endl;
	for (int i = 20; i > -1; i--) {
		cout << width[i];
	}
	cout << endl;
	for (int i = 20; i > -1; i--) {
		cout << height[i];
	}*/

	return 0;
}