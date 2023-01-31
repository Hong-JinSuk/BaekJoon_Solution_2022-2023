#include<iostream>
#include<algorithm>
#include<sstream>
#include<queue>
#include<deque>
#include<vector>
using namespace std;

int T, n;
deque<int> num;
bool re;
bool isError;
vector<string> answer;

// ,을 제외해서 숫자 split 하는 함수
deque<string> split(string str, char Delimiter) {
	istringstream iss(str);
	string buffer;

	deque<string> result;

	while (getline(iss, buffer, Delimiter)) {
		result.push_back(buffer);
	}

	return result;
}
int main() {

	cin >> T;
	
	for (int i = 0; i < T; i++) {

		// 명령어 입력
		string Order;
		cin >> Order;
		queue<char> order;
		for (int i = 0; i < Order.size(); i++) {
			order.push(Order[i]);
		}
		
	    //배열에 들어있는 수 개수 입력
		cin >> n;

		// 수 입력
		string str;
		cin >> str;
		str.erase(remove(str.begin(), str.end(), '['));
		str.erase(remove(str.begin(), str.end(), ']'));
		deque<string> num = split(str, ',');

		// 명령어 실행
		int orderSize = order.size();
		for (int i = 0; i < orderSize; i++) {

			// 남은 숫자가 있거나, 없어도 R에 대한 연산은 가능하다.
			if (num.size() > 0 || order.front() == 'R') {
				// order가 R이면 뒤집혔다고 인식해주고, order를 빼낸다.
				if (order.front() == 'R') {
					// re 가 true면 false로, false면 true로 해준다.
					if (re) re = false;
					else re = true;
					order.pop();
				}
				// 뒤집혔다면 뒤에서 빼주고, 아니면 앞에서 빼준다.
				else {
					order.pop();
					if (re) num.pop_back();
					else num.pop_front();
				}
			}
			// 숫자가 없는데 명령어가 남았으면 에러다.
			else isError = true;
		}

		if (isError) answer.push_back("error");
		else {
			answer.push_back("[");
			if (re) {
				for (int i = num.size() - 1; i > -1; i--) {
					answer.push_back(num[i]);
					if (i > 0) answer.push_back(",");
				}
				answer.push_back("]");
			}
			else {
				for (int i = 0; i < num.size(); i++) {
					answer.push_back(num[i]);
					if (i < num.size() - 1) answer.push_back(",");
				}
				answer.push_back("]");
			}
		}

		num.clear();
		isError = false;
		re = false;
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
		if (answer[i] == "error" || answer[i] == "]") cout << endl;
	}
	 
	return 0;
}
