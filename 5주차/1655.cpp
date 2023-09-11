#include <iostream>
#include <vector>
#include <queue>
// BOJ 1655
using namespace std;

priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

int main(void)
{
	int n, tmp;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
    {
		cin >> tmp;
        // 0 1 의 경우 최소 max/min 힙의 개수가 1개가 되도록 예외
		if (i == 0) 
			maxheap.push(tmp);
		else if (i == 1)
        {
			if (tmp > maxheap.top())
				minheap.push(num);
			else {
				minheap.push(maxheap.top());
				maxheap.pop();
				maxheap.push(tmp);
			}
		}
        // max 힙에 넣어 정렬된 후, 상단 값끼리 비교하여 개수 맞춤
		else
        {
			maxheap.push(tmp);
			if (maxheap.top() > minheap.top())
            {
				maxheap.pop();
				minheap.push(num);
				if (minheap.size() > maxheap.size())
                {
					maxheap.push(minheap.top());
					minheap.pop();
				}
			}
			if (maxheap.size() - minheap.size() > 1)
            {
				minheap.push(maxheap.top());
				maxheap.pop();
			}
		}
		cout << maxheap.top() << '\n';
	}
	return 0;
}