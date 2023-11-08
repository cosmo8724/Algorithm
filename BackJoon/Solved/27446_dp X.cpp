/* 23. 11. 08 */
/* 랩실에서 잘 자요 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int N, M;
vector<int> pages, needprint;
vector<vector<int>> dp;

int Go(int from, int to)
{
	if (from == needprint.size()) { return 0; }
	if (from == to) { return 5 + 2; }

	int& ret{ dp[from][to] };
	if (ret != INF) { return ret; }

	ret = 5 + 2 * (needprint[to] - needprint[from] + 1);
	ret = min(ret, Go(from + 1, to) + 5 + 2);
	ret = min(ret, Go(from, to - 1) + 5 + 2);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	pages.resize(M);

	for (int i{ 0 }; i < M; ++i) { cin >> pages[i]; }

	sort(begin(pages), end(pages));
	for (int i{ 1 }; i <= N; ++i) {
		if (!binary_search(begin(pages), end(pages), i)) {
			needprint.push_back(i);
		}
	}

	vector<vector<int>>(needprint.size(), vector<int>(needprint.size(), INF)).swap(dp);
	cout << Go(0, needprint.size() - 1);

	return 0;
}