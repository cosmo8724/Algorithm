/* 23. 09. 15 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_N{ 1'000'001 };
int N;
vector<int> v, score(MAX_N), card(MAX_N);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> v[i]; ++card[v[i]]; }

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ v[i] * 2 }; j < MAX_N; j += v[i]) {
			if (card[j]) {
				++score[v[i]];
				--score[j];
			}
		}
	}

	for (int i{ 0 }; i < N; ++i) { cout << score[v[i]] << ' '; }

	return 0;
}