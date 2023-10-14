/* 23. 08. 12 */
#include <bits/stdc++.h>

using namespace std;

int N, K, ret;
const int MAX = 200'001;
vector<function<int(int)>> dir{		/* �켱������ *2, --, ++ ���̹Ƿ� �Լ��� �׿� �°� */
	[](int num) { return num * 2; },
	[](int num) { return --num; },
	[](int num) { return ++num; }
};

int bfs(int start, int goal)
{
	vector<int> visited(MAX, 0);
	visited[start] = 1;

	deque<int> deq;
	deq.push_front(start);

	while (deq.size()) {
		int cur = deq.front();
		deq.pop_front();

		if (cur == goal) {
			break;
		}

		for (int i = 0; i < 3; i++) {
			int next = dir[i](cur);

			if (next < 0 || MAX <= next || visited[next]) { continue; }

			if (i != 0) {
				deq.push_back(next);
				visited[next] = visited[cur] + 1;
			}
			else {
				deq.push_front(next);
				visited[next] = visited[cur];
			}
		}
	}

	return visited[goal] - 1;
}

int main()
{
	cin >> N >> K;

	if (N == K) {
		cout << 0;
	}
	else {
		cout << bfs(N, K);
	}

	return 0;
}