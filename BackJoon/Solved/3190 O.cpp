/* 23. 09. 04 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ 0, 1, 0, -1 };
int dx[]{ 1, 0, -1, 0 };
int N, K, L, dir, curTime;
vector<vector<int>> mp;
deque<deque<bool>> visited;
deque<pair<int, int>> body;
queue<pair<int, char>> inputinfo;

int main()
{
	cin >> N >> K;
	vector<vector<int>>(N, vector<int>(N)).swap(mp);
	deque<deque<bool>>(N, deque<bool>(N)).swap(visited);
	body.push_back(make_pair(0, 0));
	while (K--) {
		int y, x;
		cin >> y >> x;
		mp[--y][--x] = 1;
	}

	cin >> L;
	while (L--) {
		int t;
		char _dir;
		cin >> t >> _dir;
		inputinfo.push(make_pair(t, _dir));
	}

	while (body.size()) {
		auto [cy, cx] = body.front();
		++curTime;

		int ny = cy + dy[dir];
		int nx = cx + dx[dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) { break; }

		if (mp[ny][nx]) { mp[ny][nx] = 0; }
		else {
			visited[body.back().first][body.back().second] = false;
			body.pop_back();
		}

		visited[ny][nx] = true;
		body.push_front(make_pair(ny, nx));

		if (curTime == inputinfo.front().first) {
			if (inputinfo.front().second == 'L') { dir = (dir + 3) % 4; }
			else { dir = (dir + 1) % 4; }
			inputinfo.pop();
		}
	}

	cout << curTime;

	return 0;
}