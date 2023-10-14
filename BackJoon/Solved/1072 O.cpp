/* 23. 09. 11 */
#include <bits/stdc++.h>

using namespace std;

long long X, Y, Z, ret{ -1 };

auto Check = [](long long value) {
	return floor(static_cast<double>((Y + value) * 100) / (X + value)) > Z;
};

int main()
{
	cin >> X >> Y;
	Z = static_cast<double>(Y * 100) / X;

	long long lo = 0, hi = static_cast<long long>(1e9);

	while (lo <= hi) {
		long long mid = (lo + hi) / 2;

		if (Check(mid)) {
			ret = mid;
			hi = mid - 1;
		}
		else { lo = mid + 1; }
	}

	cout << ret;

	return 0;
}