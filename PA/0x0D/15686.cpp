// https://www.acmicpc.net/problem/15686

#include <bits/stdc++.h>
using namespace std;

int board[52][52];
int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int mn = 2100000000; 

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				house.push_back({ i, j });
			if (board[i][j] == 2)
				chicken.push_back({ i, j });
		}

	vector<int> brute;
	for (int i = 0; i < chicken.size() - m; ++i)
		brute.push_back(0);
	for (int i = 0; i < m; ++i)
		brute.push_back(1);
	do
	{
		int totdist = 0;
		for (auto h : house)
		{
			int temp = 2100000000;
			for (int i = 0; i < chicken.size(); ++i)
			{
				if (brute[i] == 0)
					continue;
				temp = min(temp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
			}
			totdist += temp;
		}
		mn = min(mn, totdist);	
	} while (next_permutation(brute.begin(), brute.end()));

	cout << mn;
}