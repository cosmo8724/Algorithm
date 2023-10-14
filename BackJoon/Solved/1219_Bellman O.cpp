/* 23. 10. 12 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int N, st, ed, M;
vector<int> money, costs;
vector<tuple<int, int, int>> buses;

queue<int> Bellman(int _st)
{
	queue<int> cycle;
	costs[_st] = money[_st];

	for (int i{ 1 }; i <= N; ++i) {
		for (auto [from, to, cost] : buses) {
			/* From에서 번 돈 + To에서 벌 수 있는 돈 - To까지 가는데 드는 비용 */
			if (costs[from] != -INF && costs[to] < costs[from] + money[to] - cost) {
				costs[to] = costs[from] + money[to] - cost;
				if (i == N) { cycle.push(from); }
			}
		}
	}

	return cycle;
}

bool CheckPathToEnd(queue<int>&& cycle, int _ed)
{
	deque<bool> visited(N);
	while (!cycle.empty()) {
		int here{ cycle.front() };
		cycle.pop();

		for (auto [from, to, cost] : buses) {
			if (here != from || visited[to]) { continue; }
			if (to == _ed) { return true; }
			visited[to] = true;
			cycle.push(to);
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> st >> ed >> M;
	money.resize(N);
	vector<int>(N, -INF).swap(costs);
	buses.reserve(M);
	for (int i{ 0 }, from, to, cost; i < M; ++i) {
		cin >> from >> to >> cost;
		buses.push_back(make_tuple(from, to, cost));
	}
	for (int i{ 0 }; i < N; ++i) { cin >> money[i]; }

	bool isCycle{ CheckPathToEnd(Bellman(st), ed) };
	if (costs[ed] == -INF) { cout << "gg"; }
	else {
		if (isCycle) { cout << "Gee"; }
		else { cout << costs[ed]; }
	}

	return 0;
}