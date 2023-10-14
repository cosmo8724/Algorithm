/* 23. 05. 23 */
#include <iostream>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int Cnt['z' - 'a' + 1] = {};

	for (char sz : str)
		Cnt[sz - 'a']++;

	for (int i = 0; i < 'z' - 'a' + 1; i++)
		cout << Cnt[i] << ' ';

	return 0;
}