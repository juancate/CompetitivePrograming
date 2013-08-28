from sys import stdin
n,k = map(int, stdin.readline().split())
a, b, c, r = map(int, stdin.readline().split())

m = [0] * n
m[0] = a
for i in xrange(1,k):
  m[i] = (b * m[i-1] + c) % r
for i in xrange(k, n):
  for j in xrange(0, 1000000001):
    if j not in m[i-k:i]:
      m[i] = j
      break
print m
