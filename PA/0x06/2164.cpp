// https://www.acmicpc.net/problem/2164

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	queue<int> q;

	for (int i = 1; i <= n; ++i)
	{
		q.push(i);
	}

	while (-1 + n--)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();
}