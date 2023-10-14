/* 23. 09. 12*/
#include <bits/stdc++.h>

using namespace std;

int N, ret;
vector<pair<int, int>> v;
vector<int> lis;

int main()
{
	cin >> N;
	v.resize(N);
	lis.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> v[i].first >> v[i].second; }
	sort(begin(v), end(v), [](const auto& pairA, const auto& pairB) {
		return pairA.second < pairB.second;
		});

	for (int i{ 0 }; i < N; ++i) {
		auto pos = lower_bound(begin(lis), begin(lis) + ret, v[i].first);
		if (*pos == 0) { ++ret; }
		*pos = v[i].first;
	}

	cout << N - ret;

	return 0;
}
