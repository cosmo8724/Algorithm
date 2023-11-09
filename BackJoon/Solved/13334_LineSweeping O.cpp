/* 23. 11. 10 */
/* 철로 */
#include <bits/stdc++.h>

using namespace std;

int N, d, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) {
		cin >> v[i].first >> v[i].second;
		if (v[i].first > v[i].second) { swap(v[i].first, v[i].second); }
	}
	cin >> d;

	sort(begin(v), end(v), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
		if (lhs.second == rhs.second) { return lhs.first < rhs.first; }
		return lhs.second < rhs.second;
	});

	int l, r, cnt{ 0 };
	for (int i{ 0 }; i < N; ++i) {
		r = v[i].second;
		l = r - d;

		while (!pq.empty() && pq.top() < l) {
			--cnt;
			pq.pop();
		}

		if (v[i].first >= l) {
			++cnt;
			pq.push(v[i].first);

			ret = max(ret, cnt);
		}
	}

	cout << ret;

	return 0;
}