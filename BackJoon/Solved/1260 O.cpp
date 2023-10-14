/* 23. 08. 16 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
int N, M, V, a, b;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int here)
{
	visited[here] = true;
	cout << here << ' ';

	for (int there : adj[here]) {
		if (visited[there]) { continue; }
		dfs(there);
	}

	return;
}

void bfs(int here)
{
	visited[here] = true;
	queue<int> q;
	q.push(here);

	while (q.size()) {
		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (int there : adj[cur]) {
			if (visited[there]) { continue; }
			visited[there] = true;
			q.push(there);
		}
	}

	return;
}

int main()
{
	cin >> N >> M >> V;
	adj.resize(N + 1);
	visited.resize(N + 1);
	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(V);
	cout << '\n';
	vector<bool>(N + 1, false).swap(visited);
	bfs(V);

	return 0;
}