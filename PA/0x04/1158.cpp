//https://www.acmicpc.net/problem/1158

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n;
	cin >> k;

	int prev[5001] = {};
	int next[5001] = {};
	
	string output = "<";

	for (int i = 0; i < n; ++i)
	{
		prev[i] = i - 1;
		next[i] = i + 1;
	}
	prev[0] = n - 1;
	next[n - 1] = 0;


	int cur = n - 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			cur = next[cur];
		}
		next[prev[cur]] = next[cur];
		prev[next[cur]] = prev[cur];
		
		output += to_string(cur + 1);
		if(i != n-1)
			output += ", ";
	}
	output += ">";

	cout << output;
}