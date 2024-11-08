// https://www.acmicpc.net/problem/2178

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[100][100];
int dst[100][100];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j)
			board[i][j] = s[j] - '0';
	}	

	queue<pair<int, int>> Q;
	dst[0][0] = 1;
	Q.push({ 0, 0 });

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
			if (board[x][y] == 0)
				continue;
			if (dst[x][y] > 0)
				continue;
			dst[x][y] = dst[cur.X][cur.Y] + 1;
			Q.push({ x , y });
		}
	}
	cout << dst[n - 1][m - 1];
}