/* 23. 09. 13 */
#include <bits/stdc++.h>

using namespace std;

int V, farNode;
long long maxcost;
vector<vector<pair<int, int>>> adj;
deque<bool> visited;

void dfs(int here, long long cost)
{
	visited[here] = true;

	if (maxcost < cost) {
		maxcost = cost;
		farNode = here;
	}

	for (auto [next, nextcost] : adj[here]) {
		if (visited[next]) { continue; }
		dfs(next, cost + nextcost);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V;
	adj.resize(V);
	for (int i{ 0 }; i < V; ++i) {
		int st, ed, cost;
		cin >> st;
		--st;
		while (true) {
			cin >> ed;
			if (ed == -1) { break; }
			cin >> cost;
			adj[st].push_back(make_pair(--ed, cost));
		}
	}
	
	visited.resize(V);
	dfs(0, 0);
	deque<bool>(V).swap(visited);
	maxcost = 0;
	dfs(farNode, 0);

	cout << maxcost;

	return 0;
}