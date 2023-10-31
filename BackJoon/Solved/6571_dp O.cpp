/* 23. 10. 31 */
/* 피보나치 수의 개수 */
#include <bits/stdc++.h>

using namespace std;

template<typename T>
concept String = is_convertible_v<T, string>;

constexpr string NumString_ADD(string strA, string strB)
{
	reverse(begin(strA), end(strA));
	reverse(begin(strB), end(strB));

	while (strA.size() > strB.size()) { strB.push_back('0'); }
	while (strB.size() > strA.size()) { strA.push_back('0'); }

	string::size_type len{ strA.size() };
	string ret{ "" };
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

template<typename T, size_t N> requires String<T>
constexpr vector<string> Make_DP()
{
	vector<string> ret(N + 1);
	ret[1] = "1";
	ret[2] = "2";

	for (size_t i{ 3 }; i <= N; ++i) {
		ret[i] = NumString_ADD(ret[i - 1], ret[i - 2]);
	}

	return ret;
}

bool NumString_LESS(string_view svA, string_view svB)
{
	if (svA.size() == svB.size()) { return svA < svB; }
	else { return svA.size() < svB.size(); }
}

/* Global Section */
const int MAX_N{ 1'000 };
string a, b;
vector<string> dp{ Make_DP<string, MAX_N>() };

/* Main */
int main()
{
	while (true) {
		cin >> a >> b;
		if (a == "0" && b == "0") { break; }

		const auto it_from{ upper_bound(begin(dp), end(dp), a, NumString_LESS) };
		const auto it_to{ upper_bound(begin(dp), end(dp), b, NumString_LESS) };

		cout << distance(it_from, it_to) << '\n';
	}

	return 0;
}