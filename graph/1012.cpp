#include <iostream>

using namespace std;

void DFS(int map[51][51], int x, int y)
{
  if (x - 1 >= 0 && map[x - 1][y] == 1)
  {
    map[x - 1][y] = 0;
    DFS(map, x - 1, y);
  }
  if (y - 1 >= 0 && map[x][y - 1] == 1)
  {
    map[x][y - 1] = 0;
    DFS(map, x, y - 1);
  }
  if (x + 1 < 50 && map[x + 1][y] == 1)
  {
    map[x + 1][y] = 0;
    DFS(map, x + 1, y);
  }
  if (y + 1 < 50 && map[x][y + 1] == 1)
  {
    map[x][y + 1] = 0;
    DFS(map, x, y + 1);
  }
}
 
int search(int map[51][51], int m, int n)
{
    int count = 0;
  
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (map[i][j] == 1)
            {
                DFS(map, i, j);
                count++;
            }
        }
    }
    return count;
}


void mapInit(int map[51][51])
{
    for(int i = 0; i <= 50; i++)
    {
        for(int j = 0; j <= 50; j++)
        {
            map[i][j] = 0;
        }
    }
}

int main() 
{
    int t, m, n, k; // 테스트 수, 가로길이, 세로길이, 배추수
    int x, y; // 배추 좌표
    int count;
    int map[51][51];
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> k;
        mapInit(map);
        while (k--)
        {
            cin >> x >> y;
            map[x][y] = 1;
        }
        count = search(map, m, n);
        cout << count << "\n";
    }
    return 0;
}