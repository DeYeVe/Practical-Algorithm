// https://www.acmicpc.net/problem/1759

#include <bits/stdc++.h>
using namespace std;

char arr[17];
vector<char> v;
bool is_used[28];
int l, c, cons, vowl;

void func(int n)
{
	if (n == l)
	{
		if (vowl < 1 || cons < 2)
			return;
		for (int i = 0; i < l; ++i)
			cout << arr[i];
		cout << '\n';
		return;
	}
	for (int i = 0; i < c; ++i)
	{
		if (n == 0 || arr[n - 1] < v[i] && !is_used[v[i] - 'a'])
		{
			bool b = (v[i] - 'a') * (v[i] - 'e') * (v[i] - 'i') *
				(v[i] - 'o') * (v[i] - 'u') == 0;

			if (b)
				vowl++;
			else
				cons++;
			arr[n] = v[i];
			is_used[v[i] - 'a'] = true;

			func(n + 1);

			if (b)
				vowl--;
			else
				cons--;
			is_used[v[i] - 'a'] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; ++i)
	{
		v.push_back(' ');
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	func(0);
}