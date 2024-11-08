// https://www.acmicpc.net/problem/11328

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int isPossible[1001] = {};

	for (int i = 0; i < n; ++i)
	{
		string a, b;
		cin >> a >> b;

		int cnt[26] = {};
		for (auto e : a)
			cnt[e - 'a']++;
		for (auto e : b)
			cnt[e - 'a']--;

		bool flag = 1;
		for (auto e : cnt)
			if (e != 0)
				flag = 0;
		
		if (flag)
			isPossible[i]++;
	}

	for (int i = 0; i < n; ++i)
	{
		if (isPossible[i])
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}
}