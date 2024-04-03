# 6566 애너그램 그룹

# 애너그램이란? - 단어의 배치를 바꿨을 때 될 수 있는 다른 단허들의 집합
#문자열이 되게많이 들어오는데, 이를 배치해서 같게 만든다 == 이를 정렬했을 때 일치한다
# 가 되기 때문에, 모든 문자열을 sort 하고, 각각의 애너그램 집합에 삽입할 수 있다면 좋다


import copy

arr = []
while True:
	tmp = input()
	if not tmp:
		break
	arr.append(list(tmp))

tmparr = copy.deepcopy(arr)

anagram = []
for i in range(len(arr)):
	arr[i].sort()
	anagram.append([i])

visited = [0] * len(arr)
for i in range(len(arr)):
	visited[i] = 1
	for j in range(i, len(arr)) :
		if arr[i] == arr[j] and visited[j] == 0:
			visited[j] = 1
			anagram[i].append(j)
anagram.sort(key = lambda x: -1 * len(x))


#print(tmparr)
r = []
for i in range(5):
	for j in range(len(anagram[i])):
		r.append(tmparr[anagram[i][j]])
	r.sort()
	for k in range(len(r))
		print(''.join(r[k]))
	r = []
#print(anagram)