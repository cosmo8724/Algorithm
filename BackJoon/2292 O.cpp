#include <iostream>

using namespace std;

int main()
{
	int Num = 0;
	cin >> Num;

	int i = 0;
	int k = 1;
	while (true)
	{
		k = k + i * 6;
		if (Num > k)
		{
			i++;
			continue;
		}
		else
			break;
	}

	cout << i + 1;

	return 0;
}