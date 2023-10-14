/* 23. 09. 08 */
#include <bits/stdc++.h>

using namespace std;

int N, M, ret = numeric_limits<int>::max();
int lo = 1, hi;
vector<int> v;

bool Check(long long mid)
{
	int num = 0;

	for (int i{ 0 }; i < M; ++i) {
		num += v[i] / mid;
		if (v[i] % mid) { ++num; }
	}

	return N >= num;
}

int main()
{
	cin >> N >> M;
	v.resize(M);
	for (int i{ 0 }; i < M; ++i) {
		cin >> v[i];
		hi = max(hi, v[i]);
	}

	while (lo <= hi) {
		long long mid = (lo + hi) >> 1;
		if (Check(mid)) {
			ret = min(ret, static_cast<int>(mid));
			hi = mid - 1;
		}
		else { lo = mid + 1; }
	}

	cout << ret;

	return 0;
}