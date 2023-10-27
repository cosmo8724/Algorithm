/* 23. 10. 27 */
/* 알고리즘 수업 - 행렬 경로 문제 1 */
#include <bits/stdc++.h>
#include <array>

using namespace std;

constexpr size_t MAX_N{ 15 };

template<typename T, size_t n>
constexpr array<array<T, n + 1>, n + 1> MakeDP()
{
	array<array<T, n + 1>, n + 1> dp{};
	for (int i{ 0 }; i <= n; ++i) {
		for (int j{ 0 }; j <= n; ++j) {
			if (i == 0 || j == 0) { dp[i][j] = 1; }
			else {
				dp[i][j] = dp[i - 1][j] % MOD + dp[i][j - 1] % MOD;
				dp[i][j] %= MOD;
			}
		}
	}
	return dp;
}

int N;
constexpr auto dp{ MakeDP<long long, MAX_N>() };

int main()
{
	cin >> N;
	cout << dp[N][N] << ' ' << N * N;

	return 0;
}