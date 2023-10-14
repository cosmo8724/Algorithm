/* 23. 09.03 */
#include <bits/stdc++.h>

using namespace std;

int N, K, ret;
vector<int> v;
vector<int> multitab;
deque<bool> cnt;

int main()
{
	cin >> N >> K;
	v.resize(K + 1);
	cnt.resize(K + 1);

	for (int i{ 1 }; i <= K; ++i) { cin >> v[i]; }

	for (int i{ 1 }; i <= K; ++i) {
		if (!cnt[v[i]]) {
			if (multitab.size() == N) {
				int LastIdx = -1;
				for (int j{ 0 }; j < multitab.size(); ++j) {
					const auto iter = find(begin(v) + i + 1, end(v), multitab[j]);
					if (iter != end(v)) {
						LastIdx = max(LastIdx, static_cast<int>(iter - begin(v)));
					}
					else {
						++ret;
						cnt[multitab[j]] = false;
						multitab.erase(begin(multitab) + j);
						LastIdx = -1;
						break;
					}
				}

				if (LastIdx != -1) {
					++ret;
					cnt[v[LastIdx]] = false;
					multitab.erase(find(begin(multitab), end(multitab), v[LastIdx]));
				}
			}
			multitab.push_back(v[i]);
			cnt[v[i]] = true;
		}
	}

	cout << ret;

	return 0;
}