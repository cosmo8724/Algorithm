/* 23. 08. 31 */
#include <bits/stdc++.h>

using namespace std;

int N, endtime, ret;
vector<pair<int, int>> v;

int main()
{
	cin >> N;
	v.resize(N);

	for (int i{ 0 }; i < N; ++i) { cin >> v[i].first >> v[i].second; }

	sort(begin(v), end(v), [](const auto& pairA, const auto& pairB) {
		if (pairA.second == pairB.second) { return pairA.first < pairB.first; }
		return pairA.second < pairB.second;
		});

	for (int i{ 0 }; i < N; ++i) {
		if (endtime > v[i].first) { continue; }
		endtime = v[i].second;
		++ret;
	}

	cout << ret;

	return 0;
}