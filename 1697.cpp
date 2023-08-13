#include <iostream>
#include <queue>

using namespace std;
int push(queue<int> *q, int n, int k, bool checklist[])
{
    if (n * 2 == k || n - 1 == k || n + 1 == k)
        return (1);
    if (n * 2 < 100001 && checklist[n * 2] == false)
    {
        q->push(n * 2);
        checklist[n * 2] = true;
    }
    if (n + 1 < 100001 && checklist[n + 1] == false)
    {
        q->push(n + 1);
        checklist[n + 1] = true;
    }
    if (n - 1 >= 0 && checklist[n - 1] == false)
    {
        q->push(n - 1); 
        checklist[n - 1] = true;
    }
    return (0);
}


void BFS(int k, queue<int> q)
{   
    bool checklist[100001]; // 방문했는지 확인
    int count = 0;
    int size;
    int flag = 1;
    if (q.front() == k)
    {
        cout << 0;
        return;
    }
    fill(checklist, checklist + 100001, false); // 초기화
    while (flag)
    {
        size = q.size();
        count++; // 노드에서 탐색을 1회 마칠 때 증가
        for (int i = 0; i < size; i++)
        {
            if (push(&q, q.front(), k, checklist))
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
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    int n, k; // 수빈이의 위치, 동생의 위치
    queue<int> q;
  
    cin >> n >> k;
    q.push(n); // 큐에 미리 n넣고 시작
    BFS(k, q);
    return 0;
}