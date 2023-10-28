/* 23. 10. 28 */
/* 크림 파스타 */
#include <bits/stdc++.h>

using namespace std;

int N, Min_Num{ numeric_limits<int>::max() }, Min_Idx;
vector<int> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	dp.resize(N);

	for (int i{ 0 }, Num; i < N; ++i) {
		cin >> Num;
		Min_Num = min(Min_Num, Num);
		if (i) { dp[i] = Num - Min_Num > dp[i - 1] ? Num - Min_Num : dp[i - 1]; }
		cout << dp[i] << ' ';
	}

	return 0;
}