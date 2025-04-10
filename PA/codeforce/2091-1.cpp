#include <bits/stdc++.h>

using namespace std;

int T;
int func()
{

	int n;
	cin >> n;
	int digits = 8;
	unordered_multiset<int> ms = { 0,1,0,3,2,0,2,5 };
	int ret = 0;
	

	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		if (ms.find(in) != ms.end())
		{
			ms.erase(ms.find(in));
			if (ms.empty())
				ret= i + 1;
		}
	}

	return ret;
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