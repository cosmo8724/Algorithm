/* 23. 08. 12 */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 500'001;
int N, K;
vector<function<int(int)>> dir{
	[](int num) { return ++num; },
	[](int num) { return --num; },
	[](int num) { return num * 2; }
};

int bfs(int start, int goal)
{
	if (start == goal) { return 0; }
	int turn = 1;

	vector<vector<int>> visited(2, vector<int>(MAX, 0));
	visited[0][start] = 1;

	queue<int> q;
	q.push(start);

	while (q.size()) {
		goal += turn;

		if (goal >= MAX) { return -1; }
		if (visited[turn % 2][goal]) { break; }

		int size = q.size();
		for (int i = 0; i < size; i++) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < 3; i++) {
				int next = dir[i](cur);

				if (next < 0 || next >= MAX || visited[turn % 2][next]) { continue; }

				visited[turn % 2][next] = visited[(turn + 1) % 2][cur] + 1;

				if (next == goal) { return turn; }
				q.push(next);
			}
		}
		turn++;
	}

	return turn;
}

int main()
{
	cin >> N >> K;

	cout << bfs(N, K);

	return 0;
}