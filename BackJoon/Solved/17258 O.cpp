/* 23. 10. 04 */
#include <bits/stdc++.h>

using namespace std;

int N, M, K, T;
vector<pair<int, int>> queries;
vector<int> cnt;
vector<vector<int>> dp;

int Go(int here, int remain, int prev_used)
{
	if (here == queries.size()) { return 0; }

	int& ret{ dp[here][remain] };
	if (ret) { return ret; }

	int need{ T - queries[here].second };
	int real_need = prev_used >= need ? 0 : need;

	if (remain >= real_need) {
		ret = max(Go(here + 1, remain - real_need, need) + queries[here].first, Go(here + 1, remain, 0));
	}
	else { ret = Go(here + 1, remain, 0); }

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K >> T;
	cnt.resize(N + 1);
	for (int i{ 0 }, _in, _out; i < M; ++i) {
		cin >> _in >> _out;
		if (_out > N) { _out = N + 1; }
		for_each(begin(cnt) + _in, begin(cnt) + _out, [](int& _cnt) { _cnt = min(++_cnt, T); });
	}

	int len{ 1 };
	for (int i{ 1 }; i < N; ++i) {
		if (cnt[i] != cnt[i + 1]) {
			queries.push_back(make_pair(len, cnt[i]));
			len = 0;
		}
		++len;
	}
	queries.push_back(make_pair(len, cnt[N]));

	vector<vector<int>>(queries.size(), vector<int>(K + 1)).swap(dp);
	cout << Go(0, K, 0);

	return 0;
}