/* 23. 09. 30 */
#include <bits/stdc++.h>

using namespace std;

int N, M;
deque<bool> vip;
vector<int> dp;

int Go(int idx)
{
	if (idx >= N - 1) { return 1; }
	if (vip[idx]) { return Go(idx + 1); }

	int& ret{ dp[idx] };
	if (~ret) { return ret; }
	
	ret = 0;
	if (!vip[idx + 1]) { ret += Go(idx + 1) + Go(idx + 2); }
	else { ret += Go(idx + 1); }

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vip.resize(N);
	vector<int>(N, -1).swap(dp);
	for (int i{ 0 }; i < M; ++i) {
		int idx;
		cin >> idx;
		vip[--idx] = true;
	}

	cout << Go(0);

	return 0;
}