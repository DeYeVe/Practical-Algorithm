#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	auto cmp = [&](int& a, int& b)
		{
			return a > b;
		};

	priority_queue<int, vector<int>, decltype(cmp)> pq{cmp
};


	pq.push(5);
	pq.push(1);
	pq.push(3);

	while (!pq.empty()) {
		std::cout << pq.top() << " ";
		pq.pop();
	}


}