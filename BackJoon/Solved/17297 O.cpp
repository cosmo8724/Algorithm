/* 23. 10. 01 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_N{ 40 };
int M;
vector<int> dp(MAX_N);

int main()
{
	cin >> M;
	dp[0] = 0;
	dp[1] = 5;	// Messi
	dp[2] = 13;	// Messi Gimossi

	for (int i{ 3 }; i < MAX_N; ++i) { dp[i] = dp[i - 1] + dp[i - 2] + 1; }
	for (int i{ MAX_N - 1 }; i >= 2; --i) {
		if (M >= dp[i]) {
			M -= dp[i] + 1;
		}
	}

	--M;
	if (M == 5 || M == -1) { cout << "Messi Messi Gimossi"; }
	else { cout << string("Messi Gimossi")[M]; }

	return 0;
}