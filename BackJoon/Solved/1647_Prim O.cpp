/* 23. 09. 19 */
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> edge;
deque<bool> visited;

int Prim()
{
	int ret{ 0 }, maxCost{ 0 };
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 0));

	for (int i{ 0 }; i < N; ++i) {
		while (!pq.empty() && visited[pq.top().second]) { pq.pop(); }

		auto [cost, here] { pq.top() };
		visited[here] = true;
		ret += cost;
		maxCost = max(maxCost, cost);

		for (auto [there, nextCost] : edge[here]) {
			pq.push(make_pair(nextCost, there));
		}
	}

	return ret - maxCost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	edge.resize(N);
	visited.resize(N);
	int from, to, cost;
	for (int i{ 0 }; i < M; ++i) {
		cin >> from >> to >> cost;
		edge[--from].push_back(make_pair(--to, cost));
		edge[to].push_back(make_pair(from, cost));
	}

	cout << Prim();

	return 0;
}