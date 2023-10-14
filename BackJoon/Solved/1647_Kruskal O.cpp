/* 23. 09. 19 */
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> parent;
vector<pair<int, pair<int, int>>> edge;

int find(int idx)
{
	if (idx == parent[idx]) { return idx; }
	else { return parent[idx] = find(parent[idx]); }
}

void uni(int idxA, int idxB)
{
	idxA = find(idxA);
	idxB = find(idxB);
	parent[idxB] = idxA;
}

bool IsSameParent(int idxA, int idxB)
{
	return find(idxA) == find(idxB);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	parent.resize(N + 1);
	edge.resize(M);
	for (int i{ 1 }; i <= N; ++i) { parent[i] = i; }
	for (int i{ 0 }; i < M; ++i) {
		cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
		--edge[i].second.first;
		--edge[i].second.second;
	}
	sort(begin(edge), end(edge));

	int result{ 0 }, maxCost{ 0 };
	for (int i{ 0 }; i < M; ++i) {
		auto [cost, vtx] {edge[i]};
		auto [from, to] {vtx};
		if (!IsSameParent(from, to)) {
			maxCost = max(maxCost, cost);
			result += cost;
			uni(from, to);
		}
	}

	cout << result - maxCost;

	return 0;
}