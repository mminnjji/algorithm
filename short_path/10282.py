# 10282 해킹
# 의존하고 있는 컴퓨터들이 전염 -> 걸리는 시간?
# 근데 이거 floyd-wassel로 푸는게 낫지 않나?
# 수가 너무 큼 - 근데 만약에 다익스트라로 한다면 -> 어차피 힙큐에 들어오는 애들은 다 감염되는 친구들임 -> 힙큐에서 마지막으로 참조되는 친구(가장 거리가 먼 친구겠죠)
import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)

def short_path():
	q = []
	heapq.heappush(q, (0, num))
	arr[num] = 0
	while q:
		s, x = heapq.heappop(q)
		for k in range(pc):
			if board[x][k] != -1:
				new_s = arr[x] + board[x][k]
				if new_s < arr[k]:
					arr[k] = new_s
					heapq.heappush(new_s, k)

n  = int(input())

for i in range(n):
	pc, dist, num = map(int, input().split())
	arr = [INF * pc]
	board = [-1 * n for _ in range(pc)]
	for j in range(pc):
		x, y, s = map(int, input().split())
		board[x][y] = s
	short_path()
