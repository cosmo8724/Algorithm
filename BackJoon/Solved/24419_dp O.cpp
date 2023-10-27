/* 23. 10. 27 */
/* 알고리즘 수업 - 행렬 경로 문제 2 */
#include <bits/stdc++.h>
#include <array>

using namespace std;

constexpr int MAX_N{ 1'000 };
constexpr int MOD{ 1'000'000'007 };

template<typename T>
constexpr T MinV(const T a, const T b)
{
	if (a == 0 && b == 1) { return 0; }
	if (a == 1) { return 1; }
	return b - static_cast<long long>(MinV(b % a, a)) * b / a;
}

template<typename T, size_t n>
constexpr array<T, n + 1> MakeDP()
{
	array<T, n + 1> dp{};
	array<T, 2 * n + 1> facto{ 1 };

	for (int i{ 1 }; i <= 2 * n; ++i) { facto[i] = static_cast<long long>(facto[i - 1]) * i % MOD; }
	for (int i{ 1 }; i <= n; ++i) {
		T t{ MinV<T>(facto[i], MOD) };
		dp[i] = facto[2 * i] * (static_cast<long long>(t) * t % MOD) % MOD;
	}

	return dp;
}

int N;
constexpr auto dp{ MakeDP<int, MAX_N>() };

int main()
{
	cin >> N;
	cout << dp[N] << ' ' << N * N;

	return 0;
}