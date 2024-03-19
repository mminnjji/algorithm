#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dp;

vector<vector<int>> makeTree(int n, vector<vector<int>> &links)
{
	vector<vector<int>> tree(n, vector<int>(0)); // 0만 들어있는 vector로 n개 초기
	for (int i = 0; i < links.size(); i++)
	{
		tree[links[i][0]].push_back(links[i][1]);
	}
	return tree;
}

int fillDp(vector<int> &sales, vecto<vector<int>> &tree, int node, bool flag)
{
	if (dp[node][flag] != -1)
}

int solution(vector<int> sales, vector<vector<int>> links) {
    dp.assign(sales.size() + 1, vector<int>(2, -1)); // true
	vector<vector<int>> tree = makeTree(sales.size() + 1, links); // 트리만들기
	return min(fillDp(sales, tree, 1, true), fillDp(sales, tree, 1, false));
}