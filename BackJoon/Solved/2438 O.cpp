/* 23.04.24 */
#include <iostream>

using namespace std;

int main()
{
	short	Count;
	cin >> Count;
	Count++;

	for (short i = 1; i < Count; ++i)
	{
		for (short j = 1; j <= i; ++j)
			cout << '*';
		cout << '\n';
	}

	return 0;
}