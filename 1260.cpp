#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 1001
 
void DFS(int v, bool visited[], vector<int> graph[])
{
    int tmp;
  
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < graph[v].size(); i++)
  	{
    		tmp = graph[v][i];
    		if (visited[tmp] == false)
    			DFS(tmp, visited, graph); // 재귀 -> 방문 노드의 그 다음노드로 연결
  	}
}
 
void BFS(int v, bool visited[], vector<int> graph[])
{
  	queue<int> q;
    int tmp;
  
  	q.push(v); // 큐에 삽입하고 삭제하는 방식
  	visited[v] = true;

  	while (!q.empty())
    {
    		tmp = q.front();
    		q.pop();
    		cout << tmp << " ";
    		for (int i = 0; i < graph[tmp].size(); i++)
    		{
      			if (visited[graph[tmp][i]] == false) { // 노드 방문하여 확인
        				q.push(graph[tmp][i]);
        				visited[graph[tmp][i]] = true;
      			}
    		}
  	}
}

void resetVisit(bool visited[], int n) {
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
}
 
int main() 
{
    int n, m, v; // 정점 개수, 간선수, 시작정점
    int x, y; // 정점 기록
    vector<int> graph[MAX];
    bool visited[MAX]; //정점 방문 여부

    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        //양방향 연결
        graph[x].push_back(y);
		graph[y].push_back(x);
    }
    
    /* 연결된 정점을 크기순으로 나열 -> 작은 값부터 탐색*/
    for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

    resetVisit(visited, n);// false로 초기화
    DFS(v, visited, graph);
    cout << '\n';
    resetVisit(visited, n);
    BFS(v, visited, graph);
    return 0;
}