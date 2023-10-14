/* 23. 08. 12 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
int R, C;
vector<vector<char>> mp;
pair<int, int> pos;

bool CheckMeet(vector<vector<bool>>& visited, queue<pair<int, int>>& q)
{
	queue<pair<int, int>> ret;

	while (q.size()) {
		auto [cy, cx] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) { continue; }
			if (mp[ny][nx] == 'L') { return true; }

			visited[ny][nx] = true;

			if (mp[ny][nx] == 'X') { ret.push(make_pair(ny, nx)); }
			else { q.push(make_pair(ny, nx)); }
		}
	}

	ret.swap(q);

	return false;
}

queue<pair<int, int>> melt(vector<vector<bool>>& visited, queue<pair<int, int>>& q)
{
	queue<pair<int, int>> ret;

	while (q.size()) {
		auto [cy, cx] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) { continue; }
			if (visited[ny][nx]) { continue; }

			if (mp[ny][nx] == 'X') {
				visited[ny][nx] = true;
				mp[ny][nx] = '.';
				ret.push(make_pair(ny, nx));
			}
		}
	}

	return ret;
}

int main()
{
	cin >> R >> C;
	vector<vector<char>>(R, vector<char>(C, 0)).swap(mp);
	vector<vector<bool>> visited_water(R, vector<bool>(C, 0));
	vector<vector<bool>> visited_swan(R, vector<bool>(C, 0));
	queue<pair<int, int>> q_water;
	queue<pair<int, int>> q_swan;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mp[i][j];

			if (mp[i][j] == '.' || mp[i][j] == 'L') {
				if (mp[i][j] == 'L') {
					pos.first = i;
					pos.second = j;
				}
				visited_water[i][j] = true;
				q_water.push(make_pair(i, j));
			}
		}
	}

	visited_swan[pos.first][pos.second] = true;
	q_swan.push(make_pair(pos.first, pos.second));

	int day = 0;

	while (!CheckMeet(visited_swan, q_swan)) {
		day++;

		melt(visited_water, q_water).swap(q_water);
	}

	cout << day;

	return 0;
}