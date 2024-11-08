// https://www.acmicpc.net/problem/14956

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int, int>

pii loc(int n, int m)
{
	if (n == 2)
	{
		switch (m - 1)
		{
		case 0: return { 1, 1 };
		case 1:	return { 1, 2 };
		case 2:	return { 2, 2 };
		case 3:	return { 2, 1 };
		}
	}
	
	int half = n / 2;
	int quadrant = (m - 1) / (half * half);
	pii p = loc(half, m - quadrant * (half * half));

	switch (quadrant)
	{
	case 0:
		return { p.Y, p.X };
	case 1:
		return { p.X, p.Y + half };
	case 2:
		return { p.X + half, p.Y + half};
	case 3:
		return { n + 1 - p.Y, half + 1 - p.X };
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	cout << loc(n, m).X << ' ' << loc(n, m).Y;
}