/* 23. 09. 17 */
#include <bits/stdc++.h>

using namespace std;

string A, B, ret;
vector<vector<int>> dp;

int main()
{
	cin >> A >> B;
	A = " " + A;
	B = " " + B;

	int N{ static_cast<int>(B.size()) }, M{ static_cast<int>(A.size()) };
	vector<vector<int>>(N, vector<int>(M)).swap(dp);

	for (int i{ 1 }; i < N; ++i) {
		for (int j{ 1 }; j < M; ++j) {
			if (A[j] == B[i]) { dp[i][j] = dp[i - 1][j - 1] + 1; }
			else { dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); }
		}
	}

	int y{ N - 1 }, x{ M - 1 };
	while (dp[y][x]) {
		if (dp[y][x] == dp[y - 1][x]) { --y; }
		else if (dp[y][x] == dp[y][x - 1]) { --x; }
		else {
			ret.push_back(A[x]);
			--y;
			--x;
		}
	}

	cout << dp[N - 1][M - 1] << '\n';
	if (!ret.empty()) {
		for (int i{ static_cast<int>(ret.size() - 1) }; i >= 0; --i) { cout << ret[i]; }
	}

	return 0;
}