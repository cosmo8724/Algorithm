/* 23. 09. 04 */
#include <bits/stdc++.h>

using namespace std;

int T, K, n, dir, ret;
deque<string> dq;
deque<bool> visited;

void Rotate(int _n, int _dir)
{
	visited[_n] = true;
	if (_n != T - 1 && !visited[_n + 1] && dq[_n][2] != dq[_n + 1][6]) { Rotate(_n + 1, _dir * -1); }
	if (_n != 0 && !visited[_n - 1] && dq[_n][6] != dq[_n - 1][2]) { Rotate(_n - 1, _dir * -1); }

	if (_dir == 1) {
		char tmp = dq[_n].back();
		shift_right(begin(dq[_n]), end(dq[_n]), 1);
		dq[_n].front() = tmp;
	}
	else {
		char tmp = dq[_n].front();
		shift_left(begin(dq[_n]), end(dq[_n]), 1);
		dq[_n].back() = tmp;
	}
}

int main()
{
	cin >> T;
	deque<string>(T).swap(dq);
	visited.resize(T);
	
	for (int i{ 0 }; i < T; ++i) { cin >> dq[i]; }

	cin >> K;
	while (K--) {
		cin >> n >> dir;
		Rotate(--n, dir);
		deque<bool>(T).swap(visited);
	}

	for (auto& mydq : dq) {
		if (mydq[0] == '1') { ++ret; }
	}

	cout << ret;

	return 0;
}