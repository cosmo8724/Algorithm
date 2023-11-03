/* 23. 11. 03 */
/* 퇴사 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> works;
vector<int> dp;

int Go(int here)
{
	if (here >= N) { return 0; }
	if (dp[here]) { return dp[here]; }

	dp[here] = max(Go(here + 1), Go(here + works[here].first) + works[here].second);

	return dp[here];
}

int main()
{
	cin >> N;
	works.resize(N);
	dp.resize(N);

	for (int i{ 0 }; i < N; ++i) {
		cin >> works[i].first >> works[i].second;
		if (i + works[i].first > N) { works[i].second = 0; }
	}

	cout << Go(0);

	return 0;
}