// https://www.acmicpc.net/problem/1012

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, m, n, k;
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	cin >> t;

	while (t--)
	{

		int board[52][52] = { 0, }; 
		int vis[52][52] = { 0, };
		int res = 0;

		cin >> m >> n >> k;

		for (int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> x >> y;
			board[x][y]++;
		}

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (!board[i][j] || vis[i][j])
					continue;

				queue<pair<int, int>> Q;
				Q.push({ i, j });
				vis[i][j]++;
				res++;

				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();

					for (int i = 0; i < 4; ++i)
					{
						int x = cur.X + dx[i];
						int y = cur.Y + dy[i];

						if (x < 0 || y < 0 || x >= m || y >= n)
							continue;
						if (!board[x][y] || vis[x][y])
							continue;
						vis[x][y] = 1;
						Q.push({ x, y });
					}
				}
			}
		}
		cout << res << '\n';
	}
}