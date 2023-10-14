/* 23. 08. 23 */
#include <bits/stdc++.h>

using namespace std;

string S;

int main()
{
	cin >> S;

	int i{ 0 };
	const int size = S.size();
	for (i; i < size; ++i) {
		if (i < size - 1 && S[i] == 'p' && S[i + 1] == 'i') { ++i; }
		else if (i < size - 1 && S[i] == 'k' && S[i + 1] == 'a') { ++i; }
		else if (i < size - 2 && S[i] == 'c' && S[i + 1] == 'h' && S[i + 2] == 'u') { i += 2; }
		else { break; }
	}

	if (i == size) { cout << "YES"; }
	else { cout << "NO"; }

	return 0;
}