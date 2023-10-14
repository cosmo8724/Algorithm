/* 23. 08. 12 */
#include <bits/stdc++.h>

using namespace std;

int N, K;
const int MAX = 100'001;
vector<function<int(int)>> dir{
	[](int num) { return --num; },
	[](int num) { return ++num; },
	[](int num) { return num * 2; }
};

pair<int, int> bfs(int start, int goal)
{
	vector<int> cnt(MAX, 0);
	cnt[start] = 1;

	vector<int> visited(MAX, 0);
	visited[start] = 1;

	queue<int> q;
	q.push(start);

	while (q.size()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int next = dir[i](cur);

			if (next < 0 || MAX <= next) { continue; }
			if (visited[next] == 0) {
				cnt[next] += cnt[cur];
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
			else if (visited[next] == visited[cur] + 1) { cnt[next] += cnt[cur]; }
		}
	}

	return make_pair(visited[K] - 1, cnt[K]);
}

int main()
{
	cin >> N >> K;

	auto [minTime, minCnt] = bfs(N, K);
	cout << minTime << '\n' << minCnt;

	return 0;
}