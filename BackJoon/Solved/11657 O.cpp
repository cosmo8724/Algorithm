/* 23. 09. 28 */
#include <bits/stdc++.h>

using namespace std;

const long long INF{ static_cast<long long>(2e9) };
int N, M;
vector<vector<pair<int, int>>> buses;
vector<long long> costs;

bool Bellman(int st)
{
	costs[st] = 0;

	for (int i{ 0 }; i <= N; ++i) {
		for (int here{ 0 }; here < N; ++here) {
			for (auto [to, cost] : buses[here]) {
				if (costs[here] != INF && costs[to] > costs[here] + cost) {
					if (i == N) { return true; }
					costs[to] = costs[here] + cost;
				}
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<long long>(N, INF).swap(costs);
	buses.resize(N);

	int from, to, cost;
	for (int i{ 0 }; i < M; ++i) {
		cin >> from >> to >> cost;
		buses[--from].push_back(make_pair(--to, cost));
	}

	if (Bellman(0)) { cout << -1 << '\n'; }
	else {
		for (int i{ 1 }; i < N; ++i) {
			cout << (costs[i] == INF ? -1 : costs[i]) << '\n';
		}
	}

	return 0;
}