import sys
input = sys.stdin.readline

n = int(input())
k = int(input())

sensor = list(map(int,input().split()))
sensor.sort()

array = []
for i in range(0, n - 1):
	array.append(sensor[i+1] - sensor[i])
array.sort()

print(sum(array[:n - k]))