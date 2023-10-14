/* 23. 08. 10 */
#include <bits/stdc++.h>

using namespace std;

int N, elem, root, blocked, ret;
vector<int> adj[51];

void ReafCount(int here)
{
	if (here == blocked) {
		return;
	}

	int size = adj[here].size();
	int cnt = 0;

	for (int i = 0; i < size; i++) {
		if (adj[here][i] != blocked) {
			ReafCount(adj[here][i]);
			cnt++;
		}
	}

	if (cnt == 0) {
		ret++;
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> elem;

		if (elem == -1) {
			root = i;
		}
		else {
			adj[elem].push_back(i);
		}
	}

	cin >> blocked;

	ReafCount(root);
	
	cout << ret;

	return 0;
}