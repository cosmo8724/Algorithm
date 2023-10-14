/* 23. 10. 02 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_STAT{ 1001 }, MAX_QUEST{ 50 };
int N;
vector<vector<int>> dp(MAX_STAT, vector<int>(MAX_STAT, -1));
vector<pair<pair<int, int>, int>> quests;
deque<bool> visited(MAX_QUEST);

int Go(int str, int intel)
{
	int& ret{ dp[str][intel] };
	if (~ret) { return ret; }

	vector<int> visit_this_turn;
	int point_this_turn{ 0 };
	ret = 0;

	for (int i{ 0 }; i < N; ++i) {
		auto [require, reward] { quests[i] };
		auto [req_str, req_int] { require };

		if (req_str <= str || req_int <= intel) {
			++ret;

			if (!visited[i]) {
				visited[i] = true;
				visit_this_turn.push_back(i);
				point_this_turn += reward;
			}
		}
	}

	for (int i{ 0 }, next_str, next_intel; i <= point_this_turn; ++i) {
		next_str = clamp(str + i, 1, 1000);
		next_intel = clamp(intel + point_this_turn - i, 1, 1000);

		ret = max(ret, Go(next_str, next_intel));
	}

	for (int quest : visit_this_turn) { visited[quest] = false; }

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	quests.resize(N);
	for (int i{ 0 }; i < N; ++i) {
		cin >> quests[i].first.first >> quests[i].first.second >> quests[i].second;
	}

	sort(begin(quests), end(quests));
	cout << Go(1, 1);

	return 0;
}