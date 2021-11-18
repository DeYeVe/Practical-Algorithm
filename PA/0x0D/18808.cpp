// https://www.acmicpc.net/problem/18808

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &v)
{
	int row = v.size();
	int col = v[0].size();
	vector<vector<int>> temp;
	vector<int> temp2;

	for (int i = 0; i < col; ++i)
	{
		for (int j = row - 1; j >= 0; --j)
		{
			temp2.push_back(v[j][i]);
		}
		temp.push_back(temp2);
		temp2.clear();
	}

	v.resize(temp.size());
	copy(temp.begin(), temp.end(), v.begin());
}

vector<vector<int>> notebook;
int n, m;

void func()
{
	vector<int> temp;
	vector<vector<int>> stk;
	int r, c, t;
	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> t;
			temp.push_back(t);
		}
		stk.push_back(temp);
		temp.clear();
	}

	int rot = 4;
	while (rot--)
	{
		if (rot < 3)
		rotate(stk);
		r = stk.size();
		c = stk[0].size();
		vector<vector<int>> fill;
		for (int i = 0; i < n - r + 1; ++i)
			for (int j = 0; j < m - c + 1; ++j)
			{
				bool poss = true;
				fill.resize(notebook.size());
				copy(notebook.begin(), notebook.end(), fill.begin());
				for (int ii = 0; ii < r; ++ii)
					for (int jj = 0; jj < c; ++jj)
					{
						if (stk[ii][jj] == 1)
						{
							if (notebook[i + ii][j + jj] == 0)
								fill[i + ii][j + jj] = 1;
							else
							{
								poss = false;
								jj = c;
								ii = r;
							}
						}							
					}
				if (poss)
				{
					copy(fill.begin(), fill.end(), notebook.begin());
					return;
				}
			}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k, total = 0;
	cin >> n >> m >> k;

	vector<int> temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			temp.push_back(0);
		}
		notebook.push_back(temp);
		temp.clear();
	}

	while (k--)
	{
		func();
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (notebook[i][j] == 1)
				total++;

	cout << total;
}