/* 23. 11. 08 */
/* 타일링 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_N{ 250 };
int N;
vector<string> dp(MAX_N + 1);

string NumString_ADD(string strA, string strB)
{
	reverse(begin(strA), end(strA));
	reverse(begin(strB), end(strB));

	while (strA.size() > strB.size()) { strB.push_back('0'); }
	while (strB.size() > strA.size()) { strA.push_back('0'); }

	string ret{ "" };
	string::size_type len{ strA.size() };
	int carry{ 0 };

	for (string::size_type i{ 0 }; i < len; ++i) {
		int num{ strA[i] - '0' + strB[i] - '0' + carry };
		ret += to_string(num % 10);
		carry = num / 10;
	}
	if (carry) { ret += to_string(carry); }

	reverse(begin(ret), end(ret));

	return ret;
}

int main()
{
	dp[0] = dp[1] = "1";
	dp[2] = "3";
	for (int i{ 3 }; i <= MAX_N; ++i) {
		dp[i] = NumString_ADD(NumString_ADD(dp[i - 1], dp[i - 2]), dp[i - 2]);
	}

	while (true) {
		cin >> N;
		if (cin.eof()) { break; }
		cout << dp[N] << '\n';
	}

	return 0;
}