/* 23. 10. 18 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
int N, TC;
vector<vector<int>> board, costs;
deque<deque<bool>> visited;

void PrintAnswer(int testcase, int answer)
{
	cout << "Problem " << testcase << ": " << answer << '\n';
}

void Dijk(int stY, int stX)
{
	costs[stY][stX] = board[stY][stX];
	visited[stY][stX] = true;

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.push(make_tuple(costs[stY][stX], stY, stX));

	while (!pq.empty()) {
		auto [cost, cy, cx] { pq.top() };
		pq.pop();

		if (cost > costs[cy][cx]) { continue; }

		for (int dir{ 0 }, nextcost, ny, nx; dir < 4; ++dir) {
			ny = cy + dy[dir];
			nx = cx + dx[dir];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) { continue; }
			if (visited[ny][nx]) { continue; }

			nextcost = board[ny][nx];
			nextcost += cost;

			if (costs[ny][nx] > nextcost) {
				costs[ny][nx] = nextcost;
				pq.push(make_tuple(nextcost, ny, nx));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true)
	{
		cin >> N;
		if (!N) { break; }
		vector<vector<int>>(N, vector<int>(N)).swap(board);
		vector<vector<int>>(N, vector<int>(N, INF)).swap(costs);
		deque<deque<bool>>(N, deque<bool>(N)).swap(visited);

		for (int i{ 0 }; i < N; ++i) {
			for (int j{ 0 }; j < N; ++j) {
				cin >> board[i][j];
			}
		}

		Dijk(0, 0);
		PrintAnswer(++TC, costs[N - 1][N - 1]);
	}

	return 0;
}