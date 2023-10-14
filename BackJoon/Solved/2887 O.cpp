/* 23. 09. 14 */
#include <bits/stdc++.h>

using namespace std;

int N, x, y, z, ret;
vector<pair<int, int>> edge_x, edge_y, edge_z;
vector<pair<int, pair<int, int>>> edges;
vector<int> parent;

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

	cin >> N;
	parent.resize(N);
	iota(begin(parent), end(parent), 0);

	for (int i{ 0 }; i < N; ++i) {
		cin >> x >> y >> z;
		edge_x.push_back(make_pair(x, i));
		edge_y.push_back(make_pair(y, i));
		edge_z.push_back(make_pair(z, i));
	}

	sort(begin(edge_x), end(edge_x));
	sort(begin(edge_y), end(edge_y));
	sort(begin(edge_z), end(edge_z));

	for (int i{ 0 }; i < N - 1; ++i) {
		edges.push_back(make_pair(edge_x[i + 1].first - edge_x[i].first, make_pair(edge_x[i].second, edge_x[i + 1].second)));
		edges.push_back(make_pair(edge_y[i + 1].first - edge_y[i].first, make_pair(edge_y[i].second, edge_y[i + 1].second)));
		edges.push_back(make_pair(edge_z[i + 1].first - edge_z[i].first, make_pair(edge_z[i].second, edge_z[i + 1].second)));
	}
	sort(begin(edges), end(edges));

	for (auto [cost, nodes] : edges) {
		auto [from, to] { nodes };
		if (find(from) != find(to)) {
			uni(from, to);
			ret += cost;
		}
	}

	cout << ret;

	return 0;
}