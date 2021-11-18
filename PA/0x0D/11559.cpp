// https://www.acmicpc.net/problem/11559

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int chain = 0;
	bool end = false;
	char field[14][8];
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	for (int i = 0; i < 12; ++i)
		for (int j = 0; j < 6; ++j)
			cin >> field[i][j];

	while (!end)
	{
		int vis[14][8];
		for (int i = 0; i < 12; ++i)
			for (int j = 0; j < 6; ++j)
				vis[i][j] = 0;

		end = true;

		for (int i = 0; i < 12; ++i)
			for (int j = 0; j < 6; ++j)
			{
				if (field[i][j] == '.')
					continue;
				if (vis[i][j] == 1)
					continue;

				char color = field[i][j];
				queue<pair<int, int>> Q;
				Q.push({ i, j });
				int area = 1;
				vector<pair<int, int>> temp;
				temp.push_back({ i, j });
				vis[i][j] = 1;

				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();
					
					for (int k = 0; k < 4; ++k)
					{
						int x = cur.X + dx[k];
						int y = cur.Y + dy[k];

						if (x < 0 || x >= 12 || y < 0 || y >= 6)
							continue;
						if (field[x][y] != color || vis[x][y])
							continue;

						temp.push_back({ x, y });
						Q.push({ x, y });
						vis[x][y] = 1;
						area++;
					}
				}

				if (area >= 4)
				{
					for (auto ele : temp)
						field[ele.X][ele.Y] = '.';
					end = false;
				}
			}

		if (end)
			break;

		chain++;
		for (int i = 0; i < 6; ++i)
		{
			char temp[12];
			for (int j = 0; j <12; ++j)
				temp[j] = '.';
			int idx = 0;
			for (int j = 11; j >= 0; --j)
			{
				if (field[j][i] != '.')
				{
					temp[idx] = field[j][i];
					idx++;
				}
			}

			for (int j = 11; j >= 0; --j)
			{
				field[j][i] = temp[11 - j];
			}
		}
	}

	cout << chain;
}