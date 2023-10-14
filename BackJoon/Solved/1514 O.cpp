/* 23. 10. 06 */
#include <bits/stdc++.h>

using namespace std;

const int CW{ 1 }, CCW{ -1 };
int N, dp[101][10][10][10][2];
vector<int> current, target;

int Mod(int value)
{
	return value < 0 ? value + 10 : value % 10;
}

int Roll(int idx, int RollCountHere, int RollCountNext, int RollCountDoubleNext, int dir)
{
	if (idx == N) { return 0; }

	int& ret{ dp[idx][RollCountHere][RollCountNext][RollCountDoubleNext][dir] };
	if (~ret) { return ret; }
	if (Mod(RollCountHere + current[idx]) == target[idx]) {
		return ret = min(Roll(idx + 1, RollCountNext, RollCountDoubleNext, 0, 1), Roll(idx + 1, RollCountNext, RollCountDoubleNext, 0, 0));
	}

	ret = static_cast<int>(1e9);
	int direction{ dir ? CW : CCW };

	for (int i{ 1 }; i <= 3; ++i) {
		ret = min(ret, 1 + Roll(idx, Mod(RollCountHere + direction * i), RollCountNext, RollCountDoubleNext, dir));
		ret = min(ret, 1 + Roll(idx, Mod(RollCountHere + direction * i), Mod(RollCountNext + direction * i), RollCountDoubleNext, dir));
		ret = min(ret, 1 + Roll(idx, Mod(RollCountHere + direction * i), Mod(RollCountNext + direction * i), Mod(RollCountDoubleNext + direction * i), dir));
	}

	return ret;
}

int main()
{
	cin >> N;
	current.resize(N);
	target.resize(N);
	for (int i{ 0 }; i < N; ++i) { scanf_s("%1d", &current[i]); }
	for (int i{ 0 }; i < N; ++i) { scanf_s("%1d", &target[i]); }

	memset(dp, -1, sizeof(dp));
	cout << min(Roll(0, 0, 0, 0, 1), Roll(0, 0, 0, 0, 0));

	return 0;
}