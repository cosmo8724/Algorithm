/* 23. 09. 11 */
#include <bits/stdc++.h>

using namespace std;

long long S, C, sum, lo, hi, mid, len, ret;
vector<long long> pa;

bool Check(long long value)
{
	long long cnt = 0;
	for (const auto& _len : pa) {
		cnt += _len / value;
	}
	return cnt >= C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> S >> C;
	pa.resize(S);
	for (int i{ 0 }; i < S; ++i) {
		cin >> pa[i];
		sum += pa[i];
	}
	
	lo = 1;
	hi = *max_element(cbegin(pa), cbegin(pa));

	while (lo <= hi) {
		mid = (lo + hi) / 2;

		if (Check(mid)) {
			lo = mid + 1;
			len = mid;
		}
		else { hi = mid - 1; }
	}

	ret = sum - len * C;

	cout << ret;

	return 0;
}