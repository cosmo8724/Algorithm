/* 23. 05. 23 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> mtrl;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		mtrl.push_back(tmp);
	}

	int Cnt = 0;

	/* �ִ� ����� ���� 100000 + 100000���� ũ�� ���� ����. */
	/* ��Ȥ ���� �ð��� �ſ� ª�� ��� �̷� ���� ó���� �ʿ��ϴ�. */
	if (M <= 200000)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (mtrl[i] + mtrl[j] == M)
					Cnt++;
			}
		}
	}

	cout << Cnt;

	return 0;
}