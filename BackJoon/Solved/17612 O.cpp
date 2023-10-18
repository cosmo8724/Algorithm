/* 23. 10. 15 */
#include <bits/stdc++.h>

using namespace std;

int N, K;
long long ret;

class Cashier
{
public:
	bool operator()(Cashier& lhs, Cashier& rhs) {
		if (lhs.maxTime == rhs.maxTime) { return lhs.cashier_id > rhs.cashier_id; }
		return lhs.maxTime > rhs.maxTime;
	}

public:
	int customer_id;
	int cashier_id;
	int maxTime;
};
priority_queue<Cashier, vector<Cashier>, Cashier> customers;
vector<Cashier> v_out;

void Go()
{
	while (!customers.empty()) {
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	for (int i{ 1 }, id, w; i <= N; ++i) {
		cin >> id >> w;

		if (i <= K) { customers.push(Cashier{ id, i, w }); }
		else {
			customers.push(Cashier{ id, customers.top().cashier_id, w + customers.top().maxTime});
			v_out.push_back(customers.top());
			customers.pop();
		}
	}
	while (!customers.empty()) {
		v_out.push_back(customers.top());
		customers.pop();
	}
	sort(begin(v_out), end(v_out), [](const Cashier& lhs, const Cashier& rhs) {
		if (lhs.maxTime == rhs.maxTime) { return lhs.cashier_id > rhs.cashier_id; }
		return lhs.maxTime < rhs.maxTime;
	});

	long long cnt{ 1 };
	for (const Cashier& customer : v_out) {
		ret += (cnt++) * customer.customer_id;
	}
	
	cout << ret;

	return 0;
}