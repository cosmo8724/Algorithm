/* 23. 09. 14 */
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> route;
deque<bool> visited;

int Prim()
{
	int ret{ 0 };
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 0));

	for (int i{ 0 }; i < N; ++i) {
		while (!pq.empty() && visited[pq.top().second]) { pq.pop(); }

		auto& [cost, here] { pq.top() };
		visited[here] = true;
		ret += cost;

		for (const auto& [next, cost] : route[here]) { pq.push(make_pair(cost, next)); }
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	route.resize(N);
	visited.resize(N);

	int from, to, cost;
	for (int i{ 0 }; i < M; ++i) {
		cin >> from >> to >> cost;
		route[--from].push_back(make_pair(--to, cost));
		route[to].push_back(make_pair(from, cost));
	}

	cout << Prim();

	return 0;
}