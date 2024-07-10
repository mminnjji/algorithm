import sys
import heapq
input = sys.stdin.readline

# 날짜를 뒤에서부터 생각한다고 해보자...

n = int(input())
if n == 0:
	print(0)
else:
	univ = []
	for _ in range(n):
		a, b = map(int, input().split())
		univ.append([b, a])

	univ.sort(reverse=True)

	# 그 날짜에 할 수 있는 친구들이란....? - 기한이 지금 날짜보다 큰 친구들
	# 그 친구들 중에 큰거 찾기 - 딜리트하기
	# 반복하기  
	curr_date = max(map(lambda x:x[0], univ))
	result = 0
	while curr_date:
		today = []
		for i in range(len(univ)):
			if curr_date <= univ[i][0]:
				heapq.heappush(today, [-univ[i][1], i])
		if today:
			cost, day = heapq.heappop(today)
			result += -cost
			del univ[day]
		curr_date -= 1

	print(result)
		
