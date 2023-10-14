/* 23. 09. 21 */
#include <bits/stdc++.h>

using namespace std;

const int ROUND_TIME{ 5 }, MAX_TIME{ 90 }, TOTAL_ROUND{ MAX_TIME / ROUND_TIME };
double rateA, rateB;
vector<int> prime{ 2, 3, 5, 7, 11, 13, 17 };
vector<vector<double>> dp[TOTAL_ROUND];

bool IsPrime(int score)
{
	auto it{ lower_bound(cbegin(prime), cend(prime), score) };
	if (it == cend(prime)) { return false; }
	if (score == *it) { return true; }
	return false;
}

double dfs(int idx, int scoreA, int scoreB)
{
	if (idx == TOTAL_ROUND) { return IsPrime(scoreA) || IsPrime(scoreB) ? 1.0 : 0.0; }

	double& ret{ dp[idx][scoreA][scoreB] };
	if (ret > -numeric_limits<double>::epsilon()) { return ret; }

	ret = 0.0;
	ret += dfs(idx + 1, scoreA, scoreB) * (1.0 - rateA) * (1.0 - rateB);
	ret += dfs(idx + 1, scoreA + 1, scoreB) * rateA * (1.0 - rateB);
	ret += dfs(idx + 1, scoreA, scoreB + 1) * (1.0 - rateA) * rateB;
	ret += dfs(idx + 1, scoreA + 1, scoreB + 1) * rateA * rateB;

	return ret;
}

int main()
{
	cin >> rateA >> rateB;
	rateA /= 100;
	rateB /= 100;

	for (int i{ 0 }; i < TOTAL_ROUND; ++i) { vector<vector<double>>(TOTAL_ROUND, vector<double>(TOTAL_ROUND, -1.0)).swap(dp[i]); }

	cout << fixed << setprecision(6) <<  dfs(0, 0, 0);

	return 0;
}