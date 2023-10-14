/* 23.04.26 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int		Count, Limit;
	int		Temp;
	vector<int>	Card;
	int		Sum = 0;
	int		Max = -1;

	cin >> Count >> Limit;

	for (int i = 0; i < Count; ++i)
	{
		cin >> Temp;
		Card.push_back(Temp);
	}

	sort(Card.begin(), Card.end(), [](int Front, int Back) {
		return Front > Back;
	});

	for (int i = 0; i < Count - 2; i++)
	{
		for (int j = i + 1; j < Count - 1; j++)
		{
			for (int k = j + 1; k < Count; k++)
			{
				Sum = Card[i] + Card[j] + Card[k];
				if (Sum <= Limit && Sum > Max)
					Max = Sum;
			}
		}
	}

	cout << Max << '\n';

	return 0;
}