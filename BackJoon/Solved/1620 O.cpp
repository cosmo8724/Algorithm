/* 23. 05. 23 */
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<int, string> Num;
	map<string, int> Name;

	int N, M;
	cin >> N >> M;

	string str;
	for (int i = 1; i <= N; i++)
	{
		cin >> str;
		Num.emplace(i, str);
		Name.emplace(str, i);
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> str;
		if (isdigit(str[0]))
			cout << Num[atoi(str.c_str())] << '\n';
		else
			cout << Name[str] << '\n';
	}

	return 0;
}