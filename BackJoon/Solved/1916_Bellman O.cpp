/* 23. 09. 13 */
#include <bits/stdc++.h>

using namespace std;

int N, M, st, ed;
vector<tuple<int, int, int>> buses;
vector<int> costs;

void Go()
{
	for (int i{ 1 }; i <= N; ++i) {
		for (int j{ 0 }; j < buses.size(); ++j) {
			auto& [from, to, cost] { buses[j] };
			if (costs[to] > costs[from] + cost) {
				costs[to] = costs[from] + cost;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<int>(N, 1e9).swap(costs);
	int from, to, cost;
	for (int i{ 0 }; i < M; ++i) {
		cin >> from >> to >> cost;
		buses.push_back(make_tuple(--from, --to, cost));
	}
	cin >> st >> ed;

	costs[--st] = 0;
	Go();

	cout << costs[--ed];

	return 0;
}