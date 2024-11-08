// https://www.acmicpc.net/problem/1931

#include <bits/stdc++.h>
using namespace std;

int main(void)
{

	int N;

	cin >> N;

	pair<int, int> S[100005];

	for(int i = 0; i < N; ++i)
	{
		int j, k;
		cin >> j >> k;
		S[i] = { k, j };
	}

	sort(S, S + N);

	int res = 0;
	int t = 0;

	for (int i = 0; i < N; ++i)
	{
		if (t <= S[i].first)
		{
			if (t <= S[i].second)
			{
				t = S[i].first;
				res++;
			}
		}
	}

	cout << res;
}