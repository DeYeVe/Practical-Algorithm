// https://www.acmicpc.net/problem/3273

#include <bits/stdc++.h>
using namespace std;

int flag[2000001];
int arr[100001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, res = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		flag[t]++;
		arr[i] = t;
	}

	cin >> x;

	for (int i = 0; i < n; ++i)
	{
		if (x > arr[i])
			if (flag[x - arr[i]])
				res++;
	}

	cout << res / 2;
}