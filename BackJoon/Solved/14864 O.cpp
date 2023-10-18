/* 23. 10. 18 */
#include <bits/stdc++.h>

using namespace std;

bool IsInvalid;
int N, M;
vector<int> cards, visited;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	cards.resize(N + 1);
	visited.resize(N + 1);

	for (int i{ 0 }, X, Y; i < M; ++i) {
		cin >> X >> Y;
		++cards[X];
		--cards[Y];
	}
	for (int i{ 1 }; i <= N; ++i) {
		cards[i] += i;
		if (++visited[cards[i]] > 1) {
			IsInvalid = true;
			break;
		}
	}

	if (IsInvalid) { cout << -1; }
	else {
		for (int i{ 1 }; i <= N; ++i) {
			cout << cards[i] << ' ';
		}
	}

	return 0;
}