// https://www.acmicpc.net/problem/1926

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[500][500];
bool vis[500][500];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int n, m;
	int num = 0; int max = 0;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 0 || vis[i][j])
				continue;

			num++;

			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i, j });

			int area = 0;

			while (!Q.empty())
			{
				area++;
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int x = cur.X + dx[i];
					int y = cur.Y + dy[i];

					if (x < 0 || y < 0 || x >= n || y >= m)
						continue;
					if (vis[x][y] || board[x][y] == 0)
						continue;
					vis[x][y] = 1;
					Q.push({ x , y });					
				}
				if (area > max)
					max = area;
			}			
		}
	cout << num << '\n' << max;
}