/* 23. 09. 20 */
#include <bits/stdc++.h>

using namespace std;
using vvst = vector<vector<stack<int>>>;

const int RED{ 1 }, BLUE{ 2 };

int dy[]{ 0, 0, -1, 1 };
int dx[]{ 1, -1, 0, 0 };
int N, K, ret{ 1 };
vector<vector<int>> board;
vvst states;
vector<pair<pair<int, int>, int>> piece;

bool IsInBoard(int y, int x)
{
	if (y >= 0 && x >= 0 && y < N && x < N) { return true; }
	return false;
}

bool Move(int idx)
{
	auto& [cy, cx] { piece[idx].first };
	int& dir{ piece[idx].second };

	int ny{ cy + dy[dir] };
	int nx{ cx + dx[dir] };
	if (!IsInBoard(ny, nx) || board[ny][nx] == BLUE) {
		dir ^= 1;
		ny = cy + dy[dir];
		nx = cx + dx[dir];

		if (IsInBoard(ny, nx) && board[ny][nx] != BLUE) { return Move(idx); }
	}
	else if (board[ny][nx] == RED) {
		stack<int>& curState{ states[cy][cx] };
		stack<int>& moveState{ states[ny][nx] };
		if (curState.top() == idx) {
			curState.pop();
			states[ny][nx].push(idx);
		}
		else {
			queue<int> q;
			while (!curState.empty() && curState.top() != idx) {
				piece[curState.top()].first = make_pair(ny, nx);
				q.push(curState.top());
				curState.pop();
			}
			q.push(curState.top());
			curState.pop();
			
			while (!q.empty()) {
				moveState.push(q.front());
				q.pop();
			}
		}
		cy = ny;
		cx = nx;
		if (moveState.size() >= 4) { return true; }
	}
	else {
		stack<int>& curState{ states[cy][cx] };
		stack<int>& moveState{ states[ny][nx] };
		if (curState.top() == idx) {
			curState.pop();
			states[ny][nx].push(idx);
		}
		else {
			stack<int> st;
			while (!curState.empty() && curState.top() != idx) {
				st.push(curState.top());
				curState.pop();
				piece[st.top()].first = make_pair(ny, nx);
			}
			st.push(curState.top());
			curState.pop();

			while (!st.empty()) {
				moveState.push(st.top());
				st.pop();
			}
		}
		cy = ny;
		cx = nx;
		if (moveState.size() >= 4) { return true; }
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	vector<vector<int>>(N, vector<int>(N)).swap(board);
	vvst(N, vector<stack<int>>(N)).swap(states);
	piece.resize(K);
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			cin >> board[i][j];
		}
	}
	for (int i{ 0 }; i < K; ++i) {
		cin >> piece[i].first.first >> piece[i].first.second >> piece[i].second;
		--piece[i].first.first;
		--piece[i].first.second;
		--piece[i].second;

		states[piece[i].first.first][piece[i].first.second].push(i);
	}


	while (true) {
		bool flag{ false };
		for (int i{ 0 }; i < K; ++i) {
			if (Move(i)) { flag = true;  break; }
		}
		if (flag) { break; }
		++ret;
		if (ret >= 1000) { ret = -1; break; }
	}

	cout << ret;

	return 0;
}