// https://www.acmicpc.net/problem/15683

#include <bits/stdc++.h>
using namespace std;

int office[8][8];
int n, m, mn;

void up(int r, int c, int arr[][8])
{
	for (int i = r - 1; i >= 0; --i)
	{
		if (arr[i][c] == 6)
			break;
		if (arr[i][c] == 0)
			arr[i][c] = 7;
	}
}

void down(int r, int c, int arr[][8])
{
	for (int i = r + 1; i < n; ++i)
	{
		if (arr[i][c] == 6)
			break;
		if (arr[i][c] == 0)
			arr[i][c] = 7;
	}
}

void left(int r, int c, int arr[][8])
{
	for (int i = c - 1; i >= 0; --i)
	{
		if (arr[r][i] == 6)
			break;
		if (arr[r][i] == 0)
			arr[r][i] = 7;
	}
}

void right(int r, int c, int arr[][8])
{
	for (int i = c + 1; i < m; ++i)
	{
		if (arr[r][i] == 6)
			break;
		if (arr[r][i] == 0)
			arr[r][i] = 7;
	}
}

void func(int r, int c, int arr[][8])
{
	if (c >= m)
	{
		r++;
		c = 0;
	}

	if (r == n)
	{
		int sum = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (arr[i][j] == 0)
					sum++;

		mn = min(mn, sum);

		return;
	}

	int cp[8][8];
	copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

	if (cp[r][c] == 0 || cp[r][c] == 6 || cp[r][c] == 7)
		func(r, c + 1, cp);

	if (cp[r][c] == 1)
	{
		up(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

		down(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

		left(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

		right(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);
	}

	if (cp[r][c] == 2)
	{
		up(r, c, cp);
		down(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

		left(r, c, cp);
		right(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);
	}

	if (cp[r][c] == 3)
	{
		up(r, c, cp);
		left(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

		up(r, c, cp);
		right(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

		down(r, c, cp);
		left(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

		down(r, c, cp);
		right(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

	}

	if (cp[r][c] == 4)
	{
		up(r, c, cp);
		left(r, c, cp);
		right(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

		up(r, c, cp);
		left(r, c, cp);
		down(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

		up(r, c, cp);
		right(r, c, cp);
		down(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);

		down(r, c, cp);
		left(r, c, cp);
		right(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);
	}

	if (cp[r][c] == 5)
	{
		up(r, c, cp);
		left(r, c, cp);
		right(r, c, cp);
		down(r, c, cp);
		func(r, c + 1, cp);
		copy(&arr[0][0], &arr[0][0] + 64, &cp[0][0]);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> office[i][j];

	mn = 9999;
	func(0, 0, office);
	cout << mn;
}