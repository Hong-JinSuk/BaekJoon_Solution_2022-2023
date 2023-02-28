#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int n, X;
// 이렇게하면 오름차순도 가능~
//priority_queue<int, vector<int>, greater<int>> pos;
priority_queue<int> neg, pos;

int main() {

	cin >> n;
	while (n--) {
		cin >> X;

		// 0 이아니면 push
		if (X) {
			// 내림차순 배열이라서 음수로 넣어줌
			if (X > 0) pos.push(-X);
			else if (X < 0) neg.push(X);
		}
		// 0 이면
		else {
			// 배열이 둘다 비어있으면
			if (pos.empty() && neg.empty()) cout << "0\n";
			// 양수쪽만 비어있으면
			else if (pos.empty()) {
				cout << neg.top() << "\n";
				neg.pop();
			}
			// 음수쪽만 비어있으면
			else if (neg.empty()) {
				cout << abs(pos.top()) << "\n";
				pos.pop();
			}
			// 둘다 있으면 크기비교
			else {
				if (pos.top() > neg.top()) {
					cout << abs(pos.top()) << "\n";
					pos.pop();
				}
				else {
					cout << neg.top() << "\n";
					neg.pop();
				}
			}
		}
	}

	return 0;
}