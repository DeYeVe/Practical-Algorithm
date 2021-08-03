// https://www.acmicpc.net/problem/10804

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int card[20];
	for (int i = 0; i < 20; ++i)
		card[i] = i + 1;

	pair<int, int> p[10];
	for (int i = 0; i < 10; ++i)
	{
		cin >> p[i].first;
		cin >> p[i].second;
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < (p[i].second - p[i].first + 1) / 2; ++j)
			swap(card[p[i].first + j - 1], card[p[i].second - j - 1]);
	}
	for (int i = 0; i < 20; ++i)
		cout << card[i] << ' ';
}