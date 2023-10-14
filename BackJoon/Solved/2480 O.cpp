/* 23.04.24 */
#include <iostream>

using namespace std;

int main()
{
	short	A, B, C, Value = 0, Count = 0;
	cin >> A >> B >> C;

	if (A == B && B == C)
	{
		Value = C;
		Count = 2;
	}
	else
	{
		if (A == B)
		{
			Value = A;
			Count = 1;
		}
		else if (B == C)
		{
			Value = B;
			Count = 1;
		}
		else if (A == C)
		{
			Value = A;
			Count = 1;
		}
	}

	if (Count == 0)
		cout << max<short>(A, max<short>(B, C)) * 100;
	else if (Count == 1)
		cout << 1000 + Value * 100;
	else
		cout << 10000 + Value * 1000;

	return 0;
}