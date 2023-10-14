/* 23. 09. 28 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ numeric_limits<int>::max() };
int V, E, K;
vector<vector<pair<int, int>>> edges;
vector<int> costs;

void Dijk(int st)
{
	costs[st] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, st));

	while (!pq.empty()) {
		auto [cost, here] { pq.top() };
		pq.pop();

		if (costs[here] < cost) { continue; }

		for (auto [next, next_cost] : edges[here]) {
			int total_cost{ next_cost + cost };
			if (costs[next] > total_cost) {
				costs[next] = total_cost;
				pq.push(make_pair(total_cost, next));
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E >> K;
	edges.resize(V);
	vector<int>(V, INF).swap(costs);
	--K;

	int from, to, cost;
	for (int i{ 0 }; i < E; ++i) {
		cin >> from >> to >> cost;
		edges[--from].push_back(make_pair(--to, cost));
	}

	Dijk(K);

	for (int i{ 0 }; i < V; ++i) {
		if (costs[i] == INF) { cout << "INF\n"; }
		else { cout << costs[i] << '\n'; }
	}

	return 0;
}