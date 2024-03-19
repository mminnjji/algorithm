#include <iostream>
#include <vector>

using namespace std;

int visited[10] = {0,};
int min_val = 10000000; 

void backtrack(int n, int cnt, int curr, int cost, vector<vector<int>> &city)
{
	if (cost >= min_val)
		return;
	if (cnt == n)
	{
		//출발도시로 돌아오기 가능한지 확인
		if (city[curr][0] != 0)
			min_val = min(min_val, cost + city[curr][0]);
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (city[curr][i] && !visited[i])
		{
			visited[i] = 1;
			backtrack(n, cnt + 1, i, cost + city[curr][i], city);
			visited[i] = false;
		}
	}
}
// 근데 dp를 사용하기에는 너무 모든걸 순회해야하지 않나?
int solution(int n, vector<vector<int>> &city)
{
	visited[0] = 1;
	//1번도시에서 출발하여 원순회를 하기를 원함
	//1번도시에 방문했다는 flag를 세우고 시작함
	backtrack(n, 1, 0, 0, city);
	return min_val;
}

int main()
{
	int n;
	vector<vector<int>> cost;
	int answer;

	//입력
	cin >> n;
	cost.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	answer = solution(n, cost);

	//출력
	cout << answer;
	return 0;
}