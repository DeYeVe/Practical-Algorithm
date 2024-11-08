// https://www.acmicpc.net/problem/10026

#include <bits/stdc++.h>
using namespace std;

#define X first;
#define Y second;

int board[101][101];
int vis[101][101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = { 0, -1, 0, 1 };

	int n, ansa = 0, ansb = 0;
	int turn = 2;

	bool rgb = true;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j)
		{
			board[i][j] = s[j];
		}
	}

	while (turn--)
	{
		if (turn == 1)
			rgb = true;
		else
		{
			rgb = false;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
				{
					vis[i][j] = 0;
					if (board[i][j] == 'R')
						board[i][j] = 'G';
				}
		}

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (vis[i][j] == 1)
					continue;

				queue<pair<int, int>> Q;
				Q.push({ i, j });
				vis[i][j] = 1;
				
				if (rgb)
					ansa++;
				else
					ansb++;

				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();
					int curX = cur.X;
					int curY = cur.Y;
					int curcolor = board[curX][curY];

					for (int k = 0; k < 4; ++k)
					{
						int nx = curX + dx[k];
						int ny = curY + dy[k];

						if (nx < 0 || nx > n || ny < 0 || ny > n)
							continue;
						if (vis[nx][ny])
							continue;
						if (board[nx][ny] != curcolor)
							continue;

						Q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}
			}
	}

	cout << ansa << " " << ansb;

}