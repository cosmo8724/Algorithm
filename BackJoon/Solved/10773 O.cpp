/* 23.05.02 */
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int	Count, N, Sum = 0;
	stack<int>	Num;

	cin >> Count;

	while (Count--)
	{
		cin >> N;

		if (N == 0)
		{
			Num.pop();
			continue;
		}

		Num.push(N);
	}

	while (Num.size())
	{
		Sum = Sum + Num.top();
		Num.pop();
	}

	cout << Sum << '\n';

	return 0;
}