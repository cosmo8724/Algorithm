/* 23. 09. 15 */
#include <bits/stdc++.h>

using namespace std;

size_t max_len;
string s;
deque<deque<bool>> IsPalindrome;
vector<int> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s;
	max_len = s.size();
	deque<deque<bool>>(max_len, deque<bool>(max_len)).swap(IsPalindrome);
	dp.resize(max_len + 1);

	for (int i{ 0 }; i < max_len; ++i) { IsPalindrome[i][i] = true; }
	for (int i{ 0 }; i < max_len - 1; ++i) {
		if (s[i] == s[i + 1]) { IsPalindrome[i][i + 1] = true; }
	}
	for (int len{ 3 }; len <= max_len; ++len) {
		for (int from{ 0 }; from <= max_len - len; ++from) {
			int to{ from + len - 1 };
			if (s[from] == s[to] && IsPalindrome[from + 1][to - 1]) { IsPalindrome[from][to] = true; }
		}
	}

	for (int to{ 1 }; to <= max_len; ++to) {
		dp[to] = static_cast<int>(1e9);

		for (int from{ 1 }; from <= to; ++from) {
			if (IsPalindrome[from - 1][to - 1]) {
				dp[to] = min(dp[to], dp[from - 1] + 1);
			}
		}
	}

	cout << dp[max_len];

	return 0;
}