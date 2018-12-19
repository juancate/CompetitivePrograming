from fractions import *
from sys import stdin

def lcm(a,b):
  return (a * b) / gcd(a, b)

lines = stdin.readlines()
t = int(lines[0])
pos = 1
for tc in xrange(t):
  v, b, n = map(int, ''.join(lines[pos].split('.')).split())
  pos += 1

  m, p, a = [0]*n, [0]*n, [0]*n
  total = 1
  for i in xrange(n):
    m[i], p[i], a[i] = map(int, ''.join(lines[pos].split('.')).split())
    a[i] = a[i] * 100
    total = lcm(total, m[i])
    pos += 1

  best = total * v * b
  ans = 0

  for i in xrange(n):
    period = total / m[i]
    curr = period * (m[i] * p[i] * b + a[i])
    if curr < best:
      ans = i+1
      best = curr

  print ans
