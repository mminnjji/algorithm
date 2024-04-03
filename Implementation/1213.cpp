#include <iostream>
#include <string>
using namespace std;

/*1213 펠린드롬만들기*/

// 사전 순으로 가장 빠른 알파벳 탐색
int dictionary_first(string str)
{
	int min = 91;
	int min_idx = -1;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] <= min)
		{
			min = str[i];
			min_idx = i;
		}
	}
	return (min_idx);
}

//문자열에서 현재 인덱스 제외 인덱스 중 문자 있는지 탐색
int find_char(string *str, char c, int n)
{
  int i = 0;

  while ((*str)[i])
    {
      if ((*str)[i] == c && i != n)
      {
        (*str)[i] = 92;
        return 1;
      }
      i++;
    }
  return 0;
}

// 홀수일때
void odd_str(string str)
{
	int i;
	int odd = 0;
	string part1 = "", part2 = "", part3 = "";
	while (1)
	{
		i = dictionary_first(str);
		if (i < 0)
		{
			cout << part1 << part2 << part3;
			return ;
		}
		else if (find_char(&str, str[i], i))
		{
			part1 += str[i];
			part3 = str[i] + part3;
			str[i] = 92;
		}
		else
		{
			if (!odd) // 알파벳 탐색 실패시 -> 가운데 넣기 + 플래그 세우기
			{
				part2 = str[i];
				str[i] = 92;
				odd = 1;
			}
			else
			{
				cout << odd << i << "I'm Sorry Hansoo";
				return ;
			}
		}
	}
}

//짝수일때
void even_str(string str)
{
	int i;
	string part1 = "", part2 = "", part3 = "";
	while (1)
	{
		i = dictionary_first(str); // 가장 빠른 알파벳 탐색
		if (i < 0)  // 전체 문자열 탐색 완료 
		{
			cout << part1 << part2 << part3;
			return ;
		}
		else if (find_char(&str, str[i], i))
		{
			part1 += str[i];
			part3 = str[i] + part3;
			str[i] = 92;
		}
		else
		{
			cout << "I'm Sorry Hansoo";
			return ;
		}
	}
}


int main()
{
	string str;

	cin >> str;
	if (str.size() % 2)
	{
		odd_str(str);
	}
	else
	{
		even_str(str);
	}
	return (0);
}