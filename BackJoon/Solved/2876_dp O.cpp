/* 23. 11. 10 */
/* 그래픽스 퀴즈 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> table;
vector<vector<int>> dp;
pair<int, int> ret;

int Go(int here, int grade)
{
	if (here >= N) { return 0; }
	if (table[here].first != grade && table[here].second != grade) { return 0; }

	int& _ret{ dp[here][grade] };
	if (~_ret) { return _ret; }
	_ret = 1;

	_ret += Go(here + 1, grade);

	return _ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	table.resize(N);
	vector<vector<int>>(N, vector<int>(6, -1)).swap(dp);
	for (int i{ 0 }; i < N; ++i) {
		cin >> table[i].first >> table[i].second;
	}

	for (int i{ 0 }; i < N; ++i) {
		int cnt{ Go(i, table[i].first) };
		if (ret.first < cnt) {
			ret.first = cnt;
			ret.second = table[i].first;
		}
		else if (ret.first == cnt) {
			ret.second = min(ret.second, table[i].first);
		}

		cnt = Go(i, table[i].second);
		if (ret.first < cnt) {
			ret.first = cnt;
			ret.second = table[i].second;
		}
		else if (ret.first == cnt) {
			ret.second = min(ret.second, table[i].second);
		}
	}

	cout << ret.first << ' ' << ret.second;

	return 0;
}