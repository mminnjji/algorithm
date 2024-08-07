import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline
#상 하 좌 우
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def sink_DFS(x, y, h):
    for m in range(4):
        nx = x + dx[m]
        ny = y + dy[m]
        if (0 <= nx < N) and (0 <= ny < N) and not sink_table[nx][ny] and land[nx][ny] > h:
            sink_table[nx][ny] = True
            sink_DFS(nx, ny, h)


N = int(input())
land = [list(map(int, input().split())) for _ in range(N)]

ans = 1
for k in range(max(map(max, land))):
    sink_table = [[False]*N for _ in range(N)]
    count = 0
    for i in range(N):
        for j in range(N):
            if land[i][j] > k and not sink_table[i][j]:
                count += 1
                sink_table[i][j] = True
                sink_DFS(i, j, k)
    ans = max(ans, count)

print(ans)