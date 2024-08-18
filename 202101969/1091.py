# 카드 섞기
import sys
from collections import defaultdict
def input():
    return sys.stdin.readline().rstrip()


n = int(input())
P = list(map(int, input().split()))
S = list(map(int, input().split()))

correct_positions = defaultdict(set)
visited_states = set()

for i in range(n):
    correct_positions[P[i]].add(i)

iterations = 0
current_cards = list(range(n))

while True:
    first, second, third = set(current_cards[0:n:3]), set(current_cards[1:n:3]), set(current_cards[2:n:3])

    if first == correct_positions[0] and second == correct_positions[1] and third == correct_positions[2]:
        break

    if tuple(current_cards) in visited_states:
        iterations = -1
        break

    visited_states.add(tuple(current_cards))

    next_cards = [0] * n
    for i in range(n):
        next_cards[S[i]] = current_cards[i]
    current_cards = next_cards
    iterations += 1

print(iterations)
