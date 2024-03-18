/* 10971 외판원 순회2*/
/*
발상 = 생각나는게 없음 
전체 순회 하는게 오히려 빠르지 않나 라는 생각이 들음 ㅋㅋ*/
#include <iostream>
#include <vector>

using namespace std;

int short_search(int i, int city[12][12], int n)
{
	//n이 10개이기 때문에 아무리 많아도,, 10! 정도 아닐까?
	//10! 이면 개많잖아
	
	vector<int> visit;
	for (int i = 0; i < n; i++)
	{
		visit.push_back(0);
	}
	for (int i = 0; i < n; i++)
	{
		
	}
	
}

void city_search(int city[12][12], int n)
{
	int sum = 2147483647;
	// 아 진짜 어렵넹 ;;
	// 그냥 순회하면 될 것 같다가도,, 아닐 것 같다는 느낌이 들음
	for (int i = 0; i < n; i++)
	{
		if (sum >= short_search(i))
			sum = short_search(i, city, n);
	}
	cout << sum;
}


int main()
{
	int n;
	int city[12][12];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> city[i][j];
		}
	}
	city_search(city, n);
}