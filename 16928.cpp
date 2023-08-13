#include <iostream>
#include <queue>

using namespace std;

int dice(queue<int> *q, int n, bool visited[], int obst[])
{
    // 종료조건
    if (n == 99 || n == 98 || n == 97 || n == 96 || n == 95 || n == 94)
        return (1);
    // 장애물 방문 -> 그 위치로 이동 / 방문 기록
    if (n + 1 < 100 && visited[obst[n + 1]] == false)
    {
        q->push(obst[n + 1]);
        visited[obst[n + 1]] = true;
    }
    if (n + 2 < 100 && visited[obst[n + 2]] == false)
    {
        q->push(obst[n + 2]);
        visited[obst[n + 2]] = true;
    }
    if (n + 3 < 100 && visited[obst[n + 3]] == false)
    {
        q->push(obst[n + 3]);
        visited[obst[n + 3]] = true;
    }
    if (n + 4 < 100 && visited[obst[n + 4]] == false)
    {
        q->push(obst[n + 4]);
        visited[obst[n + 4]] = true;
    }
    if (n + 5 < 100 && visited[obst[n + 5]] == false)
    {
        q->push(obst[n + 5]);
        visited[obst[n + 5]] = true;
    }
    if (n + 6 < 100 && visited[obst[n + 6]] == false)
    {
        q->push(obst[n + 6]);
        visited[obst[n + 6]] = true;
    }
    return (0);
}

void initObst(int obst[])
{
    for (int i = 0; i < 101; i++)
    {
        obst[i] = i; // 장애물이 아닌 자리의 값들을 해당 값으로 채움
    }
}

void BFS(int obst[])
{
    bool visited[101]; // 방문여부 
    queue<int> q;
    int flag = 1;
    int size;
    int count = 0;

    q.push(1);
    fill(visited, visited + 101, false); // 초기화
    visited[1] = true;
    while (flag)
    {
        size = q.size();
        count++; // 노드에서 탐색을 1회 마칠 때 증가
        for (int i = 0; i < size; i++)
        {
            if (dice(&q, q.front(), visited, obst)) // q의 front부터 탐색
            {
                flag = 0;
                break;
            }
            q.pop();
        }
    }
    cout << count;
}

int main()
{
    int obst[101]; // 장애물 위치 및 이동 위치 표기
    int n, m;
    int x, y;
    cin >> n >> m;
    initObst(obst);
    for (int i = 0; i < n + m; i++) 
    {
        cin >> x >> y;
        obst[x] = y; // x위치에 이동시 y위치로 이동
    }
    BFS(obst);
}
