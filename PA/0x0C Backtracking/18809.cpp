// https://www.acmicpc.net/problem/18809

#include <bits/stdc++.h>
#define G 1
#define R 2
#define F 3
#define X first
#define Y second

using namespace std;

int mx, r, c, green, red;
int garden[52][52];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void spread(int clr[][52])
{
	int color[52][52];
	copy(&clr[0][0], &clr[0][0] + 52 * 52, &color[0][0]);
	int sec[52][52] = { 0, };
	int flower = 0;
	int second = 0;

	queue<pair<int, int>> Q;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (color[i][j] > 0)
				Q.push({ i, j });

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();

		if (color[cur.X][cur.Y] == F)
			continue;
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (garden[nx][ny] == 0 || color[nx][ny] == F)
				continue;
			if (color[nx][ny] == 0)
			{
				color[nx][ny] = color[cur.X][cur.Y];
				sec[nx][ny] = sec[cur.X][cur.Y] + 1;
				Q.push({ nx, ny });
				continue;
			}
			if (color[cur.X][cur.Y] == G)
			{
				if (color[nx][ny] == G)
					continue;
				else if (sec[nx][ny] == sec[cur.X][cur.Y] + 1) // R
				{
					color[nx][ny] = F;
					flower++;
					continue;
				}
			}
			if (color[cur.X][cur.Y] == R)
			{
				if (color[nx][ny] == R)
					continue;
				else if (sec[nx][ny] == sec[cur.X][cur.Y] + 1) // R
				{
					color[nx][ny] = F;
					flower++;
					continue;
				}
			}
		}
	}
	mx = max(mx, flower);
}

bool is_used[52][52];
int color[52][52];
void comb(int g_left, int r_left, int idx)
{
	if (idx > r * c - 1)
		return;
	if (g_left == 0 && r_left == 0)
	{
		spread(color);
		return;
	}
	if (r_left > 0)
	{
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if ((idx == 0 || (i * c + j > idx)) && garden[i][j] == 2 && !is_used[i][j])
				{
					is_used[i][j] = true;
					color[i][j] = R;
					comb(g_left, r_left - 1, i * c + j);
					is_used[i][j] = false;
					color[i][j] = 0;
				}
	}
	if (g_left > 0)
	{
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if ((idx == 0 || (i * c + j > idx)) && garden[i][j] == 2 && !is_used[i][j])
				{
					is_used[i][j] = true;
					color[i][j] = G;
					comb(g_left - 1, r_left, i * c + j);
					is_used[i][j] = false;
					color[i][j] = 0;
				}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> green >> red;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> garden[i][j];
	comb(green, red, 0);

	cout << mx;
}