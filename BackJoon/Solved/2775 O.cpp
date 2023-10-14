/* 23.04.26 */
#include <iostream>

using namespace std;

int	Calc_UnderFloor(int Floor, int Room)
{
	int	UnderFloor = Floor - 1;
	int	Total = 0;
	for (int i = 1; i <= Room; ++i)
	{
		if (UnderFloor != 0)
			Total += Calc_UnderFloor(UnderFloor, i);
		else
			Total += i;
	}

	return Total;
}

int main()
{
	int	TestCount;
	int	Floor, Room;

	cin >> TestCount;

	while (TestCount--)
	{
		cin >> Floor >> Room;
		
		cout << Calc_UnderFloor(Floor, Room) << '\n';
	}

	return 0;
}