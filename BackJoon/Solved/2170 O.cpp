/* 23. 08. 31 */
#include <bits/stdc++.h>

using namespace std;

int N, l, r, ret;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v.resize(N);

	for (int i{ 0 }; i < N; ++i) { cin >> v[i].first >> v[i].second; }

	sort(begin(v), end(v));
	l = v[0].first;
	r = v[0].second;

	for (int i{ 1 }; i < N; ++i) {
		if (r < v[i].first) {
			ret += r - l;
			l = v[i].first;
			r = v[i].second;
		}
		else if (v[i].first <= r && v[i].second >= r) {
			r = v[i].second;
		}
	}

	ret += r - l;

	cout << ret;

	return 0;
}