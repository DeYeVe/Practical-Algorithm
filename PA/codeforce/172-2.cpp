#include <bits/stdc++.h>

using namespace std;

int T;
int func()
{
	int n;
	int res = 0;
	cin >> n;

	int arr[1001] = { 0, };
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr[x]++;
	}

	for (int i = 0; i < 1001; i++)
	{
		if (arr[i] % 2 == 0)
			res += 2;
		
	}

	return res;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		cout << func() << "\n";
	}
}