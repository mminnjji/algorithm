#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int get_integer_len(int n)
{
    int count = 0;
    int i = 10;
    while (n)
    {
        n = n / i;
        i = i * 10;
        count++;
    }
    return (count);
}


int solution(string s) {
    int min = s.size();
    int len = min;
    
    char str[len];
    for (int i = 0; i < len; i++)
    {
        str[i] = s[i];
    }
    for (int i = 1; i < len; i++)
    {
        int n = 0; // 비교해야 하는 것 => n * i 와 (n + 1) * i 번째 배열을 n 만큼 비교했을 때 같은지
        int count = 1;
        int sum = len % i;
        while ((n + 1) * i <= len)
        {
            if (!strncmp(str + n * i, str + n * i + i, i))
                count++;
			else
            {
                if (count != 1)
                    sum += (get_integer_len(count) + i);
				else
                	sum += i;
                count = 1;
            }
            n++;
        }
        if (sum < min)
            min = sum;
    }
    return min;
}

int main()
{
	string str;
	str = "xababcdcdababcdcd";

	cout << solution(str);
}