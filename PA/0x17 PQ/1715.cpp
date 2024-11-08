// https://www.acmicpc.net/problem/1715

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int N;
	cin >> N;
	int res = 0;

	priority_queue<int, vector<int>, greater<int>> pq;
	while (N--)
	{
		int i;
		cin >> i;
		pq.push(i);
	}

	while (pq.size() != 1)
	{
		int a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();

		res += a + b;
		pq.push(a + b);
	}

	cout << res;
}