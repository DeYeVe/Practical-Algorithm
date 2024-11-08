// https://www.acmicpc.net/problem/21276

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, string> root;
	unordered_map<string, set<string>> childs;
	unordered_map<string, int> indegree;
	int N, M;

	int tot = 0;
	set<string> roots;

	cin >> N;
	while (N--)
	{
		string s;
		cin >> s;
		root.insert({ s, s });
		indegree.insert({ s, 0 });

	}
	cin >> M;

	while (M--)
	{
		string c, p;
		cin >> c >> p;
		indegree[c]++;
		root[c] = root[p];
		childs[p].insert(c);
	}

	queue<string> Q;
	for (auto e : indegree)
	{
		if (e.second == 0)
		{
			Q.push(e.first);
			roots.insert(e.first);
		}
	}

	tot = Q.size();

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		vector<string> toErase;
		for (auto e : childs[cur])
		{
			root[e] = root[cur];
			if (--indegree[e] == 0)
			{
				Q.push(e);
			}
			else
			{
				toErase.push_back(e);
			}
		}
		for (auto e : toErase)
			childs[cur].erase(e);
	}

	cout << tot << "\n";

	vector<pair<string, set<string>>> s_childs; 
	for (auto e : childs)
		s_childs.push_back(e);
	sort(s_childs.begin(), s_childs.end());

	for (auto e : roots)
		cout << e << " ";
	cout << "\n";

	for (auto e : s_childs)
	{
		cout << e.first << " " << e.second.size() << " ";
		for (auto ee : e.second)
			cout << ee << " ";
		cout << "\n";
	}
}