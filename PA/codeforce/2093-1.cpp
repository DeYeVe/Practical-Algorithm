#include <bits/stdc++.h>

using namespace std;

int T;
string func()
{

	int n;
	cin >> n;
	int ret = 0;

	if (n % 2 == 0)
		return "NO";
	else
		return "YES";
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