/* 23. 09. 05 */
#include <bits/stdc++.h>

using namespace std;

int N, ret_max = numeric_limits<int>::min(), ret_min = numeric_limits<int>::max();
vector<int> v, oper(4);

void dfs(int idx, int sum)
{
	if (idx == N) {
		ret_max = max(ret_max, sum);
		ret_min = min(ret_min, sum);
		return;
	}

	for (int i{ 0 }; i < 4; ++i) {
		if (oper[i] == 0) { continue; }

		--oper[i];
		if (i == 0) { dfs(idx + 1, sum + v[idx]); }
		else if (i == 1) { dfs(idx + 1, sum - v[idx]); }
		else if (i == 2) { dfs(idx + 1, sum * v[idx]); }
		else if (i == 3) { dfs(idx + 1, sum / v[idx]); }
		++oper[i];
	}
}

int main()
{
	cin >> N;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> v[i]; }
	for (int i{ 0 }; i < 4; ++i) { cin >> oper[i]; }

	dfs(1, v[0]);

	cout << ret_max << '\n' << ret_min;

	return 0;
}