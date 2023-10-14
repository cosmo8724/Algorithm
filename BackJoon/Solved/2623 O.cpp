/* 23. 09. 22 */
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> Entry;
vector<vector<int>> After;

vector<int> bfs()
{
	queue<int> q;
	for (int i{ 1 }; i <= N; ++i) {
		if (Entry[i] == 0) { q.push(i); }
	}

	vector<int> ret;
	while (!q.empty()) {
		int here{ q.front() };
		q.pop();
		ret.push_back(here);

		for (int i{ 0 }; i < After[here].size(); ++i) {
			int next{ After[here][i] };
			--Entry[next];

			if (!Entry[next]) { q.push(next); }
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	Entry.resize(N + 1);
	After.resize(N + 1);

	for (int i{ 0 }; i < M; ++i) {
		int cnt;
		cin >> cnt;
		vector<int> v(cnt);

		for (int j{ 0 }; j < cnt; ++j) { cin >> v[j]; }
		for (int j{ 0 }; j < cnt; ++j) {
			for (int k{ j + 1 }; k < cnt; ++k) {
				After[v[j]].push_back(v[k]);
				++Entry[v[k]];
			}
		}
	}

	vector<int> ret{ bfs() };
	if (ret.size() != N) { cout << 0; }
	else {
		for (int i : ret) {
			cout << i << '\n';
		}
	}

	return 0;
}