import math

n = int(raw_input())

k = 1
ok = False
while (k * (k + 1) / 2) < n:
    r = k * (k + 1) / 2
    c = n - r
    c *= -2

    s = int((-1 + math.sqrt(1 - 4 * c)) / 2)
    t = s * (s + 1) / 2

    if t + r == n :
        ok = True
        break

    k += 1

if ok:
    print "YES"
else:
    print "NO"
