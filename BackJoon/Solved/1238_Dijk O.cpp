/* 23. 10. 13 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int N, M, X, ret;
vector<vector<pair<int, int>>> edges, rev_edges;
vector<int> costs, rev_costs;

void Dijk(const vector<vector<pair<int, int>>>& _edges, vector<int>& _costs, int st)
{
	_costs[st] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, st));

	while (!pq.empty()) {
		auto [cost, here] { pq.top() };
		pq.pop();

		if (cost > _costs[here]) { continue; }

		for (auto [next, nextcost] : _edges[here]) {
			nextcost += cost;

			if (_costs[next] > nextcost) {
				_costs[next] = nextcost;
				pq.push(make_pair(nextcost, next));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> X;
	edges.resize(N);
	rev_edges.resize(N);
	vector<int>(N, INF).swap(costs);
	vector<int>(N, INF).swap(rev_costs);

	for (int i{ 0 }, from, to, cost; i < M; ++i) {
		cin >> from >> to >> cost;
		edges[--from].push_back(make_pair(--to, cost));
		rev_edges[to].push_back(make_pair(from, cost));
	}

	--X;
	Dijk(rev_edges, costs, X);
	Dijk(edges, rev_costs, X);

	for (int i{ 0 }; i < N; ++i) {
		ret = max(ret, costs[i] + rev_costs[i]);
	}

	cout << ret;

	return 0;
}