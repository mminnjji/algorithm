#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[1001][1001];
int new_map[1001][1001];
int visited[1001][1001];

void reset_visit(int n, int m)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            visited[i][j] = 0;
    }
}

int check_way(int x, int y)
{
    int count = 0;
    int size;
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    while (1)
    {
        size = q.size();
        x = q.front().first;
        y = q.front().second;
        for(int i = 0; i < size; i++)
        {
            if (map[x][y] == 2)
                break;
            if (x - 1 >= 0 && map[x - 1][y] != 0 && !visited[x - 1][y])
                q.push(make_pair(x - 1, y));
            if (y - 1 >= 0 && map[x][y - 1] != 0 && !visited[x][y - 1])
                q.push(make_pair(x, y - 1));
            if (x + 1 < 1000 && map[x + 1][y] != 0 && !visited[x + 1][y])
                q.push(make_pair(x + 1, y));
            if (y + 1 < 1000 && map[x][y + 1] != 0 && !visited[x][y + 1])
                q.push(make_pair(x, y + 1));
            q.pop();
            visited[x][y] = 1;
        }
        count++;
    }
    return (count - 1);
}

void find_way(int n, int m)
{
    int x, y;

    x = 0;
    while (x < n)
    {
        y = 0;
        while (y < m)
        {
            reset_visit(n, m);
            new_map[x][y] = check_way(x, y);      
            y++;
        }
        x++;
    }
}

int main()
{
    int n, m;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    find_way(n, m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << new_map[i][j] << " ";
        }
      cout << "\n";
    }
    return (0);
}