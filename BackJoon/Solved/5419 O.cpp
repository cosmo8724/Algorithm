/* 23. 10. 05 */
#include <bits/stdc++.h>

using namespace std;

int TC, N;
long long ret;
vector<pair<int, int>> islands;
vector<int> ypos, tree;

long long Sum(int idx)
{
	long long _ret{ 0 };
	while (idx > 0) {
		_ret += tree[idx];
		idx -= idx & -idx;
	}
	return _ret;
}

void Update(int idx, int value)
{
	while (idx <= N) {
		tree[idx] += value;
		idx += idx & -idx;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> TC;
	while (TC--) {
		cin >> N;
		vector<int>(N).swap(ypos);
		vector<int>(N + 1).swap(tree);
		vector<pair<int, int>>(N).swap(islands);

		for (int i{ 0 }; i < N; ++i) {
			cin >> islands[i].first >> islands[i].second;
			islands[i].second *= -1;
			ypos[i] = islands[i].second;
		}

		sort(begin(islands), end(islands));
		sort(begin(ypos), end(ypos));

		ret = 0;
		Update(distance(cbegin(ypos), lower_bound(cbegin(ypos), cend(ypos), islands[0].second)) + 1, 1);
		
		for (int i{ 1 }, idx; i < N; ++i) {
			idx = distance(cbegin(ypos), lower_bound(cbegin(ypos), cend(ypos), islands[i].second)) + 1;
			ret += Sum(idx);
			Update(idx, 1);
		}

		cout << ret << '\n';
	}

	return 0;
}