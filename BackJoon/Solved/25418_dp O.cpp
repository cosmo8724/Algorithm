/* 23. 11. 07 */
/* 정수 a를 k로 만들기 */
#include <bits/stdc++.h>

using namespace std;

int A, K;
vector<int> dp;

int main()
{
	cin >> A >> K;
	dp.resize(K + 1);

	for (int i{ A + 1 }; i <= K; ++i) {
		dp[i] = dp[i - 1] + 1;
		if (!(i & 1) && i / 2 >= A) { dp[i] = min(dp[i], dp[i / 2] + 1); }
	}

	cout << dp[K];

	return 0;
}