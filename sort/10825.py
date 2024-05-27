import sys
input = sys.stdin.readline

n = int(input())
student = []

for i in range(n):
	name, a, b, c = input().split()
	student.append([name, int(a), int(b), int(c)])

student.sort(key=lambda x: (-1 * x[1], x[2], -1 * x[3], x[0]))

for i in range(n):
	print(student[i][0])

