/* 23.05.02 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, House[1001][3], Cost[3];
	for (int i = 0; i < 3; ++i)
		House[0][i] = 0;

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Cost[0] >> Cost[1] >> Cost[2];

		House[i][0] = min<int>(House[i - 1][1], House[i - 1][2]) + Cost[0];
		House[i][1] = min<int>(House[i - 1][0], House[i - 1][2]) + Cost[1];
		House[i][2] = min<int>(House[i - 1][0], House[i - 1][1]) + Cost[2];
	}

	cout << min<int>(min<int>(House[N][0], House[N][1]), House[N][2]) << '\n';

	return 0;
}