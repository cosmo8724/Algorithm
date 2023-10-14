/* 23. 05. 23 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	getline(cin, str);

	for (char& sz : str)
	{
		if (islower(sz))
		{
			if (sz > 'z' - 13)
				sz -= 13;
			else
				sz += 13;
		}
		else if (isupper(sz))
		{
			if (sz > 'Z' - 13)
				sz -= 13;
			else
				sz += 13;
		}
	}

	cout << str;

	return 0;
}