// https://www.acmicpc.net/problem/5430

#include <bits/stdc++.h>
using namespace std;

void parse(string &s, deque<int> &dq)
{
	int buf = 0;
	for (int i = 1; i < s.size() - 1; ++i)
	{
		if (s[i] == ',')
		{
			dq.push_back(buf);
			buf = 0;
		}
		else
			buf = buf * 10 + (s[i] - '0');
	}
	if (buf != 0)
		dq.push_back(buf);
}

void print_dq(deque<int> &dq)
{
	cout << "[";
	for (int i = 0; i < dq.size(); ++i)
	{
		cout << dq[i];
		if (i != dq.size() - 1)
			cout << ",";
	}
	cout << "]\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		deque<int> dq;
		string p, arr;
		bool rev = 0, error = 0;
		int n;
		cin >> p >> n >> arr;

		parse(arr, dq);

		for (auto ele : p)
		{
			if (ele == 'R')
				rev = !rev;
			else // 'D'
			{
				if (dq.empty())
				{
					error = 1;
					break;
				}
				if (rev)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}
		if (error)
			cout << "error\n";
		else
		{
			if (rev)
				reverse(dq.begin(), dq.end());
			print_dq(dq);
		}
	}
}