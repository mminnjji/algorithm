#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void acm()
{
    int n, k, x, y, w;
    int d[1002];
    vector<int> rule[1002];
    int result[1002];
    int visited[1002] = {0, };
    queue<int> q;

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        rule[x].push_back(y);
        visited[y]++;
    }
    cin >> w;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            q.push(i);
        result[i] = d[i];
    }
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < rule[cur].size(); i++)
        {
            int next = rule[cur][i];
            visited[next]--;
            result[next] = max(result[next], result[cur] + d[next]);

            if (visited[next] == 0)
            {
                q.push(next);
            }
        }
    }

    cout << result[w] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        acm();
    }
    return (0);
}