// https://www.acmicpc.net/problem/17478

#include <bits/stdc++.h>
using namespace std;

void print_indent(int depth)
{
	for (int i = 0; i < depth; ++i)
		cout << "____";
}

void func(int n, int depth)
{
	if (depth == 0)
		cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

	print_indent(depth);
	cout << "\"����Լ��� ������?\"\n";

	if (n == 0)
	{
		print_indent(depth);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else
	{
		print_indent(depth);
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		print_indent(depth);
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		print_indent(depth);
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		func(n - 1, depth + 1);
	}
	print_indent(depth);
	cout << "��� �亯�Ͽ���.\n";

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	func(n, 0);
}