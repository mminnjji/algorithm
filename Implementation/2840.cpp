#include <iostream>
#include <vector>

using namespace std;

int find_str(char real[], char c, int i, int n)
{
	if (c == '?')
		return 1;
	for (int j = 0; j < n; j++)
	{
		if (real[j] == c && j != i)
			return 0;
	}
	return 1;
}

void solution(int n, int k, vector<pair<int, char>> circle)
{
	// 돌아갔을 때의 인덱스를 기억하고, 넣으면 됨
	char real[n];
	int idx = 0;
	vector<char> comeon;

	for (int i = 0; i < n; i++)
	{
		real[i] = '?';
	}
	for (int i = 0; i < circle.size(); i++)
	{
		idx = (idx + circle[i].first) % n;
		if (real[idx] == '?' || real[idx] == circle[i].second)
			real[idx] = circle[i].second;
		else
		{
			cout <<'!';
			return ;
		}
	}
	for (int i = n; i >= 1; i--)
	{
		if (!find_str(real,real[(idx + i) % n], (idx + i) % n, n))
		{
			cout <<'!';
			return ;
		}
	}
	for (int i = n; i >= 1; i--)
	{
		cout << real[(idx + i) % n];
	}
}

int main()
{
	int n, k, s;
	char c;
	vector<pair<int, char>> circle;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> s >> c;
		circle.push_back(make_pair(s, c));
	}
	solution(n, k, circle);
}