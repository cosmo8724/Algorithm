/* 23. 10. 25 */
/* 박성원 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN{ 51 };
int N, K;
vector<string> Nums;
vector<vector<long long>> dp;
vector<int> Cache(MAX_LEN), CacheStr;

int StringMod(string_view sv, const int div)
{
	int ret{ 0 }, len{ static_cast<int>(sv.size()) };
	for (int i{ 0 }; i < len; ++i) {
		ret *= 10;
		ret += sv[i] - '0';
		ret %= div;
	}
	return ret;
}

void Go()
{
	for (int here{ 0 }; here < (1 << N); ++here) {
		for (int i{ 0 }, next; i < N; ++i) {
			if (here & (1 << i)) { continue; }

			next = here | (1 << i);

			for (int j{ 0 }, nextK; j < K; ++j) {
				nextK = ((j * Cache[Nums[i].size()]) % K + CacheStr[i]) % K;
				dp[next][nextK] += dp[here][j];
			}
		}
	}
}

long long CalcGCD(long long Smaller, long long Bigger)
{
	if (Smaller > Bigger) { swap(Smaller, Bigger); }

	while (Smaller) {
		long long Remainder{ Bigger % Smaller };
		Bigger = Smaller;
		Smaller = Remainder;
	}

	return Bigger;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	Nums.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> Nums[i]; }
	cin >> K;

	vector<vector<long long>>(1 << N, vector<long long>(K)).swap(dp);
	dp[0][0] = 1;

	/* 자릿수 별로 나올 수 있는 나머지를 미리 계산해 둠. */
	Cache[0] = 1 % K;
	for (int i{ 1 }; i < MAX_LEN; ++i) {
		Cache[i] = (Cache[i - 1] * 10) % K;
	}


	/* 숫자를 K로 나눈 값. */
	CacheStr.resize(N);
	for (int i{ 0 }; i < N; ++i) {
		CacheStr[i] = StringMod(Nums[i], K);
	}

	Go();

	long long Denominator{ 1 }, Numerator{ dp[(1 << N) - 1][0] };
	for (int i{ 1 }; i <= N; ++i) { Denominator *= i; }
	long long gcd{ CalcGCD(Numerator, Denominator) };
	Denominator /= gcd;
	Numerator /= gcd;

	cout << Numerator << '/' << Denominator;

	return 0;
}