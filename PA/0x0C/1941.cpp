// https://www.acmicpc.net/problem/1941

#include <bits/stdc++.h>
using namespace std;

int arr[9];
char group[27];
bool is_used[27];
int res;

bool is_linked()
{
	int expand[51] = { 0, };
	bool visit[51] = { 0, };
	int begin = 0, cnt = 0;

	for (int i = 0; i < 7; ++i)
	{
		int replace = arr[i] + 8 + 2 * (arr[i] / 5);
		expand[replace]++;
		if (i == 0)
			begin = replace;
	}

	queue<int> Q;
	Q.push(begin);
	int d[4] = { -7, -1, 1, 7 };

	while (!Q.empty())
	{
		int f = Q.front();
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			if (expand[f + d[i]] && !visit[f + d[i]])
			{
				visit[f + d[i]] = true;
				cnt++;
				Q.push(f + d[i]);
			}
		}
	}
	if (cnt == 7)
		return true;
	else
		return false;
}

void func(int cur, int scnt)
{
	if (cur == 7)
	{
		if (scnt < 4)
			return;
		if (is_linked())
			res++;
		return;
	}

	for (int i = 0; i < 25; ++i)
	{
		if (cur == 0 || arr[cur - 1] < i && !is_used[i])
		{
			arr[cur] = i;
			is_used[cur] = true;
			if (group[i] == 'S')
				func(cur + 1, scnt + 1);
			else
				func(cur + 1, scnt);
			is_used[cur] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	for (int i = 0; i < 5; ++i)
	{
		cin >> s;
		for (int j = 0; j < 5; ++j)
			group[5 * i + j] = s[j];			
	}

	func(0, 0);

	cout << res;
}