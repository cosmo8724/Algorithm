/* 23. 08. 18 */
#include <bits/stdc++.h>

using namespace std;

int N, K, cur, ret;
string s;
vector<int> words;

int Check(int cur)
{
	int cnt = 0;
	for (int word : words) {
		if (word && (word & cur) == word) { cnt++; }
	}
	return cnt;
}

int Learn(int index, int cnt, int cur)
{
	if (cnt <= 0 || index == 26) { return Check(cur); }

	int ret = Learn(index + 1, cnt, cur);
	if (!(cur & (1 << index))) { ret = max(ret, Learn(index + 1, cnt - 1, cur | (1 << index))); }

	return ret;
}

int main()
{
	cin >> N >> K;
	words.resize(N);
	K -= 5;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s.size() == 8 && K >= 0) { ::ret++; continue; }
		for (int j = 0; j < s.size(); j++) {
			words[i] |= 1 << (s[j] - 'a');
		}
	}

	cur |= 1 << ('a' - 'a');
	cur |= 1 << ('c' - 'a');
	cur |= 1 << ('i' - 'a');
	cur |= 1 << ('n' - 'a');
	cur |= 1 << ('t' - 'a');

	if (K >= 0) { ::ret += Learn(0, K, cur); }
	
	cout << ::ret << '\n';

	return 0;
}