#include <bits/stdc++.h>

using namespace std;

int T;
int func()
{

	string s;
	cin >> s;
	int ret = -1;

	int zerotemp = 0;
	for (char e : s)
		if (e - '0' > 0)
		{
			ret++;
			zerotemp = 0;
		}
		else
			zerotemp++;

	return ret + zerotemp;

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