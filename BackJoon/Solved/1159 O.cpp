/* 23. 05. 23 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int Cnt;
	cin >> Cnt;

	string name;
	vector<string> names;
	int arr[26] = {};

	while (Cnt--)
	{
		cin >> name;
		name.substr(1, name.end() - name.begin());
		
		arr[name[0] - 'a']++;
	}

	Cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] >= 5)
		{
			Cnt++;
			cout << char(i + 'a');
		}
	}

	if (Cnt == 0)
		cout << "PREDAJA";

	return 0;
}