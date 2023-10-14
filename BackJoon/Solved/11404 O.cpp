/* 23. 09. 28 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int N, M;
vector<vector<int>> costs;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<vector<int>>(N, vector<int>(N, INF)).swap(costs);
	for (int i{ 0 }; i < N; ++i) { costs[i][i] = 0; }

	int from, to, cost;
	for (int i{ 0 }; i < M; ++i) {
		cin >> from >> to >> cost;
		--from;
		--to;
		costs[from][to] = min(costs[from][to], cost);
	}

	for (int k{ 0 }; k < N; ++k) {
		for (int i{ 0 }; i < N; ++i) {
			for (int j{ 0 }; j < N; ++j) {
				costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
			}
		}
	}

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			cout << (costs[i][j] == INF ? 0 : costs[i][j]) << ' ';
		}
		cout << '\n';
	}

	return 0;
}