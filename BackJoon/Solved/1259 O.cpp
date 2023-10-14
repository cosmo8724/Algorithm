/* 23.04.26 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string	Number;
	string	RevNumber;

	while (true)
	{
		cin >> Number;

		if (Number == "0")
			break;

		RevNumber = Number;

		reverse(RevNumber.begin(), RevNumber.end());

		if (Number == RevNumber)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}

	return 0;
}