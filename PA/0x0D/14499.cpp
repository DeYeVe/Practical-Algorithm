// https://www.acmicpc.net/problem/14499

#include <bits/stdc++.h>
using namespace std;

int board[22][22];
int n, m, x, y, k;

void roll(int dir, int dice[6])
{
	int temp[6];
	switch (dir) 
	{
	case 1: temp[0] = dice[0];
		temp[1] = dice[2];
		temp[2] = dice[3];
		temp[3] = dice[5];
		temp[4] = dice[4];
		temp[5] = dice[1];
		for (int i = 0; i < 6; ++i)
			dice[i] = temp[i];
		y++;
		break;

	case 2: temp[0] = dice[0];
		temp[1] = dice[5];
		temp[2] = dice[1];
		temp[3] = dice[2];
		temp[4] = dice[4];
		temp[5] = dice[3];
		for (int i = 0; i < 6; ++i)
			dice[i] = temp[i];
		y--;
		break;

	case 3: temp[0] = dice[5];
		temp[1] = dice[1];
		temp[2] = dice[0];
		temp[3] = dice[3];
		temp[4] = dice[2];
		temp[5] = dice[4];
		for (int i = 0; i < 6; ++i)
			dice[i] = temp[i];
		x--;
		break;

	case 4: temp[0] = dice[2];
		temp[1] = dice[1];
		temp[2] = dice[4];
		temp[3] = dice[3];
		temp[4] = dice[5];
		temp[5] = dice[0];
		for (int i = 0; i < 6; ++i)
			dice[i] = temp[i];
		x++;
		break;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> y >> k;

	int dice[6] = { 0, };

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	while(k--)
	{ 
		int in;
		cin >> in;

		if (in == 1 && y + 1 >= m)
			continue;
		if (in == 2 && y - 1 < 0)
			continue;
		if (in == 3 && x - 1 < 0)
			continue;
		if (in == 4 && x + 1 >= n)
			continue;

		roll(in, dice);

		if (board[x][y] == 0)
			board[x][y] = dice[2];
		else
		{
			dice[2] = board[x][y];
			board[x][y] = 0;
		}
		cout << dice[5] << '\n';
	}
}