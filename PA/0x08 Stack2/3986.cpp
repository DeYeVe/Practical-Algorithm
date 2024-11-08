// https://www.acmicpc.net/problem/3986

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int ans = 0;
	cin >> n;

	while (n--)
	{
		string str;
		cin >> str;

		stack<int>S;
		for (auto ele : str)
		{
			if (S.empty() || S.top() != ele)
				S.push(ele);
			else
				S.pop();
		}

		if (S.empty())
			ans++;
	}

	cout << ans;
}