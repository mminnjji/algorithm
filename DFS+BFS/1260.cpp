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
    			DFS(tmp, visited, graph);
  	}
}
 
void BFS(int v, bool visited[], vector<int> graph[])
{
  	queue<int> q;
    int tmp;
  
  	q.push(v);
  	visited[v] = true;

  	while (!q.empty())
    {
    		tmp = q.front();
    		q.pop();
    		cout << tmp << " ";
    		for (int i = 0; i < graph[tmp].size(); i++)
    		{
      			if (visited[graph[tmp][i]] == false) {
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
    
    for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());
 
    resetVisit(visited, n);
    DFS(v, visited, graph);
    cout << '\n';
    resetVisit(visited, n);
    BFS(v, visited, graph);
    return 0;
}