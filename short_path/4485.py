# 4485 나는야 젤다가 아닌 링크
# 다익스트라 알고리즘 - 각 노드를 연결했을 때의 최소값
# 다익스트라란? - 인접 노드를 갔을때... 최단경로를 저장 -> 최단경로를 방문 <주변노드 업데이트> -> 최단경로 방문 반복

import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def short_path():
	q = []
	heapq.heappush(q, (board[0][0], 0, 0))
	distance[0][0] = 0
	
	while q:
		cost, x, y = heapq.heappop(q)
		if x == n - 1 and y == n - 1:
			print(f'Problem {count}: {distance[x][y]}')
			break
		for i in range(4):
			nx = x + dx[i]
			ny = y + dy[i]

			if 0 <= nx < n and 0 <= ny < n:
				ncost = cost + board[nx][ny]
				if ncost < distance[nx][ny]:
					distance[nx][ny] = ncost
					heapq.heappush(q, (ncost, nx, ny))

count = 1
while 1:
	n = int(input())
	if n == 0:
		break
	board = [list(map(int, input().split())) for _ in range(n)]
	distance = [[INF] * n for _ in range(n)]
	short_path()
	count += 1