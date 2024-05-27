## 1253 좋다
# 어떤 수를 다른 수 두개의 합으로 나타낼 수 있다면 -> 좋다
# N개의 수를 가지는 배열
# array[i] - array[j] 가 존재하는지 탐색
# new_array 를 생성하지 말고, 기존 array 의 인덱스를 제한하여 탐색

import sys
input = sys.stdin.readline

def binary_search(target, data, start, end, exc):

    while start <= end:
        mid = (start + end) // 2
        if data[mid] == target:
            if mid != exc:
                return mid
        elif data[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return None

n = int(input())

array = list(map(int, input().split()))
array.sort()
result = 0

# 0인경우의 예외처리 필요
for i in range(n):
	if i > 1:
		for j in range(i):
			target = array[i] - array[j]
			if binary_search(target, array,0, i - 1, j) is not None:
				result += 1
				break
	
print(result)
