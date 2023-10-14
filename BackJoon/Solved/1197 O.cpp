/* 23. 09. 14 */
#include <bits/stdc++.h>

using namespace std;

int V, E, st, ed, co, ret;
vector<int> parent;
multimap<int, pair<int, int>> edges;

int find(int idx)
{
	if (parent[idx] == idx) { return idx; }
	return parent[idx] = find(parent[idx]);
}

void uni(int idx_base, int idx_derived)
{
	idx_base = find(idx_base);
	idx_derived = find(idx_derived);
	parent[idx_derived] = idx_base;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E;
	parent.resize(V);
	iota(begin(parent), end(parent), 0);

	while (E--) {
		cin >> st >> ed >> co;
		edges.emplace(co, make_pair(--st, --ed));
	}

	for (auto& [cost, vertices] : edges) {
		const auto& [from, to] { vertices };
		if (find(from) != find(to)) {
			uni(from, to);
			ret += cost;
		}
	}

	cout << ret;

	return 0;
}