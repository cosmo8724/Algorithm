/* 23. 08. 16*/
#include <bits/stdc++.h>

using namespace std;

int N, a, b, cnt, ret = numeric_limits<int>::max();
vector<int> values;
vector<bool> visited;
vector<bool> team;
vector<vector<int>> adj;

int dfs(int here, bool value)
{
	int ret = values[here];
	visited[here] = true;
	cnt++;

	for (int there : adj[here]) {
		if (visited[there] || team[there] ^ value) { continue; }

		ret += dfs(there, value);
	}

	return ret;
}

int main()
{
	cin >> N;
	values.resize(N);
	visited.resize(N);
	team.resize(N);
	adj.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> values[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			adj[i].push_back(b - 1);
		}
	}

	for (int i = (1 << N) - 2; i > 0; i--) {
		vector<bool>(N, false).swap(visited);
		cnt = 0;

		int stF = -1, stT = -1;
		for (int j = 0; j < N; j++) {
			if (i & 1 << j) {
				stT = j;
				team[j] = true;
			}
			else {
				stF = j;
				team[j] = false;
			}
		}

		int sumT = dfs(stT, true);
		int sumF = dfs(stF, false);

		if (cnt != N) { continue; }
		
		ret = min(ret, abs(sumT - sumF));
	}

	if (ret == numeric_limits<int>::max()) { cout << -1; }
	else { cout << ret; }

	return 0;
}