/* 23. 09. 08 */
#include <bits/stdc++.h>

using namespace std;

int N, M, lo, hi, mx, ret = numeric_limits<int>::max();
vector<int> v;

bool Check(int mid)
{
	if (mid < mx) { return false; }
	int cnt = 0, sum = 0;;
	for (int i{ 0 }; i < N; ++i) {
		if (sum + v[i] > mid) {
			sum = 0;
			cnt++;
		}
		sum += v[i];
	}
	if (sum) { ++cnt; }

	return cnt <= M;
}

int main()
{
	cin >> N >> M;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) {
		cin >> v[i];
		hi += v[i];
	}
	mx = *max_element(begin(v), end(v));

	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (Check(mid)) {
			ret = min(ret, mid);
			hi = mid - 1;
		}
		else { lo = mid + 1; }
	}

	cout << ret;

	return 0;
}