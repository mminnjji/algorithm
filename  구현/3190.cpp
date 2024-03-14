/*3190 뱀*/
/* 발상
일단 맵을 저장하는 배열/벡터가 존재해야함
사과가 있는 곳 == 1 없는 곳 == 0
뱀의 정보를 담고있는 구조체 
- 뱀의 위치, 뱀의 방향, 뱀의 길이 이정도
뱀은 매 초마다 이동을 한다네요 => 걍 회차라고 생각하겠음
-> 3 D 라면, 3회차때 D 방향 (오른쪽) 으로 이동 
우리는 기준을 상/하/좌/우 로 둡시다
그리고 각 상황에서 왼/오로 튼다고 했을 떄 어떻게 방향전환이 되는지 정도를 
기억하고 있으면 좋을 것 같네
맵에 뱀이 있는지 없는지 확인하는 값으로 2를 놓으면 좋겠고
움직였는데 2다? => out 이런 느낌
조금 편하게 하려면 어차피 뱀은 1칸씩 움직이고 있기 때문에 
맵 자체의 벽도 3으로 처리해주면 이지하다
*/

#include <iostream>
#include <deque>

using namespace std;
// 벰 구조체 없고, 걍 배열 탐색하면서 봐도 될 것 같은데?

void	snake_move(int board[150][150], int n, int d)
{
	int flag = count = 0;
	int i = j = 1;
	int	dc;
	char dir;
	deque<pair<int, int>> snake;
	snake.push_back(make_pair(1, 1));
	cin >> dc >> dir;
	int dcount = 1;
	while (1)
	{
		if (count == dc)
		{
			if (dir == 'L')
				flag--;
			else if (dir == 'D')
				flag++;
			if (flag < 0)
				flag = 3;
			else if (flag > 3)
				flag = 0;
			if (dcount != d)
			{
				cin >> dc >> dir;
				dcount++;
			}
		}
		// 방향 검사해서 flag 업데이트 해주
		if (flag == 0 || flag == 2)
			j = j + (flag == 0) * 2 - 1;
		else if (flag == 1 || flag == 3)
			i = i - (flag == 1) * 2 + 1;
		if (board[i][j] == 3 || board[i][j] == 2)
			break;
		else if (board[i][j] == 0)
		{
			board[snake.front().fisrt][snake.front().second] = 0;
			snake.pop_front;
			snake.push_back(make_pair(i)(j));
		}
		else if (board[i][j] == 1)
		{
			snake.push_back(make_pair(i)(j));
		}
		count++;		
	}
	cout << count;
}

int main()
{
	int n, a, ar, ac, d;
	cin >> n;
	int board[150][150];
	board = (void )
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
				board[i][j] = 3;
			else if	(i == 1 && j == 1)
				board[i][j] = 2;
			else
				board[i][j] = 0;
		}
	}
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> ar >> ac;
		board [ar][ac] = 1;
	}
	cin >> d;
	snake_move(board, n, d);
}