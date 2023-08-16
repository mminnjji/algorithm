#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getMaxWay(vector<vector<int>> trg, int n)
{
    int max;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j - 1 >= 0 && j + 1 <= i)
            {
                trg[i][j] += trg[i - 1][j - 1] > trg[i - 1][j] ? trg[i - 1][j - 1] : trg[i - 1][j];
            }
            else if (j - 1 < 0)
                trg[i][j] = trg[i - 1][j] + trg[i][j];
            else if (j + 1 > i)
                trg[i][j] = trg[i - 1][j - 1] + trg[i][j];
        }
    }
    max = *max_element(trg[n - 1].begin(), trg[n - 1].end());
    cout << max;
}

int main()
{
    int n, tmp;
    vector<int> buf;
    vector<vector<int>> trg;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> tmp;
            buf.push_back(tmp);
        }
        trg.push_back(buf);
        buf.clear();
    }
    getMaxWay(trg, n);
    return 0;
}