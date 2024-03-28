/* 백트래킹이란
- 흔히 사용하는 dfs+bfs 탐색시 결과값이 틀릴경우, 
이전단계로 되돌아가 결과를 수행하는 것
-dfs 와 재귀함수로 구성하면 편리하게 구현할 수 있음. 
*/

/*2580 스도쿠*/
/*
발상 : dfs 사용 + 이전단계 기억하기
=> 각 칸에 해당하는 경우의 수를 기억 -> 연결리스트로 저장하고 
=> 각 칸의 정보는 배열에 들어있고, 빈 칸의 경우 값을 0으로 저장함
=> 연결리스트의 정보는 각 행/열을 기준으로 함
=> 배열을 검사하고, 가능한 정보를 0~8 의 인덱스를 가진 연결리스트에 이진으로 저장함
=> 반복문으로 내부에서 가능한 결과값을 발견했을 경우 바로 리턴하며 초기 함수로 돌아옴
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int search_success(int num, int row, int col, int rule[9][9])
{
    int check_row[2];
    int check_col[2];

    // 작은 사각형 기준 검사해야하는 파트 선정
    if (row % 3 == 0)
    {
        check_row[0] = row + 1;
        check_row[1] = row + 2;
    }
    else if (row % 3 == 1)
    {
        check_row[0] = row - 1;
        check_row[1] = row + 1;
    }
    else if (row % 3 == 2)
    {
        check_row[0] = row - 1;
        check_row[1] = row - 2;
    }

    if (col % 3 == 0)
    {
        check_col[0] = col + 1;
        check_col[1] = col + 2;
    }
    else if (col % 3 == 1)
    {
        check_col[0] = col - 1;
        check_col[1] = col + 1;
    }
    else if (col % 3 == 2)
    {
        check_col[0] = col - 1;
        check_col[1] = col - 2;
    }

    // 행/열 검사
    for(int i = 0; i < 9; i++)
    {
        if (rule[col][i] == num)
            return 1;
    }
    for(int i = 0; i < 9; i++)
    {
        if (rule[i][row] == num)
            return 1;
    }
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if (rule[check_col[i]][check_row[j]] == num)
                return 1;
        }
    }

    return 0;
}

typedef struct p_node
{
    struct p_node   *prev;
    int             row;
    int             col;
    struct p_node   *next;
} t_node;


t_node  *init_node(t_node *prev, int col, int row)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    node->prev = prev;
    node->row = row;
    node->col = col;
    node->next = NULL;
    return (node);
}

t_node  *set_node(int rule[9][9])
{
    t_node *start;

    start = NULL;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if (rule[i][j] == 0)
            {
                if (!start)
                    start = init_node(NULL, i, j);
                else
                {
                    start->next = init_node(start, i, j);
                    start = start->next;
                }
            }
        }
    }
    while (start->prev)
    {
        start = start->prev;
    }
    return (start);
}

int sudoku(int rule[9][9], t_node *curr)
{
    int flag = 0, res;

    for(int i = 1; i < 10; i++)
    {
        if (!search_success(i, curr->row, curr->col, rule))
        {
            rule[curr->col][curr->row] = i;
            if (!curr->next)
                return (3);
            res = sudoku(rule, curr->next);
            if (res == 1)
            {
                //cout << "error:" << rule[curr->col][curr->row] <<"\n";
                rule[curr->col][curr->row] = 0;
            }
            if (res == 3)
                return (3);
        }
    }
    return (1);
    // 결과를 체크해주는 배열도 필요함. 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int     rule[9][9];
    t_node  *node;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> rule[i][j];
        }
    }
    node = set_node(rule);
    sudoku(rule, node);
    //cout << "\n\n";
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << rule[i][j];
            if (j != 8)
                cout << ' ';
        }
            cout << '\n';
    }
    return 0;
}