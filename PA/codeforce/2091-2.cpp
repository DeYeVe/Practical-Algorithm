#include <bits/stdc++.h>

using namespace std;

int T;
int func()
{

	int n, x;
	cin >> n >> x;
	int ret = 0;

	priority_queue<int> pq;


	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		pq.push(in);
	}

	int temp = 0;
	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		temp++;

		if (cur * temp >= x)
		{
			ret++;
			temp = 0;
		}
	}

	return ret;
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