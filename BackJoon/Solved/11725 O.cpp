/* 23. 09. 13 */
#include <bits/stdc++.h>

using namespace std;

int N, from, to;
vector<vector<int>> v;
deque<bool> visited;
vector<int> ret;

void dfs(int here)
{
	visited[here] = true;

	for (int next : v[here]) {
		if (visited[next]) { continue; }
		ret[next] = here;
		dfs(next);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v.resize(N + 1);
	ret.resize(N + 1);
	visited.resize(N + 1);
	for (int i{ 0 }; i < N - 1; ++i) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	dfs(1);

	for (int i{ 2 }; i <= N; ++i) { cout << ret[i] << '\n'; }

	return 0;
}