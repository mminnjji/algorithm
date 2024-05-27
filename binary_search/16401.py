# 16401 과자 나눠주기
# 최대한 긴 과자로 나눠주기 -> 여러조각으로 나눠질 수 있지만, 과자를 하나로 합칠 수는 없다
# 길이를 대상으로,, 1 ~ 가장 긴 과자의 길이를 start - end 라고 놓고 이분탐색하며 조카에게 줄 수 있는지 찾기
# 중간값 찾지 말고 -> 최댓값 찾아야 되니까 -> 찾는 즉즉 저장해두고 출력
import sys
input = sys.stdin.readline

def binary_search(target, data, start, end, n):
	tmp = 0
	while start <= end:
		sum = 0
		mid = (start + end) // 2
		for i in range(n):
			sum += data[i] // mid
		if sum < target:
			end = mid - 1
		else:
			tmp = mid
			start = mid + 1
	if tmp:
		return tmp
	return 0

m, n = map(int, input().split())

snack = list(map(int, input().split()))

start = 1
end = max(snack)
res = binary_search(m, snack, start, end, n)

print(res)

