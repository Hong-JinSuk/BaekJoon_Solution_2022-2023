//#include<iostream>
//
//using namespace std;
//
//int N, K;
//bool alphabet[26];
//
//int main() {
//
//	cin >> N >> K;
//
//	if (K < 5) {
//		cout << 0;
//		return 0;
//	}
//
//
//	// 이미 읽을 수 있는 글자 컷
//	alphabet['a'-'a'] = true;
//	alphabet['n'-'a'] = true;
//	alphabet['t'-'a'] = true;
//	alphabet['i'-'a'] = true;
//	alphabet['c'-'a'] = true;
//
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//		int Cut = str.length() - 8;
//		str = str.substr(4, Cut);
//	}
//
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define r 3
#define n 4 // 4개중 3개 선택

int cArr[r] = { 0,};

void combination(int depth, int next) {
    if (depth == r) {
        for (int i = 0; i < 3; i++) {
            cout << cArr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = next; i <= n; i++) {
        cArr[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main(void) {
    cout << "조합 (순서x, 중복x)" << endl;
    combination(0, 1);

    return 0;
}
