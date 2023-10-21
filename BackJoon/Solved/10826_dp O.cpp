/* 23. 10. 21 */
/* 피보나치 수 IV */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> dp;

string StrSum(string strA, string strB)
{
	string ret{ "" };
	int carry{ 0 };

	reverse(begin(strA), end(strA));
	reverse(begin(strB), end(strB));

	while (strA.size() > strB.size()) { strB.push_back('0'); }
	while (strB.size() > strA.size()) { strA.push_back('0'); }

	for (size_t i{ 0 }, num; i < strA.size(); ++i) {
		num = strA[i] - '0' + strB[i] - '0' + carry;
		ret += to_string(num % 10);
		carry = num / 10;
	}

	if (carry) { ret += to_string(carry); }

	reverse(begin(ret), end(ret));

	return ret;
}

int main()
{
	cin >> N;
	if (!N) {
		cout << 0;
		return 0;
	}
	dp.resize(N + 1);
	dp[0] = "0";
	dp[1] = "1";

	for (int i{ 2 }; i <= N; ++i) {
		dp[i] = StrSum(dp[i - 2], dp[i - 1]);
	}

	cout << dp[N];

	return 0;
}