#include <iostream>
#include <string>

using namespace std;

int main()
{
	short	Test, Repeat;
	string	Word;
	string	Result;
	cin >> Test;

	while (Test--)
	{
		cin >> Repeat >> Word;
		Result = "";

		for (short i = 0; i < short(Word.size()); ++i)
		{
			for (short j = 0; j < Repeat; ++j)
				Result += Word[i];
		}

		cout << Result << '\n';
	}

	return 0;
}