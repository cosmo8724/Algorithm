/* 23. 09. 17 */
#include <bits/stdc++.h>

using namespace std;

long long N;
vector<long long> v;
pair<long long, long long> ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> v[i]; }

	long long lo{ 0 }, hi{ N - 1 }, sum{ abs(v[lo] + v[hi]) };
	ret = make_pair(v[lo], v[hi]);
	while (lo < hi) {
		long long curSum = v[lo] + v[hi];
		if (sum > abs(curSum)) {
			sum = abs(curSum);
			ret = make_pair(v[lo], v[hi]);
		}
		if (curSum < 0) { ++lo; }
		else { --hi; }
	}

	cout << ret.first << ' ' << ret.second;

	return 0;
}