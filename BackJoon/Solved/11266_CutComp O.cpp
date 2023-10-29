/* 23. 10. 29 */
/* 단절점 */
/** 단절점 조건
* 정점 A보다 늦게 탐색 되는 정점들에서 정점 A보다 먼저 탐색 되는 정점으로 가는 경로가 없는 경우 정점 A는 단절점이다.
* 루트 노드로 잡은 특정 노드의 자식 수가 2개 이상이면 단절점이다.
*/
#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;
vector<int> visited, cutcomponent;

int dfs(int here, int cnt, bool is_root)
{
	visited[here] = cnt;
	int ret{ visited[here] };
	int child{ 0 };

	for (int next : adj[here]) {
		if (visited[next]) {
			ret = min(ret, visited[next]);
			continue;
		}

		++child;
		int is_directed{ dfs(next, cnt + 1, false) };
		if (!is_root && is_directed >= visited[here]) { cutcomponent.push_back(here); }
		ret = min(ret, is_directed);
	}
	
	if (is_root && child > 1) { cutcomponent.push_back(here); }
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E;
	adj.resize(V + 1);
	visited.resize(V + 1);
	for (int i{ 0 }, from, to; i < E; ++i) {
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	for (int i{ 1 }; i <= V; ++i) {
		if (!visited[i]) {
			dfs(i, 1, true);
		}
	}

	sort(begin(cutcomponent), end(cutcomponent));
	cutcomponent.erase(unique(begin(cutcomponent), end(cutcomponent)), end(cutcomponent));

	cout << cutcomponent.size() << '\n';
	for (int i : cutcomponent) { cout << i << ' '; }

	return 0;
}