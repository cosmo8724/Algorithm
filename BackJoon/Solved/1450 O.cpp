/* 23. 09. 23 */
#include <bits/stdc++.h>

using namespace std;

int N, C;
long long ret;
vector<int> v;

void Accumulate(int idx, int to, int sum, vector<int>& out_v)
{
	if (sum > C) { return; }
	if (idx == to) {
		out_v.push_back(sum);
		return;
	}

	Accumulate(idx + 1, to, sum + v[idx], out_v);
	Accumulate(idx + 1, to, sum, out_v);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> C;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> v[i]; }

	vector<int> ret1, ret2;
	Accumulate(0, N / 2, 0, ret1);
	Accumulate(N / 2, N, 0, ret2);
	sort(begin(ret1), end(ret1));
	sort(begin(ret2), end(ret2));

	for (int i : ret2) {
		if (i <= C) {
			ret += distance(begin(ret1), upper_bound(begin(ret1), end(ret1), C - i));
		}
	}

	cout << ret;

	return 0;
}