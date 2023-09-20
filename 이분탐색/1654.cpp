#include <iostream>
#include <algorithm>

using namespace std;

int ren[10000];

int main()
{
    unsigned int k, n, right, left, mid;
    unsigned int res;
  
    left = 1;
    cin >> k >> n;
    res = 0;
    cin >> ren[0];
    right = ren[0];
  
    for (int i = 1; i < k; i++)
    {
        cin >> ren[i];
        if (ren[i] > right)
          right = ren[i];
    }
  
    while (left <= right)
    {
        unsigned int sum = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < k; i++)
            sum += ren[i] / mid;
        if (sum >= n)
        {
            left = mid + 1;
            res = max(res, mid);
        }
        else
            right = mid - 1;
    }
    cout << res;
}