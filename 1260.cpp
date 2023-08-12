#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void visit(int n, int v, pair<int, int> p[])
{
    queue<int> q;
}

int main()
{
    int n, m, v; // 정점 개수, 간선 수, 시작 정점
    int x, y; // 간선 연결
  
    cin >> n >> m >> v;
    pair<int, int> p[m]; // pair배열을 이용해 간선연결 구현
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;  
        p[i] = make_pair(x, y); // 연결 삽입
    }
    visit(n, v, p);
    return (0);
}