/* 23. 09. 05 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ -1, 1, 0, 0 };
int dx[]{ 0, 0, 1, -1 };
int R, C, M;
int r, c, s, d, z;
int pos = -1, ret;
vector<vector<int>> mp;
map<pair<int, int>, pair<int, int>> sharks;
map<pair<int, int>, int> sharks_size;

int Execute_Fishing(int col)
{
	int _ret = 0;

	for (int i{ 0 }; i < R; ++i) {
		if (mp[i][col]) {
			_ret = mp[i][col];
			mp[i][col] = 0;
			sharks.erase({ i, col });
			sharks_size.erase({ i, col });
			break;
		}
	}

	return _ret;
}

void Move_Sharks()
{
	map<pair<int, int>, pair<int, int>> new_sharks;
	map<pair<int, int>, int> new_size;
	for (auto& [_pos, info] : sharks) {
		if (sharks_size[_pos] == 7) {
			int a = 10;
		}
		auto [cy, cx] = _pos;
		auto& [cnt, dir] = info;

		mp[cy][cx] = 0;
		int ny = cy, nx = cx;
		int curcnt = cnt;

		while (true) {
			ny = cy + curcnt * dy[dir];
			nx = cx + curcnt * dx[dir];

			if (ny >= 0 && nx >= 0 && ny < R && nx < C) { break; }
			else {
				if (dir <= 1) {
					if (ny < 0) {
						curcnt -= cy;
						cy = 0;
					}
					else {
						curcnt -= R - 1 - cy;
						cy = R - 1;
					}
				}
				else {
					if (nx < 0) {
						curcnt -= cx;
						cx = 0;
					}
					else {
						curcnt -= C - 1 - cx;
						cx = C - 1;
					}
				}
				dir ^= 1;
			}
		}

		if (auto [it, suc] { new_sharks.insert({ { ny, nx }, info }) }; suc == false) {
			if (new_size[it->first] < sharks_size[_pos]) {
				it->second = info;
				new_size[it->first] = sharks_size[_pos];
				mp[ny][nx] = new_size[it->first];
			}
		}
		else {
			new_size[it->first] = sharks_size[_pos];
			mp[ny][nx] = new_size[it->first];
		}
	}
	new_sharks.swap(sharks);
	new_size.swap(sharks_size);

	for (auto& [pos, size] : sharks_size) {
		mp[pos.first][pos.second] = size;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C >> M;
	vector<vector<int>>(R, vector<int>(C)).swap(mp);
	for (int i{ 0 }; i < M; ++i) {
		cin >> r >> c >> s >> d >> z;
		mp[--r][--c] = z;
		--d;
		if (d <= 1) { s %= 2 * (R - 1); }
		else { s %= 2 * (C - 1); }
		sharks[{r, c}] = { s, d };
		sharks_size[{r, c}] = z;
	}

	while (pos != C - 1) {
		++pos;
		ret += Execute_Fishing(pos);
		Move_Sharks();
	}

	cout << ret;

	return 0;
}