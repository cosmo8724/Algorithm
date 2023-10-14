/* 23. 10. 14 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int TC, N, M, T, S, G, H;
vector<vector<pair<int, int>>> edges;
vector<int> candidates, costs;

bool IsSmell(int from, int to)
{
	return (from == G && to == H) || (from == H && to == G);
}

void Dijk(int st)
{
	costs[st] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, st));

	while (!pq.empty()) {
		auto [cost, here] { pq.top() };
		pq.pop();

		if (cost > costs[here]) { continue; }

		for (auto [next, nextcost] : edges[here]) {
			nextcost += cost;
			if (costs[next] > nextcost) {
				costs[next] = nextcost;
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

	cin >> TC;
	while (TC--) {
		cin >> N >> M >> T >> S >> G >> H;

		vector<vector<pair<int, int>>>(N).swap(edges);
		for (int i{ 0 }, from, to, cost; i < M; ++i) {
			cin >> from >> to >> cost;
			cost *= 2;
			if (IsSmell(from, to)) { --cost; }
			edges[--from].push_back(make_pair(--to, cost));
			edges[to].push_back(make_pair(from, cost));
		}

		vector<int>(T).swap(candidates);
		for (int i{ 0 }; i < T; ++i) {
			cin >> candidates[i];
			--candidates[i];
		}
		sort(begin(candidates), end(candidates));

		vector<int>(N, INF).swap(costs);
		Dijk(--S);

		for (int i{ 0 }; i < T; ++i) {
			if (costs[candidates[i]] & 1) {
				cout << ++candidates[i] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}