/* 23. 10. 12 */
#include <bits/stdc++.h>

using namespace std;

int N, K, S;
vector<vector<int>> adj;

void Floyd()
{
	for (int mid{ 1 }; mid <= N; ++mid) {
		for (int before{ 1 }; before <= N; ++before) {
			for (int after{ 1 }; after <= N; ++after) {
				if (adj[before][mid] == 1 && adj[mid][after] == 1) { adj[before][after] = 1; }
				else if (adj[before][mid] == -1 && adj[mid][after] == -1) { adj[before][after] = -1; }
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	vector<vector<int>>(N + 1, vector<int>(N + 1)).swap(adj);
	for (int i{ 0 }, before, after; i < K; ++i) {
		cin >> before >> after;
		adj[before][after] = -1;
		adj[after][before] = 1;
	}

	Floyd();

	cin >> S;
	for (int i{ 0 }, before, after; i < S; ++i) {
		cin >> before >> after;
		cout << adj[before][after] << '\n';
	}

	return 0;
}