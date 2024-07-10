# 16398.py
# MST 제작
# kruskal 알고리즘 - 모든 간선 기준 작은 것 순서로 선택 ( 사이클 확인 ) + 트리 완성시 종료
import sys
input = sys.stdin.readline

# 가장 최상단의 부모찾기
def find_parent(parent, x):
	if parent[x] != x:
		parent[x] = find_parent(parent, parent[x])
	return parent[x] 

# 트리 합치기 - 작은 값이 부모가 되기 
def union(parent, a, b):
	a = find_parent(parent, a)
	b = find_parent(parent, b)
	if a < b:
		parent[b] = a
	else:
		parent[a] = b

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
# 부모를 자기 자신으로 초기화 
parent = [i for i in range(n)]

#Kruskal - 최소기준 간선 정렬 후 선택
edges = []
for i in range(1, n):
	for j in range(i):
		edges.append((arr[i][j], i, j))
edges.sort()

result = 0
# 간선선택 + 사이클 확인- 간선의 부모 확인
for cost, a, b in edges:
	if find_parent(parent, a) != find_parent(parent, b):
		union(parent, a, b)
		result += cost
print(result)
