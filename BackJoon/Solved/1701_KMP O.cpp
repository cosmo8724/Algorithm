/* 23. 10. 19 */
#include <bits/stdc++.h>

using namespace std;

int ret;
string T;
string::size_type lenT;
vector<int> FailTable;

vector<int> Fail(string_view sv)
{
	string_view::size_type len{ sv.size() };
	vector<int> table(len);

	for (int i{ 1 }, j{ 0 }; i < len; ++i) {
		while (j > 0 && sv[i] != sv[j]) { j = table[j - 1]; }
		if (sv[i] == sv[j]) { table[i] = ++j; }
	}

	return table;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	lenT = T.size();
	for (int i{ 0 }; i < lenT; ++i) {
		FailTable = Fail(T.substr(i, lenT - i));
		ret = max(ret, *max_element(begin(FailTable), end(FailTable)));
	}

	cout << ret;

	return 0;
}