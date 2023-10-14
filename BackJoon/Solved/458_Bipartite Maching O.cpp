/* 23. 09. 19 */
#include <bits/stdc++.h>

using namespace std;

int N, M, ret;
vector<int> cow, house;
vector<vector<int>> adj;
deque<bool> visited;

bool dfs(int from)
{
	visited[from] = true;
	for (int to : adj[from]) {
		if (house[to] == -1 || (!visited[house[to]] && dfs(house[to]))) {
			cow[from] = to;
			house[to] = from;
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
	vector<int>(N, -1).swap(cow);
	vector<int>(M, -1).swap(house);
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
		if (cow[i] == -1) {
			deque<bool>(N).swap(visited);
			if (dfs(i)) { ++ret; }
		}
	}

	cout << ret;

	return 0;
}