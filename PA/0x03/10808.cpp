// https://www.acmicpc.net/problem/10808

#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int cnt[26] = {};
	cin >> s;
	
	for (auto e : s)
	{
		cnt[e - 'a']++;
	}
	for (auto e : cnt)
	{
		cout << e << ' ';
	}
}