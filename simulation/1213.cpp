#include <iostream>
#include <string>
using namespace std;

/*1213 펠린드롬만들기*/
/* 거지같은 문제임
팰린드롬같은걸 왜 사랑하는진 몰라도 사랑한다고함
그냥 대칭되나? 만 물으면 쉬울 것같은데
사전순으로 앞서는 문자열을 출력하라는걸 보면
문자열을 탐색할때에도 사전순으로 가장 작은걸 먼저 찾아야됨*/

int dictionary_first(string str, int len)
{
	int min = 'Z';
	int min_idx = -1;

	for (int i = 0; i < len; i++)
	{
		if (str[i] <= min)
		{
			min = str[i];
			min_idx = i;
		}
	}
	return (min_idx);
}

int find_char(string *str, char c, int n)
{
  int i = 0;

  while ((*str)[i])
    {
      if ((*str)[i] == c && i != n)
      {
        (*str)[i] = 91;
        return 1;
      }
      i++;
    }
  return 0;
}

void odd_str(string str, int len)
{
	int i;
	int	odd_num = 0;
	int idx = 0;
	char res[len];
	res[len - 1] = 0;
	while (1)
	{
		i = dictionary_first(str, len);
		if (i < 0)
		{
			cout << res;
			return ;
		}
		else if (find_char(&str, str[i], i))
		{
			res[idx] = str[i];
			res[len - idx - 1] = str[i];
			str[i] = 91;
			idx++;
		}
		else
		{
			if (!odd_num)
			{
				res[len / 2] = str[i];
				str[i] = 91;
				odd_num++;
				continue ;
			}
			cout << "I'm Sorry Hansoo";
			return ;
		}
	}
}

void even_str(string str, int len)
{
	int i;
	int idx = 0;
	char res[len];
	res[len - 1] = 0;
	while (1)
	{
		i = dictionary_first(str, len);
		if (i < 0)
		{
			cout << res;
			return ;
		}
		else if (find_char(&str, str[i], i))
		{
			res[idx] = str[i];
			res[len - idx - 1] = str[i];
			str[i] = 91;
			idx++;
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
	int len = 0;
	string str;

	cin >> str;
	while (str[len])
	{
		len++;
	}
	if (len % 2)
	{
		odd_str(str, len);
	}
	else
	{
		even_str(str, len);
	}
	return (0);
}