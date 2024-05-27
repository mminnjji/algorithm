# 2170 선긋기
# 선을 그을 때 선택한 두 점의 좌표들이 주어진다.
# 선은.. 겹칠 수 있고 -> 구분할 수 없다
# 선의 길이는?
# 선의 길이

n = int(input())

node = []

a, b = map(int, input().split())
node.append([a,b])
for i in range(n - 1):
	a, b = map(int, input().split())
	for j in range(len(node)):
		if a <= node[j][0] and b > node[j][0] and b <= node[j][1]:
			node[j][0] = a
		elif a <= node[j][0] and b >= node[j][1]:
			node[j][0] = a
			node[j][1] = b
		elif a >= node[j][0] and b <= node[j][1]:
			continue
		elif a >= node[j][0] and b >= node[j][1]:
			node[j][1] = b
		
		

print(node)
			