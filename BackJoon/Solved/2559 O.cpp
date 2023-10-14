/* 23. 05. 23 */
#include <iostream>

using namespace std;

int main()
{
	int Cnt, Day;
	cin >> Cnt >> Day;

	int temp = 0;
	int psum[100001] = {};
	int ret = -10000004;

	for (int i = 1; i <= Cnt; i++)
	{
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}

	for (int i = Day; i <= Cnt; i++)
		ret = max(ret, psum[i] - psum[i - Day]);

	cout << ret << '\n';

	return 0;
}