// https://www.acmicpc.net/problem/12094

#include <bits/stdc++.h>
using namespace std;

int board[22][22];
int n, localmax, mx;

void rotate(int moved[][22])
{
	int temp[22][22];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			temp[j][n - i - 1] = moved[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			moved[i][j] = temp[i][j];
}

bool tilt(int dir, int moved[][22])
{
	while (dir--)
		rotate(moved);

	bool isEq = true;

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
				localmax = max(localmax, temp[idx - 1]);
				selected = 0;
			}
			else
			{
				temp[idx] = moved[i][j];
				selected = moved[i][j];
				localmax = max(localmax, temp[idx]);
				idx++;
			}
		}
		for (int j = 0; j < n; ++j)
		{
			if (isEq && moved[i][j] != temp[j])
				isEq = false;
			moved[i][j] = temp[j];
		}
	}

	return isEq;
}

void func(int cnt, int moved[][22])
{
	if (cnt == 0)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				mx = max(mx, moved[i][j]);
		return;
	}

	int temp[22][22];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			temp[i][j] = moved[i][j];

	for (int i = 0; i < 4; ++i)
	{
		if (bool(tilt(i, moved)))
		{
			func(0, moved);
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					moved[i][j] = temp[i][j];
			continue;
		}

		if ((localmax << (cnt - 1)) < mx)
		{
			localmax = 0;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					moved[i][j] = temp[i][j];
			return;
		}
		localmax = 0;
		func(cnt - 1, moved);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				moved[i][j] = temp[i][j];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;
	int moved[22][22] = {};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			moved[i][j] = board[i][j];
	func(10, moved);

	cout << mx;
}