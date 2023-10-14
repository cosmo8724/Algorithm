/* 23. 05 23 */
#include <iostream>
#include <stack>

using namespace std;

/* ������ ���� ��� Ǯ�� �𸣰ڴ�. */
/* �׷� ���� ����ȭ�� �Ѵ�. */
/* 90�� ȸ���� ���ų� ������ ���ų� �ڿ� �Ȱ��� ���� �ϳ� �� �ٿ� ���ų� */
int main()
{
	int N, Cnt = 0;
	cin >> N;

	string str;
	stack<char> st;
	while (N--)
	{
		cin >> str;
		st.push(str[0]);
		for (int i = 1; i < str.size(); i++)
		{
			if (st.empty())
				st.push(str[i]);
			else
			{
				if (str[i] == st.top())
					st.pop();
				else
					st.push(str[i]);
			}
		}

		if (st.empty())
			Cnt++;

		/* stack�̳� queue�� ��� �� �̷��� ���� */
		while (!st.empty())
			st.pop();
	}

	cout << Cnt;

	return 0;
}