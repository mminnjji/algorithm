room = []
mylist = []
n = input()

def custom_sort(item):
    second_criteria = int(item[1])
    first_criteria = int(item[0])
    return (second_criteria, first_criteria)



for i in range(int(n)):
	tmp = input().split()
	room.append(tmp)

room.sort(key=custom_sort)
end_t = int(room[0][1])
cnt = 1
for i in range(1, int(n)):
	if end_t <= int(room[i][0]) :
		cnt += 1
		end_t = int(room[i][1])

print(cnt)





