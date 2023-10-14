/* 23. 10. 11 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int N, M, ret;
vector<vector<pair<int, int>>> edges;
vector<int> costs_fox, costs_wolf[2];

void Dijk_fox(int st)
{
	costs_fox[st] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, st));

	while (!pq.empty()) {
		auto [cost, here] { pq.top() };
		pq.pop();

		if (cost > costs_fox[here]) { continue; }

		for (auto [next, nextcost] : edges[here]) {
			nextcost += cost;
			if (costs_fox[next] > nextcost) {
				costs_fox[next] = nextcost;
				pq.push(make_pair(nextcost, next));
			}
		}
	}
}

void Dijk_wolf(int st)
{
	costs_wolf[0][st] = 0;

	priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq;
	pq.push(make_tuple(0, st, false));

	while (!pq.empty()) {
		auto [cost, here, state] { pq.top() };
		pq.pop();

		if (cost > costs_wolf[state][here]) { continue; }

		for (auto [next, nextcost] : edges[here]) {
			if (state) { nextcost <<= 1; }
			else { nextcost >>= 1; }
			nextcost += cost;
			if (costs_wolf[!state][next] > nextcost) {
				costs_wolf[!state][next] = nextcost;
				pq.push(make_tuple(nextcost, next, !state));
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
	edges.resize(N);
	vector<int>(N, INF).swap(costs_fox);
	vector<int>(N, INF).swap(costs_wolf[0]);
	vector<int>(N, INF).swap(costs_wolf[1]);

	for (int i{ 0 }, a, b, d; i < M; ++i) {
		cin >> a >> b >> d;
		edges[--a].push_back(make_pair(--b, d * 10));
		edges[b].push_back(make_pair(a, d * 10));
	}

	Dijk_fox(0);
	Dijk_wolf(0);

	for (int i{ 1 }; i < N; ++i) {
		if (costs_fox[i] < min(costs_wolf[0][i], costs_wolf[1][i])) {
			++ret;
		}
	}

	cout << ret;

	return 0;
}