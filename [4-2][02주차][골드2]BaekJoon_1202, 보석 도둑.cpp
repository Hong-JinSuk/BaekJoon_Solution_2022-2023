#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, k, m, v, c;
vector<pair<int, int>> jewel;
priority_queue<int, vector<int>, greater<int>> bag;

// n : 보석수, m : 무게, v : 가격, k : 가방, c : 담을 수 있는 무게
void input() {

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		jewel.push_back({ m,v });
	}

	sort(jewel.begin(), jewel.end());

	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.push(c);
	}
	return;
}

// 아놔이거 int로 해놓고 몰라서 오래걸렸네...
long long solution() { 
	long long answer = 0;

	priority_queue<int, vector<int>, less<int>> price;
	int index = 0; // 탐색할 보석 순서

	while (!bag.empty()) { // 모든 배낭 탐색
		int cur_bag = bag.top();
		//cout << "Bag : " << cur << endl;
		bag.pop();
		// 현재 배낭으로 담을 수 있는 모든 보석 탐색
		while (index<jewel.size()) { 
			// 현재 가방으로 더 담을 수 없으면 break
			if (cur_bag < jewel[index].first) break;
			// 현재 가방으로 보석을 담을 수 있으면 그 가치를 넣음
			else if (cur_bag >= jewel[index].first) {
				//cout << "push price : " << jewel[index].second << endl;
				price.push(jewel[index].second);
				index++; // 다음보석 ㄱㄱ
			}
		}
		if (!price.empty()) { // 담을 수 있는 보석이 있다면
			//cout << "answer += " << price.top() << endl;
			answer += price.top(); // 그중 가장 비싼걸 담는다.
			price.pop();
		}
	}
	return answer;
}

int main() {

	input();
	cout << solution();

	return 0;
}