// https://www.acmicpc.net/problem/7562

#include <bits/stdc++.h>
using namespace std;

#define X first;
#define Y second;

int vis[301][301];


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l, curx, cury, dstx, dsty;
	
	int dx[8] = { 1, 2, -1 , -2, 1, 2, -1, -2 };
	int dy[8] = { 2, 1, 2, 1 , -2, -1, -2, -1 };

	cin >> n;
	while (n--)
	{
		cin >> l >> curx >> cury >> dstx >> dsty;

		queue<pair<int, int>> Q;

		memset(vis, -1, sizeof(vis));

		Q.push({ curx, cury });
		vis[curx][cury] = 0;

		while (!Q.empty())
		{
			pair<int, int> cur = Q.front();
			Q.pop();
			
			int QcurX = cur.X;
			int QcurY = cur.Y;
			int cnt = vis[QcurX][QcurY];
			
			for (int i = 0; i < 8; ++i)
			{
				int QdstX = QcurX + dx[i];
				int QdstY = QcurY + dy[i];

				if (QdstX < 0 || QdstX > l - 1 || QdstY < 0 || QdstY > l - 1)
					continue;

				if (vis[QdstX][QdstY] >= 0 && vis[QdstX][QdstY] <= cnt + 1)
					continue;

				Q.push({ QdstX, QdstY });
				vis[QdstX][QdstY] = cnt + 1;
			}
		}

		cout << vis[dstx][dsty] << "\n";
	}
}