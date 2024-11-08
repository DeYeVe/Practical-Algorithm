// https://www.acmicpc.net/problem/1780

#include <bits/stdc++.h>
using namespace std;

int nums[3];
vector<vector<int>> v;

bool filled_with(int num, int r, int c, int n)
{
	bool flag = true;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (v[r + i][c + j] != num)
				flag = false;
	
	return flag;
}

void func(int r, int c, int n)
{
	for (int i = 0; i < 3; ++i) {
		if (filled_with(i - 1, r, c, n))
		{
			nums[i]++;
			return;
		}
	}
	
	int third = n / 3;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			func(r + i * third, c + j * third, third);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		vector<int> buf;
		for (int j = 0; j < n; ++j)
		{
			int m;
			cin >> m;
			buf.push_back(m);
		}
		v.push_back(buf);
	}

	func(0, 0, n);

	for (auto ele : nums)
		cout << ele << '\n';
}