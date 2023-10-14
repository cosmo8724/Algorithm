/* 23. 09. 04 */
#include <bits/stdc++.h>

using namespace std;

int N, L, ret;
vector<pair<int, int>> hole;

int main()
{
	cin >> N >> L;
	hole.resize(N);

	for (int i{ 0 }; i < N; ++i) { cin >> hole[i].first >> hole[i].second; }
	sort(begin(hole), end(hole), [](const auto& pairA, const auto& pairB) {
		return pairA.second < pairB.second;
		});

	int idx = 0, cnt = 0;
	for (auto [from, to] : hole) {
		if (to <= idx) { continue; }
		if (from > idx) {
			cnt = (to - from) / L + ((to - from) % L ? 1 : 0);
			idx = from + cnt * L;
		}
		else {
			cnt = (to - idx) / L + ((to - idx) % L ? 1 : 0);
			idx = idx + cnt * L;
		}
		ret += cnt;
	}

	cout << ret;

	return 0;
}