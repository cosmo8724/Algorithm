/* 23.04.26 */
#include <iostream>
#include <string>

using namespace std;

string	WhiteSt[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string	BlackSt[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int Check_Count(string* Board, int StartIndexN, int StartIndexM)
{
	int		BlackCount = 0;
	int		WhiteCount = 0;

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (Board[StartIndexN + i][StartIndexM + j] != BlackSt[i][j])
				BlackCount++;

			if (Board[StartIndexN + i][StartIndexM + j] != WhiteSt[i][j])
				WhiteCount++;
		}
	}

	return min(BlackCount, WhiteCount);
}

int main()
{
	string	Board[50];
	int		N, M;
	int		Count;
	int		MinCount = INT_MAX;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> Board[i];

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			Count = Check_Count(Board, i, j);
			if (MinCount > Count)
				MinCount = Count;
		}
	}

	cout << MinCount << '\n';

	return 0;
}