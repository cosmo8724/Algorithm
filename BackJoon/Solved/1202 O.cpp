/* 23. 08. 31 */
#include <bits/stdc++.h>

using namespace std;

int N, K;
long long ret;
vector<pair<int, int>> jewel;
vector<int> bags;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	jewel.resize(N);
	bags.resize(K);
	for (int i{ 0 }; i < N; ++i) { cin >> jewel[i].first >> jewel[i].second; }
	for (int i{ 0 }; i < K; ++i) { cin >> bags[i]; }

	sort(begin(jewel), end(jewel));
	sort(begin(bags), end(bags));

	priority_queue<int, vector<int>, less<int>> pq;
	int curJewel = 0;
	for (int i{ 0 }; i < K; ++i) {
		while (curJewel < N && jewel[curJewel].first <= bags[i]) {
			pq.push(jewel[curJewel++].second);
		}
		if (pq.size()) {
			ret += pq.top();
			pq.pop();
		}
	}

	cout << ret;

	return 0;
}