/* 23. 10. 07 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_N{ 200'000 }, MOD{ 1'000'000'007 };
int N;
long long ret{ 1 };
vector<long long> cnt(MAX_N + 1), sum(MAX_N + 1);

long long Sum(vector<long long>& tree, int idx)
{
	long long _ret{ 0 };
	while (idx > 0) {
		_ret += tree[idx];
		idx -= idx & -idx;
	}
	return _ret;
}

long long GetDist(vector<long long>& tree, int from, int to)
{
	if (from > to) { return 0; }
	return Sum(tree, to) - Sum(tree, from - 1);
}

void Update(vector<long long>& tree, int idx, int value)
{
	while (idx <= MAX_N) {
		tree[idx] += value;
		idx += idx & -idx;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i{ 1 }, idx; i <= N; ++i) {
		cin >> idx;
		++idx;

		if (i != 1) {
			long long left{ idx * GetDist(cnt, 1, idx - 1) - GetDist(sum, 1, idx - 1) };
			long long right{ GetDist(sum, idx + 1, MAX_N) - idx * GetDist(cnt, idx + 1, MAX_N) };
			ret *= (left + right) % MOD;
			ret %= MOD;
		}

		Update(cnt, idx, 1);
		Update(sum, idx, idx);
	}

	cout << ret;

	return 0;
}