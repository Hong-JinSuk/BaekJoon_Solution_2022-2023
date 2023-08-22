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
	make_binary(len, length); // �������� ���ļ� 32+16+8+ ... ���·� ����
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
						if (height[h] == 1) { // 3���� 1�̸�
							Min = min(l, w);
							Min = min(Min, h); // Min = 3���� ���� ���� ��
							// ���̰� 2^Min�� ����� �ʿ��� ����
							// ex) 2,3,3 �̸� 2^8 �����ε�, ���̰� 4�� ����Ǻ��� = 4^3
							Need[Min] += pow(2,l+w+h) / pow(pow(2,Min), 3); 
						}
					}
				}
			}
		}
	}

	for (int i = 20; i > -1; i--) {
		if (i == 0) {
			if (Need[i] > Cube[i]) return -1; // ���� ��ä���
		}
		if (Need[i] > 0) {
			cout << "NEED_" << i << " : " << Need[i] << endl;
			if (Cube[i] >= Need[i]) { // ũ�Ⱑ �´� ť�� ������ ����ϴٸ�
				answer += Need[i];
			}
			else {
				Need[i] -= Cube[i]; // �ϴ� ��� ����
				answer += Cube[i]; // �׸�ŭ �߰�
				Need[i - 1] += Need[i] * 8; // �׺��� ������ 8���� �ʿ��� ����.
			}
		}
	}
	return answer;
}

int main() {

	input();
	cout << solution();
	//cout << endl;
	//�������� �� �� �ִ� �ڵ�
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