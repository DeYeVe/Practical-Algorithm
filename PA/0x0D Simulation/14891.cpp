// https://www.acmicpc.net/problem/14891

#include <bits/stdc++.h>
using namespace std;

#define L 6
#define R 2
#define CLK 1
#define CCLK -1
#define STOP 0

int saw[4][8];

void roll(int saw[][8], int num, int dir)
{
	int temp[8];

	if (dir == CLK)
	{
		temp[0] = saw[num][7];
		for (int i = 0; i < 7; ++i)
			temp[i + 1] = saw[num][i];

		for (int i = 0; i < 8; ++i)
			saw[num][i] = temp[i];
	}
	else if (dir == CCLK)
	{
		temp[7] = saw[num][0];
		for (int i = 0; i < 7; ++i)
			temp[i] = saw[num][i + 1];

		for (int i = 0; i < 8; ++i)
			saw[num][i] = temp[i];
	}
	//STOP
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	for (int i = 0; i < 4; ++i)
	{
		cin >> input;
		for (int j = 0; j < 8; ++j)
		{
			saw[i][j] = input.at(j) - '0';
		}

	}
	int cnt, num, dir;
	cin >> cnt;
	while (cnt--)
	{
		cin >> num >> dir;
		num--;

		int movement[4] = { 0, };
		movement[num] = dir;

		queue<tuple<int, int, int>> Q;
		if (num < 3)
			Q.push({ num, dir, R });
		if (num > 0)
			Q.push({ num, dir, L });

		while (!Q.empty())
		{
			tuple<int, int, int> tp = Q.front();
			Q.pop();

			num = get<0>(tp);
			dir = get<1>(tp);
			int side = get<2>(tp);
			if (side == R)
			{
				if (saw[num][R] != saw[num + 1][L])
				{
					movement[num + 1] = -dir;
					if (num + 1 < 3)
						Q.push({ num + 1, -dir, R });
				}
			}
			if (side == L)
			{
				if (saw[num][L] != saw[num - 1][R])
				{
					movement[num - 1] = -dir;
					if (num - 1 > 0)
						Q.push({ num - 1, -dir, L });
				}
			}
		}

		for (int i = 0; i < 4; ++i)
			roll(saw, i, movement[i]);
	}

	cout << saw[0][0] + 2 * saw[1][0] + 4 * saw[2][0] + 8 * saw[3][0];
}