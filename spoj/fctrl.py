from sys import stdin, stdout

limit = 1000000000
zeros = dict()
zeros[1, 9] = 0

for x, y in (xrange(10, limit, 10), xrange(19, limit, 10)):
    zeros[x, y] = zeros[x - 10, y - 10] + 1


def count_zeros(n):
    x = n - (n % 10)
    y = n + (10 - n % 10) - 1
    return zeros[x, y]

T = int(stdin.readline())

for i in xrange(T):
    n = int(stdin.readline())
    stdout.write("%d\n", count_zeros(n))
