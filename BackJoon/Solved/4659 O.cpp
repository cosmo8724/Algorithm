/* 23. 08. 08 */
#include <bits/stdc++.h>
#include <array>

using namespace std;

array<const char, 5> vowel { 'a', 'e', 'i', 'o', 'u' };
array<const char, 21> consonant { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };
const string_view& end_input = "end"sv;
string str;

bool HasVowel(const string& s)
{
	for (auto p : s) {
		if (find(vowel.begin(), vowel.end(), p) != vowel.end()) {
			return true;
		}
	}

	cout << format("<{}> is not acceptable.", str);

	return false;
}

bool CheckRule(const string& s)
{
	int vcnt = 0, ccnt = 0;
	const int size = s.size();
	for (int i = 0; i < size; i++) {
		if (i > 0 && s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') {
			return false;
		}

		if (find(vowel.begin(), vowel.end(), s[i]) != vowel.end()) {
			vcnt++;
			ccnt = 0;
		}
		else {
			ccnt++;
			vcnt = 0;
		}

		if (vcnt >= 3 || ccnt >= 3)
			return false;
	}

	return true;
}

int main()
{
	while (true) {
		cin >> str;
		if (str == end_input) {
			break;
		}

		if (!HasVowel(str)) {
			continue;
		}

		if (CheckRule(str)) {
			cout << format("<{}> is acceptable.", str);
		}
		else {
			cout << format("<{}> is not acceptable.", str);
		}
	}

	return 0;
}