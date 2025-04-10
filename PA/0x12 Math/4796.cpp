//https://www.acmicpc.net/problem/4796

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int cnt = 1;
	while (true) {

		int L, P, V;
		cin >> L >> P >> V;

		if (L == 0)
			break;
		cout << "Case " << cnt << ": " << (V / P) * L + min(V % P, L) << "\n";
		cnt++;
	}
}