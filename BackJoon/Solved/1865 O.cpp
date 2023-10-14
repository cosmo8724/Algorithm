/* 23. 09. 11 */
#include <bits/stdc++.h>

using namespace std;

const int START = 1;
int TC, N, M, W, S, E, T;
vector<tuple<int, int, int>> path;
vector<int> dist;

bool Go()
{
	for (int i{ 1 }; i <= N; ++i) {
		for (const auto& [s, e, t] : path) {
			if (dist[e] > dist[s] + t) {
				if (i == N) { return true; }
				dist[e] = dist[s] + t;
			}
		}
	}
	return false;
}

int main()
{
	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;
		vector<tuple<int, int, int>>().swap(path);
		vector<int>(N + 1, 987654321).swap(dist);
		for (int i{ 0 }; i < M; ++i) {
			cin >> S >> E >> T;
			path.push_back(make_tuple(S, E, T));
			path.push_back(make_tuple(E, S, T));
		}
		for (int i{ 0 }; i < W; ++i) {
			cin >> S >> E >> T;
			path.push_back(make_tuple(S, E, -T));
		}

		dist[1] = 0;
		if (Go()) { cout << "YES\n"; }
		else { cout << "NO\n"; }
	}

	return 0;
}