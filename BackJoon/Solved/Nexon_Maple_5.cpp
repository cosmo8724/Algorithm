#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, minSize;
string str;
unordered_map<string, vector<int>> mp;
vector<string> ret;

vector<int> makeLPS(const string& s)
{
	int size = s.size();
	vector<int> table(size, 0);

	for (int i = 1, j = 0; i < size; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = table[j - 1];

		if (s[i] == s[j])
			table[i] = ++j;
	}

	return table;
}

bool find_KMP(const string& seq, const string& part)
{
	int s_size = seq.size();
	int p_size = part.size();

	for (int i = 0, j = 0; i < s_size; i++)
	{
		while (j > 0 && seq[i] != part[j])
			j = mp[part][j - 1];

		if (seq[i] == part[j])
		{
			if (j == p_size - 1)
				return true;
			else
				j++;
		}
	}

	return false;
}

bool Filtering(const string& s)
{
	if (mp.empty() || minSize > s.size())
	{
		minSize = s.size();
		return false;
	}

	if (find(ret.begin(), ret.end(), s) != ret.end())
		return true;

	for (auto pair : mp)
	{
		if (s.size() < pair.first.size())
			continue;

		if (find_KMP(s, pair.first))
			return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	while (N--)
	{
		cin >> str;

		if (Filtering(str))
			ret.push_back(str);

		mp[str] = makeLPS(str);
	}

	for (auto& s : ret)
		cout << s << '\n';

	return 0;
}