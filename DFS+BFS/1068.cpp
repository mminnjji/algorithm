#include <iostream>
#include <vector>

using namespace std;

void DFS(int tmp, vector<int> tree[], int count)
{
    for (int i = 0; i < tree[tmp].size(); i++)
    {
        count++;
        DFS(tree[tmp][i], tree, count);
    }
    cout << "이거야! : " << count << "\n";
}

int main()
{
    vector<int> tree[51];
    int n, tmp, count;

    cin >> n >> tmp;
    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        tree[tmp].push_back(i);
    }
    cin >> tmp;
    count = 1;
    DFS(tmp, tree, count);
}