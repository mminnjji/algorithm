#1092 배

# 크레인 n대 - 1분에 1개씩 실을 수 있음 - 무개제한이 있어 이보다 무거운 박스는 움직일 수 없음
# n대 크레인/ 크레인의 무게제한/ 박스의 수 M
# 무거운 순서대로 정렬하여 선택

import sys
input = sys.stdin.readline

N = int(input())
crain = list(map(int, input().split()))

M = int(input())
box = list(map(int, input().split()))

crain.sort(reverse=True)
box.sort(reverse=True)

# 들 수 없는 경우
if box[0] > crain[0]:
	print(-1)
# 들 수 있는 경우
else:
	count = 0
	while box:
		j = 0
		for i in range(N):
			while j < len(box):
				if crain[i] >= box[j]:
					del box[j]
					break
				j += 1
		count += 1
	print(count)
		