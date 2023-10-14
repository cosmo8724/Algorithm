/* 23. 09. 15 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int N;
vector<vector<int>> v, dp;

int TSP(int here, int visited)
{
	if (visited == (1 << N) - 1) { return v[here][0] ? v[here][0] : INF; }

	int& ret{ dp[here][visited] };
	if (ret != -1) { return ret; }
	
	ret = INF;
	for (int i{ 0 }; i < N; ++i) {
		if (visited & (1 << i) || v[here][i] == 0) { continue; }
		ret = min(ret, TSP(i, visited | (1 << i)) + v[here][i]);
	}

	return ret;
}

int main()
{
	cin >> N;
	vector<vector<int>>(N, vector<int>(N)).swap(v);
	vector<vector<int>>(N, vector<int>(1 << N, -1)).swap(dp);

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			cin >> v[i][j];
		}
	}

	cout << TSP(0, 1);

	return 0;
}