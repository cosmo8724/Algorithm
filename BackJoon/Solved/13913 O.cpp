/* 23. 08. 12 */
#include <bits/stdc++.h>

using namespace std;

int N, K, ret;
const int MAX = 200'001;
vector<int> visited(MAX, 0);
vector<function<int(int)>> dir{
	[](int num) { return --num; },
	[](int num) { return ++num; },
	[](int num) { return num * 2; }
};

vector<int> bfs(int start, int goal)
{
	vector<int> previdx(MAX, 0);
	visited[start] = 1;

	queue<int> q;
	q.push(start);

	while (q.size()) {
		int cur = q.front();
		q.pop();

		if (cur == K) {
			ret = visited[K];
			break;
		}

		for (int i = 0; i < 3; i++) {
			int next = dir[i](cur);

			if (next < 0 || MAX <= next || visited[next]) { continue; }

			previdx[next] = cur;
			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}

	vector<int> ret;
	for (int i = K; i != N; i = previdx[i]) {
		ret.push_back(i);
	}
	ret.push_back(N);

	return ret;
}

int main()
{
	cin >> N >> K;

	vector<int> ret = bfs(N, K);

	reverse(ret.begin(), ret.end());

	cout << visited[K] - 1 << '\n';
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << ' ';
	}

	return 0;
}