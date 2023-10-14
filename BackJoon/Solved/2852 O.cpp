/* 23. 08. 09 */
#include <bits/stdc++.h>

using namespace std;

int n, winA, winB;
string s;
const int total_time = 48 * 60;
vector<int> scoreA(total_time, 0);
vector<int> scoreB(total_time, 0);

int main()
{
	cin >> n;

	while (n--) {
		int team;
		cin >> team;
		cin >> s;
		
		int minute = stoi(s.substr(0, 2));
		int second = stoi(s.substr(3, 2));
		if (team == 1) {
			for (int sec = minute * 60 + second; sec < total_time; sec++) {
				scoreA[sec]++;
			}
		}
		else {
			for (int sec = minute * 60 + second; sec < total_time; sec++) {
				scoreB[sec]++;
			}
		}
	}

	for (int i = 0; i < total_time; i++) {
		if (scoreA[i] > scoreB[i]) {
			winA++;
		}
		else if (scoreA[i] < scoreB[i]) {
			winB++;
		}
	}

	string minute = to_string(winA / 60);
	minute = minute.size() == 1 ? "0" + minute : minute;
	string second = to_string(winA % 60);
	second = second.size() == 1 ? "0" + second : second;
	cout << minute << ":" << second << '\n';

	minute = to_string(winB / 60);
	minute = minute.size() == 1 ? "0" + minute : minute;
	second = to_string(winB % 60);
	second = second.size() == 1 ? "0" + second : second;
	cout << minute << ":" << second << '\n';

	return 0;
}