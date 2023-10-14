/* 23. 09. 18 */
#include <bits/stdc++.h>

using namespace std;

int n, money, c, cost;
double m;
vector<int> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true) {
		cin >> n >> m;
		if (n == 0) { break; }
		money = static_cast<int>((m + numeric_limits<double>::epsilon()) * 100);
		vector<int>(money + 1).swap(dp);

		for (int i{ 0 }; i < n; ++i) {
			cin >> c >> m;
			cost = static_cast<int>((m + numeric_limits<double>::epsilon()) * 100);

			for (int j{ cost }; j <= money; ++j) {
				dp[j] = max(dp[j], dp[j - cost] + c);
			}
		}

		cout << dp[money] << '\n';
	}

	return 0;
}