//https://www.acmicpc.net/problem/1655

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int N;
	cin >> N;

	priority_queue<int> Max;
	priority_queue<int, vector<int>, greater<int>> Min;

	while (N--)
	{
		int i;
		cin >> i;
		if (Max.empty())
			Max.push(i);
		else
		{
			if (Min.size() < Max.size())
				Min.push(i);
			else
				Max.push(i);

			if (Max.top() > Min.top())
			{
				int maxtop = Max.top();
				int mintop = Min.top();

				Max.pop();
				Min.pop();
				Max.push(mintop);
				Min.push(maxtop);
			}
		}
		cout << Max.top() << '\n';
	}
}