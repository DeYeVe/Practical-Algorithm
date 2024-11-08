// https://www.acmicpc.net/problem/1662

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> pairii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;

	cin >> s;

	stack<pairii> stck;

	int temp = 0;
	int mult = 0;

	stck.push({ 1, 0 });


	for (char ele : s)
	{
		if (ele != '(' && ele != ')')
		{
			pairii top = stck.top();
			stck.pop();
			top.Y++;
			stck.push(top);
			temp = ele - '0';
		}

		if (ele == '(')
		{
			pairii top = stck.top();
			stck.pop();
			top.Y--;
			stck.push(top);

			stck.push({ temp, 0 });
		}

		if (ele == ')')
		{
			pairii top = stck.top();
			stck.pop();
			
			int top_sum = top.X * top.Y;

			top = stck.top();
			stck.pop();

			top.Y += top_sum;

			stck.push(top);
		}
	}

	cout << stck.top().Y;

}