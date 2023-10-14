/* 23. 05. 23 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> Height;
	int h = 0;
	while (Height.size() < 9)
	{
		cin >> h;
		Height.push_back(h);
	}

	sort(Height.begin(), Height.end());

	do 
	{
		int sum = 0;
		vector<int> ret;
		for (int i = 0; i < 7; i++)
		{
			ret.push_back(Height[i]);
			sum += Height[i];
		}

		if (sum == 100)
		{
			for (int i : ret)
				cout << i << '\n';
			return 0;
		}

	} while (next_permutation(Height.begin(), Height.end()));

	return 0;
}