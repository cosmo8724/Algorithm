/* 23. 10. 30 */
/* 접두사 찾기 */
#include <bits/stdc++.h>

using namespace std;

class Trie
{
public:
	void Insert(string_view sv, int depth) {
		if (depth == sv.size()) { return; }

		if (Childs.find(sv[depth]) == end(Childs)) {
			Childs[sv[depth]] = std::move(make_unique<Trie>());
		}

		Childs[sv[depth]]->Insert(sv, depth + 1);
	}
	
	bool Find(string_view sv, int depth) {
		if (depth == sv.size()) { return true; }
		if (Childs.find(sv[depth]) == end(Childs)) { return false; }
		return Childs[sv[depth]]->Find(sv, depth + 1);
	}

	unordered_map<char, unique_ptr<Trie>> Childs;
};

int N, M, ret;
string s;
unique_ptr<Trie> Root{ make_unique<Trie>() };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i{ 0 }; i < N; ++i) {
		cin >> s;
		Root->Insert(s, 0);
	}
	for (int i{ 0 }; i < M; ++i) {
		cin >> s;
		if (Root->Find(s, 0)) {
			++ret;
		}
	}

	cout << ret;

	return 0;
}