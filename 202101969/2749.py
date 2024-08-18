# 피보나치 3

MOD = 1000000
n = int(input())
pisano_period = 15 * (MOD // 10)

n %= pisano_period
fib_prev, fib_curr = 0, 1

for _ in range(n - 1):
    fib_prev, fib_curr = fib_curr, (fib_prev + fib_curr) % MOD

print(fib_curr)
