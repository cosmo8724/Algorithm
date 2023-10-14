/* 23. 09. 13 */
#include <bits/stdc++.h>

using namespace std;

int N, M, st, ed;
vector<vector<pair<int, int>>> buses;
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

		int size{ static_cast<int>(buses[here].size()) };
		for (int i{ 0 }; i < size; ++i) {
			auto [next, nextcost] { buses[here][i] };
			nextcost += cost;

			if (costs[next] > nextcost) {
				pq.push(make_pair(nextcost, next));
				costs[next] = nextcost;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	buses.resize(N);
	vector<int>(N, 1e9).swap(costs);
	int from, to, cost;
	for (int i{ 0 }; i < M; ++i) {
		cin >> from >> to >> cost;
		buses[--from].push_back(make_pair(--to, cost));
	}
	cin >> st >> ed;

	Dijk(--st);

	cout << costs[--ed];

	return 0;
}