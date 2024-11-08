// https://www.acmicpc.net/problem/4179

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int dst_f[1002][1002];
int dst_j[1002][1002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int n, m;
	cin >> n >> m;

	queue<pair<int, int>> Q_f;
	queue<pair<int, int>> Q_j;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j)
		{
			board[i][j] = s[j];
			if (board[i][j] == 'F')
			{
				Q_f.push({ i, j });
			}
			if (board[i][j] == 'J')
			{
				Q_j.push({ i, j });
			}
			if (board[i][j] == '.')
			{
				dst_f[i][j] = -1;
				dst_j[i][j] = -1;
			}
		}
	}

	while (!Q_f.empty())
	{
		pair<int, int> cur = Q_f.front();
		Q_f.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];

			if (x < 0 || y < 0 || x >= n || y >= m)
				continue;
			if (board[x][y] == '#')
				continue;
			if (dst_f[x][y] >= 0)
				continue;
			dst_f[x][y] = dst_f[cur.X][cur.Y] + 1;
			Q_f.push({ x , y });
		}
	}

	while (!Q_j.empty())
	{
		pair<int, int> cur = Q_j.front();
		Q_j.pop();

		if (cur.X == 0 || cur.Y == 0 || cur.X == n - 1 || cur.Y == m - 1) //escape
		{
			cout << dst_j[cur.X][cur.Y] + 1;
			return 0;
		}

		for (int i = 0; i < 4; ++i)
		{
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];
			
			if (x < 0 || y < 0 || x >= n || y >= m)
				continue;
			if (board[x][y] == '#')
				continue;
			if (board[x][y] == 'F')
				continue;
			if (dst_j[x][y] > 0)
				continue;
			if (dst_f[x][y] != -1 && dst_f[x][y] <= dst_j[cur.X][cur.Y] + 1)
				continue;

			dst_j[x][y] = dst_j[cur.X][cur.Y] + 1;
			Q_j.push({ x , y });

		}
	}
	cout << "IMPOSSIBLE";
}