/* 23. 08. 14 */
#include <bits/stdc++.h>

using namespace std;

int K;
vector<int> v;
vector<int> ret[11];
map<int, int> mp;

void go(int s, int e, int level)
{
	if (s > e) { return; }
	else if (s == e) {
		ret[level].push_back(v[s]);
		return;
	}
	else {
		int mid = (s + e) >> 1;

		ret[level].push_back(v[mid]);
		go(s, mid - 1, level + 1);
		go(mid + 1, e, level + 1);

		return;
	}
}

int main()
{
	cin >> K;
	v.resize(static_cast<int>(pow(2, K)) - 1);
	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}

	go(0, v.size() - 1, 1);

	for (int i = 1; i <= K; i++) {
		for (int j : ret[i]) {
			cout << j << ' ';
		}
		cout << '\n';
	}

	return 0;
}