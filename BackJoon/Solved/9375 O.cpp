/* 23. 05. 23 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	map<string, vector<string>> Cloth;
	int Cnt, Num;
	cin >> Cnt;

	while (Cnt--)
	{
		cin >> Num;
		vector<int> part;
		/* ����� �� ������ long long ���� �ޱ�. */
		long long sum = 1;
		string name, type;
		for (int i = 0; i < Num; i++)
		{
			cin >> name >> type;

			Cloth[type].push_back(name);
		}

		/* ���Դ� ��츦 �����Ѵ�. */
		for (auto& Pair : Cloth)
			part.push_back(Pair.second.size() + 1);

		for (int i : part)
			sum *= (long long)i;
		
		/* ��� ���� ������ ��츦 ����. */
		cout << sum - 1 << '\n';

		Cloth.clear();
	}

	return 0;
}