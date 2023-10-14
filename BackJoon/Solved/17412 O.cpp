/* 23. 09. 18 */
#include <bits/stdc++.h>

using namespace std;

const int source{ 0 }, sink{ 1 };
int N, P;
vector<vector<int>> capacity, flow;
vector<int> parent;

int Max_Flow()
{
	int ret{ 0 };

	while (true) {
		vector<int>(N, -1).swap(parent);
		parent[source] = source;

		queue<int> q;
		q.push(source);

		while (!q.empty() && parent[sink] == -1) {
			int here{ q.front() };
			q.pop();

			for (int there{ 0 }; there < N; ++there) {
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					parent[there] = here;
					q.push(there);
				}
			}
		}

		if (parent[sink] == -1) { break; }

		int amount{ numeric_limits<int>::max() };
		for (int idx{ sink }; idx != source; idx = parent[idx]) {
			amount = min(amount, capacity[parent[idx]][idx] - flow[parent[idx]][idx]);
		}
		for (int idx{ sink }; idx != source; idx = parent[idx]) {
			flow[parent[idx]][idx] += amount;
			flow[idx][parent[idx]] -= amount;
		}

		ret += amount;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> P;

	vector<vector<int>>(N, vector<int>(N)).swap(capacity);
	vector<vector<int>>(N, vector<int>(N)).swap(flow);

	for (int i{ 0 }; i < P; ++i) {
		int from, to;
		cin >> from >> to;
		++capacity[--from][--to];
	}

	cout << Max_Flow();

	return 0;
}