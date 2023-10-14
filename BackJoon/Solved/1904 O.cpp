/* 23. 09. 26 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> dp;
vector<int> dp2;

long long Go(int cntOne, int cntZero)
{
	if (cntOne + cntZero >= N) { return 1; }

	int& ret{ dp[cntOne][cntZero] };
	if (ret) { return ret; }

	ret += Go(cntOne + 1, cntZero);
	if (cntOne + cntZero <= N - 2) { ret += Go(cntOne, cntZero + 2); }

	return ret % 15746;
}

int main()
{
	cin >> N;
	//vector<vector<int>>(N + 1, vector<int>(N + 1)).swap(dp);
	//cout << Go(0, 0);
	dp2.resize(N + 1);
	dp2[0] = dp2[1] = 1;
	for (int i{ 2 }; i <= N; ++i) {
		dp2[i] = dp2[i - 1] + dp2[i - 2];
		dp2[i] %= 15746;
	}

	cout << dp2[N];

	return 0;
}