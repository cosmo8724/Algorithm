/* 23. 09. 27 */
#include <bits/stdc++.h>

using namespace std;

string strA, strB;
int lenA, lenB;
vector<vector<int>> lcs;

int main()
{
	cin >> strA >> strB;
	strA = "0" + strA;
	strB = "0" + strB;
	lenA = strA.size();
	lenB = strB.size();
	vector<vector<int>>(lenA, vector<int>(lenB)).swap(lcs);

	for (int i{ 1 }; i < lenA; ++i) {
		for (int j{ 1 }; j < lenB; ++j) {
			if (strA[i] == strB[j]) { lcs[i][j] = lcs[i - 1][j - 1] + 1; }
			else { lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]); }
		}
	}

	cout << lcs[--lenA][--lenB];

	return 0;
}