/* 23. 05. 23 */
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int Cnt[200] = {};
	string str;
	cin >> str;
	
	for (char sz : str)
		Cnt[sz]++;

	char mid = 0;
	int flag = 0;
	string ret = "";
	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (Cnt[i])
		{
			/* Ȧ������ üũ */
			if (Cnt[i] & 1)
			{
				mid = (char)i;
				flag++;
				/* ���� 3���� ������ 2���� ���� ret �յڷ� ���̱� ���� �� �� �ٿ��� ¦���� ����. */
				Cnt[i]--;
			}
			/* �Ӹ������ Ȧ���� 2�� ������ ���� �� ����. */
			if (flag == 2)
				break;

			for (int j = 0; j < Cnt[i]; j += 2)
			{
				ret = char(i) + ret;
				ret += char(i);
			}
		}
	}

	/* mid�� ������ �߰��� ��������. */
	if (mid)
		ret.insert(ret.begin() + ret.size() / 2, mid);
	if (flag == 2)
		cout << "I'm Sorry Hansoo\n";
	else
		cout << ret << '\n';

	return 0;
}