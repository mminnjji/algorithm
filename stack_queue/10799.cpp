/*10799 쇠막대기*/
/*
뭐야? 싶은 얼탱없는 문제
걍 쇠막대기가 있고, 레이저가 있을 때
레이저의 위치와,, 쇠막대기의 위치를 파악해서 
쇠막대기가 총 얼마만큼 쪼개지는 지를 찾는 문제
*/

/* 
쇠막대기가 열리고 닫히는 지점 => make_pair 로 해야할까?
-> 할 수 없음 - 언제 열리고 닫히는지 모름!!
대신에 스택을 쌓으면 좋을 것 같긴한데 어떤방식?
만약에,, 쇠막대기의 열림/닫힘이 스택으로 쌓여있을 때 하나씩 꺼내다가 레이저가 나올 때 => 잘림 => 또 나올 때 => 지금까지 나온 것이 한번 더 더해짐 
그럼 수세기 + 닫힐때 수 감소시키기를 통하여 할 수 있을듯?
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int i = 0;
	int num = 0;
	int ray[100000] = {0,};
	int res = 0;
	string str;
	stack<int> stk;
	stack<int> tmp;
	// pop 하면서 짝을 찾기 전까지의 레이저 갯수를 파악하면 됨
	 
	// 스택 두개 가지고 있다가 하면 될듯! => 순회 시간이 너무너무너무넘 오래걸림


	cin >> str;
	while (str[i])
	{
		if (str[i] == '(' && str[i + 1] != ')')
			stk.push(0);
		else if (str[i] == ')' && (i == 0 || (i >= 0 && str[i - 1] != '(')))
			stk.push(1);
		else if (str[i] == '(' && str[i + 1] == ')')
		{
			stk.push(2);
			i++;
		}
		i++;
	}
	while (!stk.empty())
	{
		if (stk.top() == 1)
		{
			stk.pop();
			num++;
		}
		else if (stk.top() == 0)
		{
			stk.pop();
			res = res + ray[num] + 1;
			ray[num] = 0;
			num--;
		}
		else if (stk.top() == 2)
		{
			stk.pop();
			for (int i = 0; i <= num; i++)
				ray[i]++;
		}
	}
	cout << res;
	return (0);
}
