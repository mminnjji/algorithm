#1744 수묶기
#그리디로 한다면, 아무래도 그냥 다 해보면서 브루트포스를 돌 수도 있을 것
#50보다 작은 자연수 n이 등장하기 때문에 경우의 수가 그렇게까지 크지는 않을 
#더하거나 곱한다고 생각되기 때문에 -> 양수의 조합이라면 덧셈 > 곱셈이고 음수 /양수라면 덧셈 < 곱셈이고 음수/음수라면 곱셈 > 덧셈
#이라고 생각하면 좋다. 
#큰수끼리 묶어야 커지기 때문에 큰수끼리 묶는다고 가정하고, 나머지가 생기는 것으로 생각하자


n = int(input())

arr = []
for _ in range(n) :
	arr.append(int(input()))
arr.sort()
idx1 = len(arr) - 1
idx2 = 0
sum = 0
flag = [0] * len(arr)
while idx1 >= 1 and arr[idx1] > 1 and arr[idx1 -1] > 1 :
	sum += arr[idx1] * arr[idx1 - 1]
	flag[idx1] = flag[idx1 - 1] = 1
	idx1 -= 2

while idx2 <= len(arr) - 2 and arr[idx2] <= 0 and arr[idx2 + 1] <= 0 :
	sum += arr[idx2] * arr[idx2 + 1]
	flag[idx2] = flag[idx2 + 1] = 1
	idx2 += 2
	

for i in range(len(arr)) :
	if flag[i] == 0 :
		sum += arr[i]

print(sum)