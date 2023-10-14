/* 23.05.06 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int Avg, Mid, MostNum = 0, Range;
	int N, Num;
	double Sum = 0.0;
	vector<int>	Nums;
	vector<int> SameCountNums;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Num;
		Nums.push_back(Num);
		Sum = Sum + static_cast<double>(Num);
	}

	sort(Nums.begin(), Nums.end());

	int Count = 1;
	int	PreNum = 4001;
	int Many = 1;

	for (int i : Nums)
	{
		if (i == PreNum)
			Count++;
		else
		{
			if (Count > Many)
			{
				Many = Count;
				SameCountNums.clear();
				vector<int>{}.swap(SameCountNums);
				SameCountNums.push_back(i);
			}
			else if (Count == Many)
				SameCountNums.push_back(i);

			Count = 1;
			PreNum = i;
		}
	}

	for (int i = 1; i < SameCountNums.size(); ++i)
	{
		if (SameCountNums[i] == SameCountNums[i - 1])
			SameCountNums[i] = 4001;
	}

	sort(SameCountNums.begin(), SameCountNums.end());

	Avg = round(Sum / N);
	Mid = Nums[(N - 1) / 2];
	if (SameCountNums.size() == 1)
		MostNum = SameCountNums.front();
	else if (SameCountNums.size() > 1)
		MostNum = SameCountNums[1];
	Range = Nums.back() - Nums.front();

	cout << Avg << '\n';
	cout << Mid << '\n';
	cout << MostNum << '\n';
	cout << Range << '\n';

	return 0;
}