/* 23. 08. 08 */
#include <bits/stdc++.h>

using namespace std;

int N, C;
vector<pair<int, long long>> v;
map<long long, int> cnt, idx;

int main()
{
	cin >> N >> C;
	
	for (int i = 1; i <= N; i++) {
		long long elem;
		cin >> elem;

		if (idx[elem] == 0) {
			idx[elem] = i;
		}
		cnt[elem]++;
	}

	for (auto& mypair : cnt) {
		v.push_back({ mypair.second, mypair.first });
	}

	sort(v.begin(), v.end(), [&](const pair<int, long long>& X, const pair<int, long long>& Y) {
		if (X.first == Y.first) {
			return idx[X.second] < idx[Y.second];
		}
		return X.first > Y.first;
	});

	for (auto& mypair : v) {
		for (int i = 0; i < mypair.first; i++) {
			cout << format("{} ", mypair.second);
		}
	}
}