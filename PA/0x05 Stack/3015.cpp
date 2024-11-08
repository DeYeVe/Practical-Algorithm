//https://www.acmicpc.net/problem/3015

#include <bits/stdc++.h>
using namespace std;

int arr[500001];
long long ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<pair<int, int>> S;

	while (n--)
	{
		int h;
		int cnt = 1;
		cin >> h;

		while (!S.empty() && S.top().first <= h)
		{
			ans += S.top().second;
			if (S.top().first == h)
				cnt += S.top().second;
			S.pop();
		}

		if (!S.empty())
			ans++;

		S.push({ h, cnt });
	}

	cout << ans;
}