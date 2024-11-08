// https://www.acmicpc.net/problem/7576

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1000][1000];
int dst[1000][1000];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int n, m;
	int max = 0;
	cin >> m >> n;

	queue<pair<int, int>> Q;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				Q.push({ i, j });
			}
			if (board[i][j] == 0)
				dst[i][j] = -1;
		}

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];

			if (x < 0 || y < 0 || x >= n || y >= m)
				continue;
			if (board[x][y] != 0)
				continue;
			if (dst[x][y] >= 0)
				continue;

			dst[x][y] = dst[cur.X][cur.Y] + 1;
			if (dst[x][y] > max)
				max = dst[x][y];
			Q.push({ x , y });
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (dst[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
		}
	cout << max;
}