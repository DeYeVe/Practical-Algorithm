// https://www.acmicpc.net/problem/1919

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	int alph[26] = {};
	int cnt = 0;

	cin >> a >> b;

	for (auto ele : a)
		alph[ele - 'a']++;
	for (auto ele : b)
		alph[ele - 'a']--;
	for (auto ele : alph)
		cnt += abs(ele);

	cout << cnt;
}