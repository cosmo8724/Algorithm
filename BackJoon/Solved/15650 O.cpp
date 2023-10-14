/* 23. 09. 13 */
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v, idx;

int main()
{
	cin >> N >> M;
	v.resize(N);
	idx.resize(N);
	iota(begin(v), end(v), 1);

	for (int i{ 0 }; i < M; ++i) { idx[i] = 1; }

	do {
		for (int i{ 0 }; i < N; ++i) {
			if (idx[i]) { cout << v[i] << ' '; }
		}
		cout << '\n';

	} while (prev_permutation(begin(idx), end(idx)));

	return 0;
}