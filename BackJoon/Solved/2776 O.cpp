/* 23. 09. 08 */
#include <bits/stdc++.h>

using namespace std;

int T, N, M;
vector<int> noteA, noteB;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--) {
		cin >> N;
		noteA.resize(N);
		for (int i{ 0 }; i < N; ++i) { cin >> noteA[i]; }
		sort(begin(noteA), end(noteA));

		cin >> M;
		noteB.resize(M);
		for (int i{ 0 }; i < M; ++i) {
			cin >> noteB[i];
			cout << binary_search(begin(noteA), end(noteA), noteB[i]) << '\n';
		}
	}

	return 0;
}