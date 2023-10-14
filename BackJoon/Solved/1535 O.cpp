/* 23. 09. 19 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_HEALTH{ 100 };
int N;
vector<int> dp, health, happy;

int main()
{
	cin >> N;
	dp.resize(MAX_HEALTH + 1);
	health.resize(N);
	happy.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> health[i]; }
	for (int i{ 0 }; i < N; ++i) { cin >> happy[i]; }

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 100 }; j >= health[i]; --j) {
			dp[j] = max(dp[j - health[i]] + happy[i], dp[j]);
		}
	}

	cout << dp[99];

	return 0;
}