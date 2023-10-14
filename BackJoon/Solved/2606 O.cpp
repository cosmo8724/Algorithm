/* 23. 08. 14 */
#include <bits/stdc++.h>

using namespace std;

int N, K, a, b;
vector<vector<int>> adj;
vector<bool> visited;

int dfs(int num)
{
	int ret = 1;
	visited[num] = true;

	for (int i : adj[num]) {
		if (visited[i]) { continue; }
		ret += dfs(i);
	}

	return ret;
}

int main()
{
	cin >> N >> K;
	adj.resize(N);
	visited.resize(N);

	while (K--) {
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}

	cout << dfs(0) - 1;

	return 0;
}