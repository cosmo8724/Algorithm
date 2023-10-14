#include <bits/stdc++.h>

using namespace std;

int n, q;
string s;
map<int, long long> table;

long long solve(int S, int E)
{
	long long ret = 0;

	S = s.rfind('*', S - 1);

	if (s[E] != '*')
		E = s.rfind('*', E);

	E = s.rfind('*', E - 1);

	return table[E] - table[S];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> s;
	cin >> q;

	long long* pValue = nullptr;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '*')
		{
			if (pValue)
				table[i] = *pValue;

			pValue = &table[i];
			continue;
		}

		if (pValue)
			*pValue += s[i] - '0';
	}

	if (pValue && *pValue)
		table.erase(--table.end());

	for (int i = 0; i < q; i++)
	{
		int S, E;
		cin >> S >> E;
		cout << solve(S, E) << '\n';
	}
}