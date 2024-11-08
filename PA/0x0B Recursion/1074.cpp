// https://www.acmicpc.net/problem/1074

#include <bits/stdc++.h>
using namespace std;

int order;

void func(int r, int c, int n)
{
	if (n == 0)
		cout << order;
	else
	{
		int half = (int)pow(2, n - 1);
		if (r < half)
		{
			if (c < half)
			{
				func(r, c, n - 1);
			}
			else
			{
				order += half * half;
				func(r, c - half, n - 1);
			}
		}
		else
		{
			if (c < half)
			{
				order += 2 * half * half;
				func(r - half, c, n - 1);
			}
			else
			{
				order += 3 * half * half;
				func(r - half, c - half, n - 1);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	func(r, c, n);
}