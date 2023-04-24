#include <iostream>

using namespace std;

int main()
{
	string	Word;
	int		Count[26];

	for (int i = 0; i < 26; ++i)
		Count[i] = -1;

	cin >> Word;

	int		Locate = 0;
	for (char Spell : Word)
	{
		for (int i = 'a'; i <= 'z'; ++i)
		{
			if (Spell == i && Count[i - 'a'] == -1)
				Count[i - 'a'] = Locate;
		}
		Locate++;
	}

	for (int i = 0; i < 26; ++i)
		cout << Count[i] << ' ';

	return 0;
}