/* 23. 10. 11 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int N, M, S, D, u, v, p;
vector<vector<pair<int, int>>> edges;
vector<int> costs;

void Dijk(int st)
{
	vector<int>(N, INF).swap(costs);
	costs[st] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, st));

	while (!pq.empty()) {
		auto [cost, here] { pq.top() };
		pq.pop();

		if (costs[here] < cost) { continue; }

		for (auto [next, nextcost] : edges[here]) {
			if (nextcost == -1) { continue; }
			nextcost += cost;

			if (costs[next] > nextcost) {
				costs[next] = nextcost;
				pq.push(make_pair(nextcost, next));
			}
		}
	}
}

void EraseShortestPath(int ed)
{
	queue<int> q;
	q.push(ed);

	while (!q.empty()) {
		int here{ q.front() };
		q.pop();

		for (int prev{ 0 }; prev < N; ++prev) {
			const auto iter { find_if(begin(edges[prev]), end(edges[prev]), [&here](const pair<int, int>& mypair) {
				return mypair.first == here;
			}) };
			if (iter == end(edges[prev]) || iter->second == -1) { continue; }
			int& cost_to_here { iter->second };
			if (costs[here] == costs[prev] + cost_to_here) {
				cost_to_here = -1;
				q.push(prev);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true) {
		cin >> N >> M;
		if (!N && !M) { break; }
		cin >> S >> D;

		vector<vector<pair<int, int>>>(N).swap(edges);
		for (int i{ 0 }; i < M; ++i) {
			cin >> u >> v >> p;
			edges[u].push_back(make_pair(v, p));
		}

		Dijk(S);
		EraseShortestPath(D);
		Dijk(S);

		cout << (costs[D] == INF ? -1 : costs[D]) << '\n';
	}

	return 0;
}