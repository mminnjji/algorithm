# 신종 바이러스인 웜 바이러스....
# 네트워크 상에 있는 녀석들은 바이러스에 감염된다 ㄷㄷ

n = int(input())
network = [[] for _ in range(n)]
visited = [0] * n

visited[0] = 1

def comeandvisit(i):
	global network
	global visited

	visited[i] = 1
	for j in range(len(network[i])):
		if visited[network[i][j]] == 0:
			comeandvisit(network[i][j])

m = int(input())

for i in range(m):
	a,b = map(int, input().split())
	network[a - 1].append(b - 1)
	network[b - 1].append(a - 1)


total = 0
for i in range(len(network[0])):
	comeandvisit(network[0][i])

print(sum(visited) - 1)
	