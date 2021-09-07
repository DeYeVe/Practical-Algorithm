// https://www.acmicpc.net/problem/1799

#include <bits/stdc++.h>
using namespace std;

int board[12][12];
int k, mx[2];
bool is_used1[22]; // 좌상단 시작 (r + c)
bool is_used2[22]; // 우상단 시작 (k - 1 + r - c)

void func(int r, int c, int cnt, int color)
{
	if (c >= k)
	{
		r++;
		c = (c % 2) ? 0 : 1;
	}

	if (r == k)
	{
		mx[color] = max(mx[color], cnt);
		return;
	}

	if (board[r][c] && !is_used1[r + c] && !is_used2[k - 1 + r - c])
	{
		is_used1[r + c] = true;
		is_used2[k - 1 + r - c] = true;
		func(r, c + 2, cnt + 1, color);
		is_used1[r + c] = false;
		is_used2[k - 1 + r - c] = false;
	}

	func(r, c + 2, cnt, color);

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < k; ++j)
			cin >> board[i][j];

	func(0, 0, 0, 0);
	func(0, 1, 0, 1);
	cout << mx[0] + mx[1];
}