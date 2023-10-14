/* 23. 09. 01 */
#include <bits/stdc++.h>

using namespace std;

int N, ret;
vector<pair<int, int>> v;

int main()
{
	cin >> N;
	v.resize(N);

	for (int i{ 0 }; i < N; ++i) { cin >> v[i].first >> v[i].second; }

	sort(begin(v), end(v));

	for (const auto& [st, ed] : v) {
		while (st > ret) { ++ret; }
		ret += ed;
	}

	cout << ret;

	return 0;
}