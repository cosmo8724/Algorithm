/* 23. 10. 19 */
#include <bits/stdc++.h>

using namespace std;

string T, P;
string::size_type lenT, lenP;
vector<int> vecFail, answer;

vector<int> Fail(string_view sv)
{
	string_view::size_type len{ sv.size() };
	vector<int> ret(len);

	for (int i{ 1 }, j{ 0 }; i < len; ++i) {
		while (j > 0 && sv[i] != sv[j]) { j = ret[j - 1]; }
		if (sv[i] == sv[j]) { ret[i] = ++j; }
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	getline(cin, T);
	getline(cin, P);
	lenT = T.size();
	lenP = P.size();
	Fail(P).swap(vecFail);

	for (int i{ 0 }, j{ 0 }; i < lenT; ++i) {
		while (j > 0 && T[i] != P[j]) { j = vecFail[j - 1]; }
		if (T[i] == P[j]) { ++j; }
		if (j == lenP) {
			answer.push_back(i - lenP + 2);	/* i - (lenP - 1) + 1 */
			j = vecFail[j - 1];
		}
	}

	cout << answer.size() << '\n';
	for (int idx : answer) { cout << idx << ' '; }

	return 0;
}