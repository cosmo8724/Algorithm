/* 23. 09. 11 */
#include <bits/stdc++.h>

using namespace std;

class CRoom
{
public:
	int iAttack;
	int iHealth;
	int iType;
};

int N;
long long attack, potion;
long long ret{ 0 };
vector<CRoom> rooms;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> attack;
	rooms.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> rooms[i].iType >> rooms[i].iAttack >> rooms[i].iHealth; }

	for (int i{ 0 }; i < N; ++i) {
		if (rooms[i].iType == 1) {
			long long cnt = rooms[i].iHealth / attack + (rooms[i].iHealth % attack ? 1 : 0);
			long long dmg = (cnt - 1) * rooms[i].iAttack;
			if (potion < dmg) {
				ret += dmg - potion;
				potion = 0;
			}
			else { potion -= dmg; }
		}
		else {
			potion = min(potion + rooms[i].iHealth, ret);
			attack += rooms[i].iAttack;
		}
	}

	cout << ++ret;

	return 0;
}