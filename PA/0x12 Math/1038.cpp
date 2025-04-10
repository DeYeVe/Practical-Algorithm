//https://www.acmicpc.net/problem/1038

#include <bits/stdc++.h>
using namespace std;


void func(int digit, long long place, long long num, vector<long long> &v)
{
	v.push_back(num);
	
	for(int i = digit + 1; i <= 9; i ++)
		func(i, place * 10, num + i * place * 10, v);

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int N;
	cin >> N;

	vector<long long> v;
	for(int i = 0; i<= 9; i++)
		func(i,1,i,v);

	sort(v.begin(), v.end());
	if (v.size() <= N)
		cout << -1;
	else
		cout << v[N];
}