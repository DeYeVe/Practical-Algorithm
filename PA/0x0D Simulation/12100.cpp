// https://www.acmicpc.net/problem/12100

#include <bits/stdc++.h>
using namespace std;

int board[22][22];
int moved[22][22];
int n;

void rotate()
{
	int temp[22][22];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			temp[j][n - i - 1] = moved[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			moved[i][j] = temp[i][j];
}

void tilt(int dir)
{
	while (dir--)
		rotate();

	for (int i = 0; i < n; ++i)
	{
		int temp[22] = { 0, };
		int selected = 0;
		int idx = 0;
		for (int j = 0; j < n; ++j)
		{
			if (moved[i][j] == 0)
				continue;
			if (selected == 0)
			{
				temp[idx] = moved[i][j];
				selected = moved[i][j];
				idx++;
				continue;
			}
			if (selected == moved[i][j])
			{
				temp[idx - 1] *= 2;
				selected = 0;
			}
			else
			{
				temp[idx] = moved[i][j];
				selected = moved[i][j];
				idx++;
			}
		}
		for (int j = 0; j < n; ++j)
			moved[i][j] = temp[j];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int mx = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];

	for (int tmp = 0; tmp < 1024; ++tmp)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				moved[i][j] = board[i][j];

		int b = tmp;
		for (int i = 0; i < 5; ++i)
		{
			int dir = b % 4;
			b /= 4;
			tilt(dir);
		}

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				mx = max(mx, moved[i][j]);
	}

	cout << mx;
}