/* 23. 05. 23 */
#include <iostream>

using namespace std;

int main()
{
	int money[3] = {};
	for (int i = 0; i < 3; i++)
		cin >> money[i];

	int time[101] = {};

	for (int i = 0; i < 3; i++)
	{
		int in, out;
		cin >> in >> out;

		for (int j = in; j < out; j++)
			time[j]++;
	}

	int sum = 0;
	for (int i = 0; i < 101; i++)
	{
		if (time[i] == 0)
			continue;
		else if (time[i] == 1)
			sum += money[0];
		else if (time[i] == 2)
			sum += money[1] * 2;
		else if (time[i] == 3)
			sum += money[2] * 3;
	}

	cout << sum;

	return 0;
}