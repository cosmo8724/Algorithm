#include <bits/stdc++.h>

using namespace std;

int n = 9, r = 7;
vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void Permutation(int n, int r, int depth)
{
	if (r == depth)
	{
		// logic
		return;
	}

	for (int i = depth; i < n; i++)
	{
		swap(v[i], v[depth]);
		Permutation(n, r, depth + 1);
		swap(v[i], v[depth]);
	}
}

int main()
{
	Permutation(n, r, 0);

	sort(v.begin(), v.end());
	do {
		// logic
	} while (next_permutation(v.begin(), v.end()));

	sort(v.rbegin(), v.rend());
	do {
		// logic
	} while (prev_permutation(v.begin(), v.end()));

	return 0;
}