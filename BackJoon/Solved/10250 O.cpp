/* 23.04.24 */
#include <iostream>

using namespace std;

int main()
{
	int	Count, H, W, N;
	int	Floor, Room;

	cin >> Count;

	while (Count--)
	{
		cin >> H >> W >> N;

		Room = N / H;
		Floor = N % H * 100;

		if (Floor == 0)
			Floor = H * 100;
		else
			Room++;

		cout << Floor + Room << '\n';
	}

	return 0;
}