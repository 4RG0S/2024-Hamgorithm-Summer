# 피보나치 6

MOD = 1000000007
memo = {}


def fibonacci(n):
    if n in memo:
        return memo[n]
    if n == 0:
        return 0
    if n == 1 or n == 2:
        return 1

    if n % 2 == 0:
        fib_half_plus_one = fibonacci(n // 2 + 1) % MOD
        fib_half_minus_one = fibonacci(n // 2 - 1) % MOD
        memo[n // 2 + 1] = fib_half_plus_one
        memo[n // 2 - 1] = fib_half_minus_one
        memo[n] = (fib_half_plus_one ** 2 - fib_half_minus_one ** 2) % MOD
    else:
        fib_half_plus_one = fibonacci(n // 2 + 1) % MOD
        fib_half = fibonacci(n // 2) % MOD
        memo[n // 2 + 1] = fib_half_plus_one
        memo[n // 2] = fib_half
        memo[n] = (fib_half_plus_one ** 2 + fib_half ** 2) % MOD

    return memo[n]


n = int(input())
print(fibonacci(n))
