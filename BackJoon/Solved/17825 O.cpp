/* 23. 09. 05 */
#include <bits/stdc++.h>

using namespace std;

const int END_TURN = 10, END_BOARD = 100;
int ret;
vector<vector<int>> adj(32, vector<int>());
vector<int> player(4), dice(END_TURN), score(32);

void Build_Board()
{
	for (int i{ 0 }; i < 20; ++i) { adj[i].push_back(i + 1); }
	adj[5].push_back(21);
	adj[10].push_back(27);
	adj[15].push_back(29);
	for (int i{ 21 }; i < 24; ++i) { adj[i].push_back(i + 1); }
	adj[24].push_back(25);
	adj[25].push_back(26);
	adj[26].push_back(20);
	adj[27].push_back(28);
	adj[28].push_back(24);
	adj[29].push_back(30);
	adj[30].push_back(31);
	adj[31].push_back(24);
	adj[20].push_back(END_BOARD);

	score[1] = 2; score[2] = 4;  score[3] = 6; score[4] = 8; score[5] = 10;
	score[6] = 12; score[7] = 14; score[8] = 16; score[9] = 18; score[10] = 20;
	score[11] = 22; score[12] = 24; score[13] = 26; score[14] = 28; score[15] = 30;
	score[16] = 32; score[17] = 34; score[18] = 36; score[19] = 38; score[20] = 40;
	score[21] = 13; score[22] = 16; score[23] = 19;  score[24] = 25;
	score[27] = 22; score[28] = 24; score[25] = 30; score[26] = 35;
	score[29] = 28; score[30] = 27; score[31] = 26;
}

int Move(int board_idx, int cnt)
{
	if (board_idx == END_BOARD) { return END_BOARD; }
	if (adj[board_idx].size() >= 2) {
		board_idx = adj[board_idx][1];
		--cnt;
	}
	if (cnt) {
		queue<int> q;
		q.push(board_idx);

		while (q.size()) {
			int here = q.front();
			q.pop();

			int& there = adj[here][0];
			q.push(there);

			if (there == END_BOARD) { return there; }
			--cnt;
			if (cnt == 0) { return there; }
		}
	}
	else { return board_idx; }
}

bool Already_There(int board_idx, int player_idx)
{
	if (board_idx == END_BOARD) { return false; }
	for (int i{ 0 }; i < 4; ++i) {
		if (i == player_idx) { continue; }
		if (player[i] == board_idx) { return true; }
	}
	return false;
}

int Play(int dice_idx)
{
	if (dice_idx == END_TURN) { return 0; }

	int ret = 0;

	for (int i{ 0 }; i < 4; ++i) {
		int before_idx = player[i];
		int after_idx = Move(before_idx, dice[dice_idx]);

		if (Already_There(after_idx, i)) { continue; }

		int _score = (after_idx == END_BOARD ? 0 : score[after_idx]);

		player[i] = after_idx;
		ret = max(ret, Play(dice_idx + 1) + _score);
		player[i] = before_idx;
	}

	return ret;
}

int main()
{
	Build_Board();

	for (int i{ 0 }; i < 10; ++i) { cin >> dice[i]; }

	cout << Play(0);

	return 0;
}