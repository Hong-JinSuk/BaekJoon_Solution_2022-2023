#include<iostream>
#include<stack>
#include<string>
#include <vector>
using namespace std;

bool isQuit = false;

int Formatting(string str) {
	if (str == "NUM") return 0;
	if (str == "POP") return 1;
	if (str == "INV") return 2;
	if (str == "DUP") return 3;
	if (str == "SWP") return 4;
	if (str == "ADD") return 5;
	if (str == "SUB") return 6;
	if (str == "MUL") return 7;
	if (str == "DIV") return 8;
	if (str == "MOD") return 9;
}

void input_order(vector<pair<int, int>>& Order) {
	string str;
	while (cin >> str) {
		if (str == "QUIT") {
			isQuit = true;
			return;
		}
		if (str == "END") break;
		else if (str == "NUM") {
			long long num;
			cin >> num;
			Order.push_back({ Formatting(str),num });
		}
		else {
			Order.push_back({ Formatting(str),0 });
		}
	}
	return;
}

void solution() {

	vector<pair<int, int>> Order;

	//cout << "input_order\n";
	input_order(Order);

	if (isQuit) return;

	long long First, Second;

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		bool isError = false;
		stack<long long> s;
		//cout << "input_stack\n";
		int s_push;
		cin >> s_push;
		s.push(s_push);
		for (auto x : Order) {
			if (isError) {
				break;
			}
			switch (x.first) {
			case 0: //NUM
				if (x.second > 1000000000 || x.second < -1000000000) {
					isError = true;
					break;
				}
				s.push(x.second);
				break;
			case 1: //POP
				if (s.empty()) {
					isError = true;
					break;
				}
				else {
					s.pop();
					break;
				}
			case 2: //INV
				s.top() *= -1;
				break;
			case 3: //DUP
				if (s.empty()) {
					isError = true;
					break;
				}
				else {
					s.push(s.top());
					break;
				}
			case 4://SWP
				if (s.size() < 2) {
					isError = true;
					break;
				}
				First = s.top();
				s.pop();
				Second = s.top();
				s.pop();
				s.push(First);
				s.push(Second);
				break;
			case 5://ADD
				if (s.size() < 2) {
					isError = true;
					break;
				}
				First = s.top();
				s.pop();
				Second = s.top();
				s.pop();
				if (First + Second > 1000000000 || First + Second < -1000000000) {
					isError = true;
					break;
				}
				s.push(First + Second);
				break;
			case 6://SUB
				if (s.size() < 2) {
					isError = true;
					break;
				}
				First = s.top();
				s.pop();
				Second = s.top();
				s.pop();
				if (Second - First > 1000000000 || Second - First < -1000000000) {
					isError = true;
					break;
				}
				s.push(Second - First);
				break;
			case 7://MUL
				if (s.size() < 2) {
					isError = true;
					break;
				}
				First = s.top();
				s.pop();
				Second = s.top();
				s.pop();
				if (First * Second > 1000000000 || First * Second < -1000000000) {
					isError = true;
					break;
				}
				s.push(First * Second);
				break;
			case 8://DIV
				if (s.size() < 2) {
					isError = true;
					break;
				}
				First = s.top();
				s.pop();
				Second = s.top();
				s.pop();
				if (First == 0) {
					isError = true;
					break;
				}
				s.push(Second / First);
				break;
			case 9://MOD
				if (s.size() < 2) {
					isError = true;
					break;
				}
				First = s.top();
				s.pop();
				Second = s.top();
				s.pop();
				if (First == 0) {
					isError = true;
					break;
				}
				s.push(Second % First);
				break;
			default:
				break;
			}
		}
		if (s.size() != 1 || isError) {
			cout << "ERROR\n";
		}
		else {
			cout << s.top() << endl;
		}
	}
	return;
}

int main() {

	while (1) {
		if (isQuit) break;
		solution();
		cout << endl; // 아 이거때문에... 3시간을... 허허허
	}

	return 0;
}