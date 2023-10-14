 /* 23. 09. 08 */
#include <bits/stdc++.h>

using namespace std;

int N, M, lo, hi, ret;
vector<int> v;

bool Check(int mid)
{
	int cnt = 1, sum = 0;
	for (int i{ 0 }; i < N; ++i) {
		if (sum + v[i] > mid) {
			sum = 0;
			++cnt;
		}
		sum += v[i];
	}
	if (sum > mid) { ++cnt; }

	return cnt <= M;
}

int main()
{
	cin >> N >> M;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> v[i]; }
	lo = *max_element(begin(v), end(v));
	hi = 1000000000;

	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (Check(mid)) {
			ret = mid;
			hi = mid - 1;
		}
		else { lo = mid + 1; }
	}

	cout << ret;

	return 0;
}