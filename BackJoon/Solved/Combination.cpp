#include <bits/stdc++.h>

using namespace std;

int n = 5, r = 3, arr[] = { 1, 2, 3, 4, 5 };

void Comb(int start, vector<int>& v)
{
	if (v.size() == r)
	{
		// logic
		return;
	}

	for (int i = start + 1; i < n; i++)
	{
		v.push_back(i);
		Comb(i, v);
		v.pop_back();
	}
}

int main()
{
	vector<int> v;

	Comb(-1, v);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < j; j++)
		{
			for (int k = 0; k < j; k++)
			{
				// logic
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				// logic
			}
		}
	}

	return 0;
}