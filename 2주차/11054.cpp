#include <iostream>
#include <vector>

using namespace std;

void findLess(vector<int> list, int less[])
{
    int max;

    less[0] = 0;
    for (int i = 1; i < list.size(); i++)
    {
        max = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (list[j] < list[i])
            {
                if (max <= less[j])
                    max = less[j] + 1;
            }
        }
        less[i] = max; 
    }
}

void findMore(vector<int> list, int more[])
{
    int max;

    more[list.size() - 1] = 0;
    for (int i = list.size() - 2; i >= 0; i--)
    {
        max = 0;
        for (int j = i + 1; j < list.size(); j++)
        {
            if (list[j] < list[i])
            {
                if (max <= more[j])
                    max = more[j] + 1;
            }
        }
        more[i] = max; 
    }
}

void search(vector<int> list, int n)
{
    int less[n];
    int more[n];
    int max;

    max = 0;
    findLess(list, less);
    findMore(list, more);
    for(int i = 0; i < list.size(); i++)
    {
        if (max <= less[i] + more[i])
            max = less[i] + more[i];
    }
    cout << max + 1;
}

int main() 
{
    int n, tmp;
    vector<int> list;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        list.push_back(tmp);
    }
    search(list, n);
    return 0;
}
