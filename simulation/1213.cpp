#include <iostream>
#include <string>
using namespace std;

/*1213 펠린드롬만들기*/

int dictionary_first(string str)
{
	char min = 91;
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

void odd_str(string str)
{
	int i;
	int	odd_num = 0;
	int idx = 0;
	char res[str.size()];
	res[str.size() - 1] = 0;
	while (1)
	{
		i = dictionary_first(str);
		if (i < 0)
		{
			cout << res;
			return ;
		}
		else if (find_char(&str, str[i], i))
		{
			res[idx] = str[i];
			res[str.size() - idx - 1] = str[i];
			str[i] = 91;
			idx++;
		}
		else
		{
			if (!odd_num)
			{
				res[str.size() / 2] = str[i];
				str[i] = 91;
				odd_num++;
				continue ;
			}
			cout << "I'm Sorry Hansoo";
			return ;
		}
	}
}

void even_str(string str)
{
	int i;
	int idx = 0;
	char res[str.size()];
	res[str.size() - 1] = 0;
	while (1)
	{
		i = dictionary_first(str);
		if (i < 0)
		{
			cout << res;
			return ;
		}
		else if (find_char(&str, str[i], i))
		{
			res[idx] = str[i];
			res[str.size() - idx - 1] = str[i];
			str[i] = 91;
			idx++;
		}
		else
		{
			cout << i << "I'm Sorry Hansoo";
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