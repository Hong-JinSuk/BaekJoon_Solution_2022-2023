#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int n, m;
int indegree[1001];
map<string, int> Living;
map<int, string> Living_;
vector<string> C[1001]; // 부모의 자식들
vector<string> real_child[1001];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string name; cin >> name;
		Living[name] = i; // 이름별 index 부여
		Living_[i] = name;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		string x, y; cin >> x >> y;
		int Parent = Living[y];
		int Child = Living[x];
		C[Parent].push_back(x);
		indegree[Child]++;
	}
}

void sol() {
	int answer = 0;
	vector<string> root;
	for (int i = 1; i <= n; i++) { // 시초 걸러내기
		if (indegree[i] == 0) {
			answer++;
			root.push_back(Living_[i]);
		}
	}
	cout << answer << endl;

	sort(root.begin(), root.end());
	for (int i = 0; i < root.size(); i++) {
		cout << root[i] << " ";
	}
	cout << endl;

	
	while (!root.empty()) { // 직계자식 걸러내기
		string parent = root.back(); root.pop_back();
		int parent_index = Living[parent];


		for (int i = 0; i < C[parent_index].size(); i++) {
			int p_child = Living[C[parent_index][i]];
			indegree[p_child]--;
			if (indegree[p_child] == 0) { // 직계자식이면(더이상 부모 X)
				real_child[parent_index].push_back(C[parent_index][i]);
				root.push_back(Living_[p_child]);
			}
		}
	}

	vector<pair<string, pair<int, vector<string>>>> Answer;
	for (int i = 1; i <= n; i++) {
		string name = Living_[i];
		int Child = real_child[i].size();
		Answer.push_back({ name,{Child,real_child[i]} });
	}
	sort(Answer.begin(), Answer.end());
	for (auto& x : Answer) {
		sort(x.second.second.begin(), x.second.second.end());
	}
	for (int i = 0; i < Answer.size(); i++) {
		cout << Answer[i].first << " " << Answer[i].second.first << " ";
		for (int j = 0; j < Answer[i].second.second.size(); j++) {
			cout << Answer[i].second.second[j] << " ";
		}
		cout << endl;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	input();
	sol();
	return 0;
}