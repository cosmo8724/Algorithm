/* 23. 10. 03 */
#include <bits/stdc++.h>

using namespace std;

int N, M, K, ret;
vector<int> candies, parent;
vector<vector<int>> friends, dp;

int Find(int idx)
{
	if (idx == parent[idx]) { return idx; }
	else { return parent[idx] = Find(parent[idx]); }
}

void Uni(int idxA, int idxB)
{
	idxA = Find(idxA);
	idxB = Find(idxB);
	if (idxA <= idxB) { parent[idxB] = idxA; }
	else { parent[idxA] = idxB; }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	candies.resize(N);
	parent.resize(N);
	friends.resize(N);
	vector<vector<int>>(N + 1, vector<int>(K + 1)).swap(dp);
	for (int i{ 0 }; i < N; ++i) { cin >> candies[i]; }
	for (int i{ 0 }; i < N; ++i) { parent[i] = i; }
	for (int i{ 0 }; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		Uni(--a, --b);
	}

	vector<int> friend_head;
	for (int i{ 0 }, p; i < N; ++i) {
		p = Find(i);
		friends[p].push_back(i);
		friend_head.push_back(p);
	}
	sort(begin(friend_head), end(friend_head));
	friend_head.erase(unique(begin(friend_head), end(friend_head)), end(friend_head));

	for (int i{ 0 }; i < friend_head.size(); ++i) {
		int cur_head{ friend_head[i] };
		int cnt{ static_cast<int>(friends[cur_head].size()) };
		int sum{ 0 };
		for_each(begin(friends[cur_head]), end(friends[cur_head]), [&](const int child_idx) {
			sum += candies[child_idx];
		});

		for (int j{ K - 1 }; j >= 0; --j) {
			if (j - cnt >= 0) { dp[i + 1][j] = max(dp[i][j], dp[i][j - cnt] + sum); }
			else { dp[i + 1][j] = dp[i][j]; }
			ret = max(ret, dp[i + 1][j]);
		}
	}

	cout << ret;

	return 0;
}