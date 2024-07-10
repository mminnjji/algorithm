# 1717 집합의 표현

def find_parent(parent, x):
	#재귀호출
	if parent[x] != x:
		parent[x] = find_parent(parent, parent[x])
	return parent[x]

def union_parent(parent, a, b):
	a = find_parent(parent, a)
	b = find_parent(parent, b)
	if a < b:
		parent[b] = a
	else:
		parent[a] = b

n, m = map(int, input().split())
parent = [i for i in range(0, n + 1)]

for i in range(m):
	j, a, b = map(int, input().split())
	if j == 0:
		union_parent(parent, a, b)
	else: 
		if find_parent(parent, a) == find_parent(parent, b):
			print("YES")
		else:
			print("NO")

