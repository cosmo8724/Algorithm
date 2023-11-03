/* 23. 11. 03 */
/* 코코스 */
#include <bits/stdc++.h>

using namespace std;

int N, K, ret;
vector<string> v;

class Trie
{
public:
	void Insert(string_view sv, int depth) {
		if (depth == K) { return; }

		if (Childs.find(sv[depth]) == end(Childs)) {
			Childs[sv[depth]] = move(make_unique<Trie>());
		}
		Childs[sv[depth]]->Insert(sv, depth + 1);
	}
	int Count() {
		int ret{ static_cast<int>(Childs.size()) };
		for (auto& [sz, Child] : Childs) {
			ret += Child->Count();
		}
		return ret;
	}
	inline void Clear() { Childs.clear(); }

public:
	map<char, unique_ptr<Trie>> Childs;
};

unique_ptr<Trie> Root{ make_unique<Trie>() };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) {
		cin >> v[i];
		reverse(begin(v[i]) + K, end(v[i]));
		Root->Insert(v[i].substr(0, K), 0);
	}
	ret += Root->Count();
	Root->Clear();
	for (int i{ 0 }; i < N; ++i) {
		Root->Insert(v[i].substr(K, K), 0);
	}
	ret += Root->Count();

	cout << ret;

	return 0;
}