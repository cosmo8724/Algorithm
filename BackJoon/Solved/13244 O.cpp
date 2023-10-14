/* 23. 08. 22 */
#include <bits/stdc++.h>

using namespace std;

int T, N, M, a, b;
vector<vector<int>> adj;
deque<bool> visited;

int dfs(int here)
{
	int ret = 1;

	visited[here] = true;

	for (int there : adj[here]) {
		if (visited[there]) { continue; }

		ret += dfs(there);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T ;

	while (T--) {
		cin >> N >> M;
		vector<vector<int>>(N + 1, vector<int>()).swap(adj);

		for (int i{ 0 }; i < M; ++i) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		deque<bool>(N + 1, false).swap(visited);

		if (M == N - 1 && dfs(a) == N) { cout << "tree" << '\n'; }
		else { cout << "graph" << '\n'; }
	}

	return 0;
}