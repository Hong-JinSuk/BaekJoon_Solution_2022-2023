#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int n, x;

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> x;
		if (x) q.push(x);
		else {
			if (q.empty()) cout << "0\n";
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}

	return 0;
}