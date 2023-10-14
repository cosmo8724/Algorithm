/* 23. 09. 17 */
#include <bits/stdc++.h>

using namespace std;

int N;
long long sum{ numeric_limits<long long>::max() };
vector<long long> v;
tuple<int, int, int> ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> v[i]; }
	sort(begin(v), end(v));

	for (int base{ 0 }; base < N - 2; ++base) {
		int lo{ base + 1 }, hi{ N - 1 };

		while (lo < hi) {
			long long curSum{ v[base] + v[lo] + v[hi] };
			if (sum > abs(curSum)) {
				sum = abs(curSum);
				ret = make_tuple(base, lo, hi);
			}
			if (curSum < 0) { ++lo; }
			else { --hi; }
		}
	}

	cout << v[get<0>(ret)] << ' ' << v[get<1>(ret)] << ' ' << v[get<2>(ret)];

	return 0;
}