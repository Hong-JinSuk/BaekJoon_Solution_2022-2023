#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cmath>
#define tu tuple<int,int,int>
using namespace std;

int n, m;
pair<int, int> Start;
char miro[51][51];
int next_x[] = { 1, -1, 0, 0 };
int next_y[] = { 0, 0, 1, -1 };
bool keys[6]; //a,b,c,d,e,f

long long Answer = 987654321;
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> miro[i][j];
			if (miro[i][j] == '0') Start = { j,i };
		}
	}
}

void BFS(tu cur) {

	bool isvisit[51][51] = { false };
	int x, y, cnt;
	tie(x, y, cnt) = cur;
	queue<tu> q;
	q.push(cur);
	isvisit[y][x] = true;
	cout << endl;
	while (!q.empty()) {

		int cx, cy, ctime;
		tie(cx, cy, ctime) = q.front();
		q.pop();
		cout << cy << ", " << cx << ", " << ctime << endl;
		if (ctime > Answer && Answer != 987654321) break;
		for (int i = 0; i < 4; i++) {
			int nx = cx + next_x[i];
			int ny = cy + next_y[i];

			if (!isvisit[ny][nx] && nx >= 0 && ny >= 0 && nx < m && ny < n) {
				// �ⱸ
				if (miro[ny][nx] == '1' && ctime + 1 < Answer) { //ctime + 1 < Answer �� ���ʿ�����,,? ctmie +1 = Answer �̿��� ���信 ���� ���ݾ�..
					Answer = ctime + 1;
					return;
				}
				// ��
				else if (miro[ny][nx] == '.' || miro[ny][nx] == '0') {
					q.push({ nx,ny,ctime + 1 });
				}
				// ����
				else if (miro[ny][nx] >= 'a' && miro[ny][nx] <= 'f') {
					if (!keys[miro[ny][nx] - 'a']) { // ���谡 ������
						keys[miro[ny][nx] - 'a'] = true;
						BFS({ nx,ny,ctime + 1 }); // ���踦 �����������ʹ� �ٽý���
						keys[miro[ny][nx] - 'a'] = false;
					}
					else {
						q.push({ nx,ny,ctime + 1 });
					}
				}
				// ��
				else if (miro[ny][nx] >= 'A' && miro[ny][nx] <= 'F') {
					if (keys[miro[ny][nx] - 'A']) { // ���谡 �ִٸ�
						q.push({ nx,ny,ctime + 1 });
					}
					else continue;
				}
				isvisit[ny][nx] = true;
			}

		}

	}

	return;
}


int main() {

	input();
	BFS({ Start.first,Start.second,0 });
	if (Answer == 987654321) cout << -1;
	else cout << Answer;
	return 0;
}

//#include<iostream>
//#include<vector>
//#include<queue>
//#include<tuple>
//using namespace std;
//
//int n, m;
//pair<int, int> Start;
//char Miro[51][51];
//bool isvisit[51][51][65]; // MAP[bitmask]
//int nx[] = { 1, -1, 0, 0 };
//int ny[] = { 0, 0, 1, -1 };
//
//void input() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> Miro[i][j];
//			if (Miro[i][j] == '0') Start = { j,i };
//		}
//	}
//}
//
//int BFS() {
//	queue<tuple<int, int, int>> q; //x,y,keys
//	q.push({ Start.first,Start.second, 0 });
//	int cnt = 0;
//
//	while (!q.empty()) {
//		cnt++;
//		int q_size = q.size();
//		//cout << endl;
//
//		for (int i = 0; i < q_size; i++) {
//
//			auto cur = q.front();
//			q.pop();
//			isvisit[get<1>(cur)][get<0>(cur)][get<2>(cur)] = true; // �������� ������� �湮
//			//cout << get<1>(cur) << ", " << get<0>(cur) << ", " << get<2>(cur) << endl;
//
//			for (int j = 0; j < 4; j++) {
//
//				int next_x = get<0>(cur) + nx[j];
//				int next_y = get<1>(cur) + ny[j];
//				int keys = get<2>(cur);
//
//				if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n) { // ���� ��
//					char next_map = Miro[next_y][next_x];
//					if (next_map == '1') return cnt;
//					if (next_map == '#') // ��
//						continue;
//					if (next_map == '.' && !isvisit[next_y][next_x][keys]) // ��
//						q.push({ next_x,next_y,keys });
//					if (next_map >= 'A' && next_map <= 'F') { // ��
//						int key = next_map - 'A'; // �� ����
//						// ���� �´� Ű�� �ְ�, ���� �湮���� ���� ���
//						if (keys & (1 << key) && !isvisit[next_y][next_x][keys]) {
//							q.push({ next_x,next_y,keys });
//						}
//					}
//					if (next_map >= 'a' && next_map <= 'f') { // �����
//						int key = next_map - 'a'; // ���� �����ϰ�
//						//keys |= (1 << key); // ���踦 ȹ���� ������ ���ش�.
//						if (!isvisit[next_y][next_x][keys |= (1 << key)])
//							q.push({ next_x,next_y,keys |= (1 << key) }); // �� ���踦 ���� ���·� ��������
//					}
//					if (next_map == '0') {
//						if (!isvisit[next_y][next_x][keys]) q.push({ next_x,next_y,keys });
//					}
//				}
//			}
//		}
//	}
//	return -1;
//}
//
//int main() {
//
//	input();
//	cout << BFS();
//
//	return 0;
//}