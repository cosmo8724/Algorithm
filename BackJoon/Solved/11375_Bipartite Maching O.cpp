/* 23. 09. 19 */
#include <bits/stdc++.h>

using namespace std;

int N, M, ret;
vector<int> employee, work;
vector<vector<int>> adj;
deque<bool> visited;

bool dfs(const int here)
{
	visited[here] = true;

	for (const int there : adj[here]) {
		if (work[there] == -1 || (!visited[work[there]] && dfs(work[there]))) {
			employee[here] = there;
			work[there] = here;
			return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<int>(N, -1).swap(employee);
	vector<int>(M, -1).swap(work);
	adj.resize(N);
	
	for (int i{ 0 }; i < N; ++i) {
		int _size;
		cin >> _size;
		adj[i].resize(_size);
		for (int j{ 0 }; j < _size; ++j) {
			cin >> adj[i][j];
			--adj[i][j];
		}
	}

	for (int i{ 0 }; i < N; ++i) {
		if (employee[i] == -1) {
			deque<bool>(N).swap(visited);
			if (dfs(i)) { ++ret; }
		}
	}

	cout << ret;

	return 0;
}