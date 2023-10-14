/* 23. 09. 18 */
#include <bits/stdc++.h>

using namespace std;

const int mod{ 1'000'007 };
int dy[]{ 0, 1 };
int dx[]{ 1, 0 };
int N, M, C;
vector<vector<int>> mp;
int dp[51][51][51][51];

int DFS(int y, int x, int limit, int cnt)
{
	if (y > N || x > M) { return 0; }
	if (y == N && x == M) {
		if (limit == 0 && mp[y][x] == 0) { return 1; }
		if (limit >= 1 && mp[y][x] > cnt) { return 1; }
		return 0;
	}

	int& ret{ dp[y][x][limit][cnt] };
	if (~ret) { return ret; }
	ret = 0;
	
	if (mp[y][x] == 0) {
		ret = (DFS(y + 1, x, limit, cnt) + DFS(y, x + 1, limit, cnt)) % mod;
	}
	else if (mp[y][x] > cnt) {
		ret = (DFS(y + 1, x, limit - 1, mp[y][x]) + DFS(y, x + 1, limit - 1, mp[y][x])) % mod;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> C;
	vector<vector<int>>(N + 1, vector<int>(M + 1)).swap(mp);
	for (int i{ 1 }; i <= C; ++i) {
		int y, x;
		cin >> y >> x;
		mp[y][x] = i;
	}

	memset(dp, -1, sizeof(dp));
	for (int i{ 0 }; i <= C; ++i) { cout << DFS(1, 1, i, 0) << ' '; }

	return 0;
}