/* 23. 08. 12 */
#include <bits/stdc++.h>

using namespace std;

int N, K, ret;
const int MAX = 200'001;
vector<function<int(int)>> dir{
	[](int num) { return --num; },
	[](int num) { return ++num; },
	[](int num) { return num * 2; }
};

int bfs(int start, int goal)
{
	vector<int> visited(MAX, 0);
	visited[start] = 1;

	queue<int> q;
	q.push(start);

	while (q.size()) {
		int cur = q.front();
		q.pop();

		if (cur == K) {
			break;
		}

		for (int i = 0; i < 3; i++) {
			int next = dir[i](cur);

			if (next < 0 || MAX <= next || visited[next]) { continue; }

			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}

	return visited[K] - 1;
}

int main()
{
	cin >> N >> K;

	cout << bfs(N, K);

	return 0;
}