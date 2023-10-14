/* 23. 09. 19 */
#include <bits/stdc++.h>
#include <array>

using namespace std;

const int TOTAL_SIZE{ 10 };
array<array<int, TOTAL_SIZE>, TOTAL_SIZE> mp;
array<int, 5> papers{ 5, 5, 5, 5, 5 };
int ret{ numeric_limits<int>::max() };

bool Check(int y, int x, int _size)
{
	for (int i{ y }; i < y + _size; ++i) {
		for (int j{ x }; j < x + _size; ++j) {
			if (i >= TOTAL_SIZE || j >= TOTAL_SIZE) { return false; }
			if (mp[i][j] == 0) { return false; }
		}
	}

	return true;
}

void Fill_Paper(int y, int x, int _size, int value)
{
	for (int i{ y }; i < y + _size; ++i) {
		for (int j{ x }; j < x + _size; ++j) {
			mp[i][j] = value;
		}
	}
}

void dfs(int y, int x, int cnt)
{
	if (cnt >= ret) { return; }

	if (x == TOTAL_SIZE) {
		dfs(y + 1, 0, cnt);
		return;
	}
	if (y == TOTAL_SIZE) {
		ret = min(ret, cnt);
		return;
	}
	if (mp[y][x] == 0) {
		dfs(y, x + 1, cnt);
		return;
	}

	for (int paper{ 5 }; paper >= 1; --paper) {
		if (papers[paper - 1] > 0 && Check(y, x, paper)) {
			--papers[paper - 1];
			Fill_Paper(y, x, paper, 0);
			dfs(y, x, cnt + 1);
			Fill_Paper(y, x, paper, 1);
			++papers[paper - 1];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i{ 0 }; i < 10; ++i) {
		for (int j{ 0 }; j < 10; ++j) {
			cin >> mp[i][j];
		}
	}

	dfs(0, 0, 0);

	cout << (ret == numeric_limits<int>::max() ? -1 : ret);

	return 0;
}