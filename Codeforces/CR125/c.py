from sys import stdin, stdout

k, b, n, t = map(int, stdin.readline().split())

x = 1
for i in range(n):
    x = k*x + b

z = x
s = 0
x = t

for i in range(n):
    if x >= z:
        break
    x = k*x + b
    s += 1

stdout.write("%d\n" % s)
