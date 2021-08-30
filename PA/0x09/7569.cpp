// https://www.acmicpc.net/problem/7569

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[100][100][100];
int dst[100][100][100];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dx[6] = { 1, 0, -1, 0, 0, 0 };
	int dy[6] = { 0, 1, 0, -1, 0, 0 };
	int dz[6] = { 0, 0, 0, 0, 1, -1	};
	int n, m, h;
	int max = 0;
	cin >> m >> n >> h;

	queue<tuple<int, int, int>> Q;

	for (int k = 0; k < h; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{				
				cin >> board[k][i][j];
				if (board[k][i][j] == 1)
				{
					Q.push({ k, i, j });
				}
				if (board[k][i][j] == 0)
					dst[k][i][j] = -1;
			}

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int i = 0; i < 6; ++i)
		{
			int x = get<1>(cur) + dx[i];
			int y = get<2>(cur) + dy[i];
			int z = get<0>(cur) + dz[i];

			if (x < 0 || y < 0 || z < 0 || x >= n || y >= m || z >= h)
				continue;
			if (board[z][x][y] != 0)
				continue;
			if (dst[z][x][y] >= 0)
				continue;

			dst[z][x][y] = dst[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			if (dst[z][x][y] > max)
				max = dst[z][x][y];
			Q.push({ z, x, y });
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < h; ++k)
			{
				if (dst[k][i][j] == -1)
				{
					cout << -1;
					return 0;
				}
			}
	cout << max;
}