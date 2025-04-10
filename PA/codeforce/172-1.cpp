#include <bits/stdc++.h>

using namespace std;

int T;
int func()
{
	int n, k;
	cin >> n >> k;

	priority_queue<int> pq;
	while (n--)
	{
		int x;
		cin >> x;
		pq.push(x);
	}
	while (!pq.empty())
	{
		int temp = pq.top();
		if (k >= temp)
			k -= temp;
		else
			return k;
		pq.pop();
	}

	return k;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		cout << func() << "\n";
	}
}