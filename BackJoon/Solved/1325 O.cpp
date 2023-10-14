/* 23. 08. 10 */
#include <bits/stdc++.h>

using namespace std;

int N, M, to, from, ret;
vector<vector<int>> net;
vector<bool> visited;

int dfs(int here)
{
	int cnt = 1;
	visited[here] = true;

	for (int there : net[here]) {
		if (!visited[there]) {
			cnt += dfs(there);
		}
	}

	return cnt;
}

int main()
{
	cin >> N >> M;
	vector<vector<int>>(N + 1, vector<int>()).swap(net);

	while (M--) {
		cin >> to >> from;
		net[from].push_back(to);
	}

	vector<int> maxidx;
	for (int i = 1; i <= N; i++) {
		vector<bool>(N + 1, false).swap(visited);
		int cnt = dfs(i);

		if (ret < cnt) {
			ret = cnt;
			maxidx.clear();
			maxidx.push_back(i);
		}
		else if (ret == cnt) {
			maxidx.push_back(i);
		}
	}

	for (int idx : maxidx) {
		cout << idx << ' ';
	}

	return 0;
}