# 가방에 대해서 훔칠 수 있는지 판별 -> 가치를 기준으로 -> 
# 무게가 작은 가방에서부터 판별한다면, 최대의 보석을 저장할 수 있음. 

import sys
import heapq
input = sys.stdin.readline

n,k = map(int,input().split())

jewel = [[*map(int, input().split())] for _ in range(n)]
bag = [int(input()) for _ in range(k)]

jewel.sort()
bag.sort()

result = 0
tmp = [] 
 
for i in bag:
    while jewel and jewel[0][0] <= i:
        heapq.heappush(tmp, -jewel[0][1])
        heapq.heappop(jewel)
    if tmp:
        result -= heapq.heappop(tmp)

print(result)