# 13334번 - 철로

import sys
import heapq

# 입력값 받기
n = int(sys.stdin.readline().strip())
locations = [] # ([(시작 좌표, 끝 좌표) ...]
for _ in range(n):
    h, o = map(int, sys.stdin.readline().strip().split())
    # 집과 사무실 중 좌표값이 낮은 것을 앞에, 좌표값이 높은 것을 뒤에 넣어줌
    locations.append((min(h, o), max(h, o)))
d = int(sys.stdin.readline().strip())

# 선분의 끝점을 기준으로 오름차순 정렬한 다음, 앞점을 기준으로 오름차순 정렬
locations.sort(key=lambda x: (x[1], x[0]))

heap = []
max_cnt = 0

for location in locations: # 각 사람의 좌표를 기준으로 반복문 돌기
    start, end = location
    heapq.heappush(heap, start) # 최소 힙. pop했을 때 start가 작은 것부터 나올 수 있도록
    line_start = end - d # 현재 사람의 끝 좌표를 기준으로 철로의 시작 지점 계산
    while heap and heap[0] < line_start: # heap[0] = 힙에 저장된 시작 지점 중 최소값
        heapq.heappop(heap) # 철로의 시작 지점보다 시작 좌표가 작은 경우 철로를 벗어나므로 pop
    max_cnt = max(max_cnt, len(heap)) # 현재 철로에 포함되는 사람 수가 최대값인 경우 갱신

print(max_cnt)