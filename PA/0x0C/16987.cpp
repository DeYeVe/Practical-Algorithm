// https://www.acmicpc.net/problem/16987

#include <bits/stdc++.h>
using namespace std;

int n, mx, broken;
int s[10], w[10];

void func(int cur)
{
	if (cur == n)
	{
		mx = max(mx, broken);
		return;
	}

	if (s[cur] <= 0 || broken == n - 1)
	{
		func(cur + 1);
		return;
	}

	for (int i = 0; i < n; ++i)
	{		
		if (cur != i && s[i] > 0)
		{
			s[cur] -= w[i];
			s[i] -= w[cur];

			bool b1 = s[cur] <= 0;
			bool b2 = s[i] <= 0;

			if (b1)
				broken++;
			if (b2)
				broken++;

			func(cur + 1);

			if (b1)
				broken--;
			if (b2)
				broken--;

			s[cur] += w[i];
			s[i] += w[cur];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i] >> w[i];
	}
	func(0);

	cout << mx;
}