#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, k, cur;
int Time[100001];
bool visited[100001];

void Search(int n) {
	bool check = false;
	
	queue<int> q;
	q.push(n);

	visited[n] = true;
	while (!q.empty()) {

		cur = q.front();
		q.pop();
		
		if (cur == k) {
			cout << Time[cur];
			break;
		}
		if (cur * 2 <= 100000) {
			if (!visited[cur * 2] || Time[cur] < Time[cur * 2]) {
				//cout << "*2" << endl;
				q.push(cur * 2);
				visited[cur * 2] = true;
				Time[cur * 2] = Time[cur];
			}
		}
		if (cur + 1 <= 100000) {
			if (!visited[cur + 1] || Time[cur] < Time[cur + 1]) {
				//cout << "+1" << endl;
				q.push(cur + 1);
				visited[cur + 1] = true;
				Time[cur + 1] = Time[cur] + 1;
			}
		}

		if (cur - 1 >= 0) {
			if (!visited[cur - 1] || Time[cur] < Time[cur - 1]) {
				//cout << "-1" << endl;
				q.push(cur - 1);
				visited[cur - 1] = true;
				Time[cur - 1] = Time[cur] + 1;
			}
		}
	}

}

int main() {

	cin >> n >> k;
	Search(n);
	return 0;
}