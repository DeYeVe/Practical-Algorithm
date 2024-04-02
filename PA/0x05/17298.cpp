//https://www.acmicpc.net/problem/17298

#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int ans[1000001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	stack<int> S;

	for (int i = n - 1; i >= 0; --i)
	{
		while (!S.empty() && S.top() <= arr[i])
		{
			S.pop();
		}
		if (S.empty())
			ans[i] = -1;
		else
			ans[i] = S.top();

		S.push(arr[i]);
	}

	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
}