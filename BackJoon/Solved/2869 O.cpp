/* 23.04.24 */
#include <iostream>

using namespace std;

int main()
{
	int Up, Down, Height, Current = 0, Day = 1;
	cin >> Up >> Down >> Height;

    int PerDay = Up - Down;
    Day = (Height - Up) / PerDay;
    Current = Day * PerDay;

 	while (true)
 	{
  		Current = Current + Up;
  
  		if (Current >= Height)
  			break;
  
  		Current = Current - Down;
  		Day++;
 	}

	cout << Day + 1;

	return 0;
}