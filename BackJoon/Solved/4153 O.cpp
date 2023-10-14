/* 23.04.26 */
#include <iostream>

using namespace std;

void sort_triangle(int* Arr)
{
	int temp = 0;
	for (int i = 0; i < 2; ++i)
	{
		if (Arr[i] > Arr[i + 1])
		{
			temp = Arr[i + 1];
			Arr[i + 1] = Arr[i];
			Arr[i] = temp;
		}
	}

	if (Arr[0] > Arr[1])
	{
		temp = Arr[1];
		Arr[1] = Arr[0];
		Arr[0] = temp;
	}
}

int main()
{
	int	Leg[3];
	int	Longest = 0;

	while (true)
	{
		for (int i = 0; i < 3; ++i)
			cin >> Leg[i];
		
		if (Leg[0] == 0 && Leg[1] == 0 && Leg[2] == 0)
			break;

		sort_triangle(Leg);

		if (Leg[0] * Leg[0] + Leg[1] * Leg[1] == Leg[2] * Leg[2])
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}

	return 0;
}