/* 23. 10. 25 */
/* 파스칼 삼각형 */
#include <bits/stdc++.h>

using namespace std;

int R, C, W, ret;
vector<vector<int>> dp, psum;

int main()
{
	cin >> R >> C >> W;
	dp.resize(R + W);
	psum.resize(R + W);
	for (int i{ 1 }; i <= R + W; ++i) {
		dp[i - 1].resize(i);
		dp[i - 1].front() = dp[i - 1].back() = 1;

		psum[i - 1].resize(i + 1);
		if (i > 2) {
			psum[i - 1][1] = 1;
			for (int j{ 1 }; j < i - 1; ++j) {
				dp[i - 1][j] = dp[i - 2][j - 1] + dp[i - 2][j];
				psum[i - 1][j + 1] = psum[i - 1][j] + dp[i - 1][j];
			}
			psum[i - 1][i] = psum[i - 1][i - 1] + dp[i - 1][i - 1];
		}
	}
	psum[0][1] = 1;
	psum[1][1] = 1;
	psum[1][2] = 2;

	for (int i{ R - 1 }, cnt{ 1 }; i < R + W - 1; ++i, ++cnt) {
		ret += psum[i][C + cnt - 1] - psum[i][C - 1];
	}

	cout << ret;

	return 0;
}