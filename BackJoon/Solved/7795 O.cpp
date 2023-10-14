/* 23. 09. 09 */
#include <bits/stdc++.h>

using namespace std;

int T, N, M;
vector<int> vA, vB;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		vA.resize(N);
		vB.resize(M);
		for (int i{ 0 }; i < N; ++i) { cin >> vA[i]; }
		for (int i{ 0 }; i < M; ++i) { cin >> vB[i]; }

		sort(begin(vA), end(vA));
		sort(begin(vB), end(vB));

		int cnt = 0;
		auto it = begin(vB);
		for (int elemA : vA) {
			it = lower_bound(it, end(vB), elemA);
			cnt += distance(begin(vB), it);
		}

		cout << cnt << '\n';
	}

	return 0;
}