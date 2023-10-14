/* 23. 09. 28 */
#include <bits/stdc++.h>

using namespace std;

int N, M, K, TC, a, b;
long long c;
vector<long long> v, tree;

long long Sum(int idx)
{
	long long ret{ 0 };
	while (idx > 0) {
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

void Update(int idx, long long num)
{
	while (idx < tree.size()) {
		tree[idx] += num;
		idx += (idx & -idx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	v.resize(N + 1);
	tree.resize(N + 1);
	for (int i{ 1 }; i <= N; ++i) {
		cin >> v[i];
		Update(i, v[i]);
	}

	TC = M + K;
	while (TC--) {
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff{ c - v[b] };
			v[b] = c;
			Update(b, diff);
		}
		else {
			cout << Sum(static_cast<int>(c)) - Sum(b - 1) << '\n';
		}
	}

	return 0;
}