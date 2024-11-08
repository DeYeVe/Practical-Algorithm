// https://www.acmicpc.net/problem/1992

#include <bits/stdc++.h>
using namespace std;

int board[64][64];

bool has_zero(int r, int c, int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (board[r + i][c + j] == 0)
				return true;
	return false;
}

bool has_one(int r, int c, int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (board[r + i][c + j] == 1)
				return true;
	return false;
}

void func(int r, int c, int n)
{
	
	if (!has_zero(r, c, n))
		cout << 1;
	else if (!has_one(r, c, n))
		cout << 0;
	else
	{
		cout << '(';

		int half = n / 2;
		func(r, c, half);
		func(r, c + half, half);
		func(r + half, c, half);
		func(r + half, c + half, half);

		cout << ')';
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		for (int j = 0; j < n; ++j)
		{
			board[i][j] = s[j] - '0';
		}
	}
	
	func(0, 0, n);
}