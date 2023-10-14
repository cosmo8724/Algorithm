/* 23. 09. 28 */
#include <bits/stdc++.h>

using namespace std;

int TC, N, M, current;
//vector<int> tree;
int tree[200'004];
map<int, int> mp;

void Update(int tree_size, int idx)
{
	while (idx < tree_size) {
		++tree[idx];
		idx += (idx & -idx);
	}
}

int Sum(int min_idx, int idx)
{
	int ret{ 0 };
	while (idx >= min_idx) {
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> TC;
	while (TC--) {
		cin >> N >> M;
		const int tree_size{ N * 2 + 1 };
		//vector<int>(tree_size).swap(tree);
		memset(tree, 0, sizeof(tree));
		map<int, int>().swap(mp);

		for (int i{ N + 1 }; i < tree_size; ++i) {
			Update(tree_size, i);
			mp[i - N] = i;
		}
		while (M--) {
			cin >> current;
			cout << Sum(N--, mp[current]) - 1 << ' ';
			Update(mp[current] - 1, N);
			mp[current] = N;
		}

		cout << '\n';
	}

	return 0;
}