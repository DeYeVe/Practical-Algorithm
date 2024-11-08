// https://www.acmicpc.net/problem/1806

#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[100001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tot;
	int mn = 1000000000;

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	tot = arr[0];

	int en = 0;
	
	for (int st = 0; st < N; st++)
	{
		while (en < N && tot < S)
		{
			en++;
			if (en < N)
				tot += arr[en];
		}
		if (en == N)
			break;

		mn = min(mn, en - st + 1);
		
		tot -= arr[st];
	}

	if (mn == 1000000000)
		cout << 0;
	else
		cout << mn;
}