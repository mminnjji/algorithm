import heapq

def min_classrooms(tasks):
    if not tasks:
        return 0

    # 시작 시간 기준 정렬
    tasks.sort(key=lambda x: x[0])

    min_heap = []

    # 첫 번째로 시작하는 강의의 종료시간 힙에 추가하며 시작
    heapq.heappush(min_heap, tasks[0][1])
		
		# 나머지에 태스크에 대해서 종료시간 비교
    for task in tasks[1:]:
        # 가장 빨리 끝나는 강의실이 현재 태스크의 시작 시간 이전일때 해당 강의실 재사용
        if min_heap[0] <= task[0]:
            heapq.heappop(min_heap)
        
        # 현재 태스크의 종료 시간 추가
        heapq.heappush(min_heap, task[1])

    # 힙에 추가된 강의실의 수 == 필요한 강의실의 수 반환
    return len(min_heap)

n = int(input())
tasks = []

for i in range(n):
		tasks.append(list(map(int, input().split())))

print(f"필요한 최소 강의실 수: {min_classrooms(tasks)}")