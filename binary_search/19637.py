# 19637 IF 문 좀 대신 써줘
# 칭호의 개수와 칭호 출력 캐릭터 주어짐
# 칭호의 이름 + 전투력의 상한값 인풋
# 캐릭터의 전투력 -> 정수 배열

import sys
input = sys.stdin.readline

# 찾아야 하는 것 == val ~ val 사이에 존재하는지
# 값들의 array 에서 배열의 인덱스를 이분탐색하면서, 거기에 들어있는지 탐색할 수 있음
def binary_search(target, data):
	tmp = 0
	start = 0
	end = len(data)
	while start <= end:
		mid = (start + end) // 2
		if data[mid][1] >= target and ((mid > 0 and data[mid - 1][1] < target) or mid == 0):
			return data[mid][0]
		elif data[mid][1] < target:
			start = mid + 1
		else:
			end = mid - 1
	return None

n,m = map(int, input().split())

chuck = []
for i in range(n):
	name, val = input().split()
	chuck.append([name, int(val)])

character = []
for j in range(m):
	character.append(binary_search(int(input()), chuck))
	
for k in range(m):
	print(character[k])