/* 23. 09. 09 */
#include <bits/stdc++.h>

using namespace std;

class CRoom
{
public:
	int iAttack;
	int iHealth;
	int iType;
};

class CPlayer
{
public:
	void setHP(long long hp) {
		llCurHP = llMaxHP = hp;
		llAttack = llInitAtk;
	}
	void Heal(long long amount) {
		llCurHP += amount;
		if (llCurHP > llMaxHP) { llCurHP = llMaxHP; }
	}

	long long llCurHP{ 0 };
	long long llMaxHP{ 0 };
	long long llAttack;
	long long llInitAtk{ 0 };
};

int N;
long long ret{ numeric_limits<long long>::max() };
CPlayer player;
vector<CRoom> rooms;

bool Battle(CRoom room)
{
	long long cnt = room.iHealth / player.llAttack + (room.iHealth % player.llAttack ? 1 : 0);
	player.llCurHP -= (cnt - 1) * room.iAttack;

	if (player.llCurHP <= 0) { return false; }
	else { return true; }
}

void Potion(CRoom& room)
{
	player.llAttack += room.iAttack;
	player.Heal(room.iHealth);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> player.llInitAtk;
	rooms.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> rooms[i].iType >> rooms[i].iAttack >> rooms[i].iHealth; }

	long long mid{ 0 }, lo{ 1 }, hi{ static_cast<long long>(1e18) + 4 };
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		player.setHP(mid);
		bool isDead = false;
		
		for (auto& room : rooms) {
			if (room.iType == 1) {
				if (!Battle(room)) {
					isDead = true;
					break;
				}
			}
			else { Potion(room); }
		}

		if (isDead) { lo = mid + 1; }
		else {
			ret = min(ret, mid);
			hi = mid - 1;
		}
	}

	cout << ret;

	return 0;
}