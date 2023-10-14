/* 23. 09. 01 */
#include <bits/stdc++.h>

using namespace std;

int N, ret;
vector<pair<int, int>> problem;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin >> N;
	problem.resize(N);

	for (int i{ 0 }; i < N; ++i) { cin >> problem[i].first >> problem[i].second; }

	sort(begin(problem), end(problem), [](const auto& pairA, const auto& pairB) {
		if (pairA.first == pairB.first) { return pairA.second > pairB.second; }
		return pairA.first < pairB.first;
		});

	for (const auto& [deadline, reward] : problem) {
		pq.push(reward);

		if (pq.size() > deadline) { pq.pop(); }
	}

	while (pq.size()) {
		ret += pq.top();
		pq.pop();
	}

	cout << ret;

	return 0;
}