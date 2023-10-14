/* 23. 05. 23 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int Cnt;
	cin >> Cnt;

	string str;
	cin >> str;

	string strFront;
	string strEnd;
	bool flag = false;

	for (char sz : str)
	{
		if (sz == '*')
		{
			flag = true;
			continue;
		}

		if (!flag)
			strFront += sz;
		else
			strEnd += sz;
	}

	while (Cnt--)
	{
		cin >> str;

		/* ab*ab �� ������ �� ab ���� ��찡 �� ���� ����ó�� */
		if (strFront.size() + strEnd.size() > str.size())
		{
			cout << "NE" << '\n';
			continue;
		}

		if (strFront == str.substr(0, strFront.size()))
		{
			if (strEnd == str.substr(str.size() - strEnd.size()))
			{
				cout << "DA" << '\n';
				continue;
			}
		}

		cout << "NE" << '\n';
	}

	return 0;
}