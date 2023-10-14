/* 23. 09. 13 */
#include <bits/stdc++.h>

using namespace std;

long long A, B, ret{ -1 };
function<long long(long long)> dir[2]{
	[](long long n) { return 2 * n; },
	[](long long n) { return n * 10 + 1; }
};

void bfs()
{
	queue<pair<long long, long long>> q;
	q.push(make_pair(A, 1));

	while (!q.empty()) {
		auto [num, cnt] {q.front() };
		q.pop();

		if (num == B) {
			ret = cnt;
			break;
		}

		for (int i{ 0 }; i < 2; ++i) {
			long long next{ dir[i](num) };
			if (next > B) { continue; }
			q.push(make_pair(next, cnt + 1));
		}
	}
}

int main()
{
	cin >> A >> B;

	bfs();

	cout << ret;

	return 0;
}