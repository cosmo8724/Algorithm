/* 23.04.27 */
#include <iostream>

using namespace std;

int main()
{
	int	N;
	int Five = 0, Three = 0;
	cin >> N;

	Five = N / 5;

	while (true)
	{
		if (Five < 0)
		{
			cout << -1 << '\n';
			return 0;
		}
		if ((N - (5 * Five)) % 3 == 0)
		{
			Three = (N - (5 * Five)) / 3;
			break;
		}
		Five--;
	}

	cout << Five + Three << '\n';

	return 0;
}