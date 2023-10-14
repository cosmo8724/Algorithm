/* 23. 09. 17 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<function<int(int)>> oper{
	[](int n) { return n / 3; },
	[](int n) { return n / 2; },
	[](int n) { return n - 1; }
};
vector<int> dp;

void Print(int n)
{
	if (n == 0) { return; }
	cout << n << ' ';

	if (n % 3 == 0 && dp[n / 3] == dp[n] - 1) { Print(n / 3); }
	else if (n % 2 == 0 && dp[n / 2] == dp[n] - 1) { Print(n / 2); }
	else if (n - 1 >= 0) { Print(n - 1); }

	return;
}

int main()
{
	cin >> N;
	vector<int>(N + 1, static_cast<int>(1e9)).swap(dp);

	dp[1] = 0;
	for (int i{ 1 }; i <= N; ++i) {
		if (i % 3 == 0) { dp[i] = min(dp[i], dp[i / 3] + 1); }
		if (i % 2 == 0) { dp[i] = min(dp[i], dp[i / 2] + 1); }
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}

	cout << dp[N] << '\n';

	Print(N);

	return 0;
}