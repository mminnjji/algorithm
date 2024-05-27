# 2110 공유기 설치

import sys
input = sys.stdin.readline


n, c = map(int,input().split())
house = []
for i in range(n):
	house.append(int(input()))

house.sort()
start = 1
end = house[-1] - house[0]
while start <= end:
	mid = (start + end) // 2
	cnt = 1
	curr = house[0]
	for i in range(1, len(house)):
		if house[i] >= curr + mid:
			cnt += 1
			curr = house[i]
	if cnt >= c:
		start = mid + 1
	else:
		end = mid - 1

print(end)
