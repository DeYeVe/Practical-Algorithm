// https://www.acmicpc.net/problem/13300

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int student[2][6] = {};

	for (int i = 0; i < n; ++i)
	{
		int s, y;
		cin >> s >> y;
		student[s][y - 1]++;
	}

	int r = 0;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 6; ++j)
			r += (student[i][j] + k - 1) / k;
	
	cout << r;
}