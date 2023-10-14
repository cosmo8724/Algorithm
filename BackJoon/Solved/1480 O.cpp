/* 23. 09. 25 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_JEMS{ 14 }, MAX_BAGS{ 11 }, MAX_CAPACITY{ 21 };
int N, M, C, dp[MAX_BAGS][1 << MAX_JEMS][MAX_CAPACITY];
vector<int> jems;

int dfs(int bag_idx, int current_jems, int capacity)
{
	if (bag_idx == M) { return 0; }

	int& ret{ dp[bag_idx][current_jems][capacity] };
	if (ret) { return ret; }

	ret = max(ret, dfs(bag_idx + 1, current_jems, C));

	for (int i{ 0 }; i < N; ++i) {
		bool isIn{ static_cast<bool>(current_jems & (1 << i)) };
		bool isPossible{ capacity - jems[i] >= 0 };
		if (!isIn && isPossible) { ret = max(ret, dfs(bag_idx, current_jems | (1 << i), capacity - jems[i]) + 1); }
	}

	return ret;
}

int main()
{
	cin >> N >> M >> C;
	jems.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> jems[i]; }

	cout << dfs(0, 0, C);

	return 0;
}