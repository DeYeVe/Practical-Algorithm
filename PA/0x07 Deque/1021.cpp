// https://www.acmicpc.net/problem/1021

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;

	int n, m, res = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		dq.push_back(i);

	while (m--)
	{
		int input, idx = 0;
		cin >> input;

		for (int i = 0; i < dq.size(); ++i)
		{
			if (input == dq.at(i))
				idx = i;
		}
		
		if ((dq.size() - idx) > idx)
		{
			while (dq.front() != input)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				res++;
			}
			dq.pop_front();
		}
		else
		{
			while (dq.front() != input)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				res++;
			}
			dq.pop_front();
		}
	}
	cout << res;
}