// https://www.acmicpc.net/problem/10866

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;

	int n;
	cin >> n;

	while (n--)
	{
		string input;
		cin >> input;

		if (input == "push_front")
		{
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (input == "push_back")
		{
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (input == "pop_front")
		{
			if (dq.empty())
				cout << -1 << "\n";
			else
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (dq.empty())
				cout << -1 << "\n";
			else
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (input == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (input == "empty")
		{
			if (dq.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (input == "front")
		{
			if (dq.empty())
				cout << -1 << "\n";
			else
			{
				cout << dq.front() << "\n";
			}
		}
		else if (input == "back")
		{
			if (dq.empty())
				cout << -1 << "\n";
			else
			{
				cout << dq.back() << "\n";
			}
		}
	}
}