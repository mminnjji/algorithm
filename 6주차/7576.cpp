#include <iostream>
#include <queue>

using namespace std;

int toma[1001][1001];

int checkToma(int n, int m, int toma[][1001])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (toma[i][j] == 0)
                return (0);
        }
    }
    return (1);
}

void putToma(int n, int m, int toma[][1001], queue<pair<int, int>> *q)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (toma[i][j] == 1)
                q->push(make_pair(i, j));
        }
    }
}

void grow(int n, int m, int toma[][1001])
{
    queue<pair<int, int>> q;
    pair<int, int> tmp;
    int count = 0;
  
    putToma(n, m, toma, &q);
    if (!q.size())
    {
      cout << -1;
      exit(0);
    }
  
    if (checkToma(n, m, toma))
    {
      cout << 0;
      exit(0);
    }
  
    while (1)
    {
        int num = q.size();
        for (int i = 0; i < num; i++)
        {
            tmp = q.front();
            if (tmp.first > 0 && !toma[tmp.first - 1][tmp.second])
            {
                toma[tmp.first - 1][tmp.second] = 1;
                q.push(make_pair(tmp.first - 1, tmp.second));
            }
            if (tmp.first < n - 1 && !toma[tmp.first + 1][tmp.second])
            {
                toma[tmp.first + 1][tmp.second] = 1;
                q.push(make_pair(tmp.first + 1, tmp.second));
            }
            if (tmp.second > 0 && !toma[tmp.first][tmp.second - 1])
            {
                toma[tmp.first][tmp.second - 1] = 1;
                q.push(make_pair(tmp.first, tmp.second - 1));
            }
            if (tmp.second < m - 1 && !toma[tmp.first][tmp.second + 1])
            {
                toma[tmp.first][tmp.second + 1] = 1;
                q.push(make_pair(tmp.first, tmp.second + 1));
            }
            q.pop();
        }
        if (q.size() == 0)
          break;
        count++;
    }
  
    if (!checkToma(n, m, toma))
    {
      cout << -1;
      exit(0);
    }
  
    cout << count;
}

int main()
{
    int n, m;

    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> toma[i][j];
    }
    grow(n, m, toma);
}